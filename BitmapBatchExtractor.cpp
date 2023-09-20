#include "BitmapBatchExtractor.h"

// from https://dev.gnupg.org/T4539
#ifdef _WIN64
#define strerror_r(errnum, buf, buflen) strerror_s(buf, buflen, errnum)
#endif
#include <png++/png.hpp>
#include <thread>

#include <sstream>
#include <iomanip>

BitmapBatchExtractor::BitmapBatchExtractor(ModuleManager* modman, Logger* logger){
	this->modman = modman;
	this->logger = logger;
}

void BitmapBatchExtractor::extract(std::string path, std::vector<uint32_t> bitmaps, int mipmap, int threadcount){

	if(threadcount == 0){
		threadcount = std::thread::hardware_concurrency();
	}

	if(threadcount == 0){
		logger->log(LOG_LEVEL_WARNING, "std::thread::hardware_concurrency() reports 0, using 4 threads as fallback!\n");
		threadcount = 4;
	} else {
		logger->log(LOG_LEVEL_INFO, "Exporting textures with %d threads\n", threadcount);
	}

	logger->log(LOG_LEVEL_INFO, "Exporting %d textures to %s\n", bitmaps.size(), path.c_str());
	bitmapWorkerControl* workerControls = new bitmapWorkerControl[threadcount];
	std::vector<std::thread> workerThreads;
	workerThreads.resize(threadcount);
	// start the worker threads
	for(int i = 0; i < threadcount; i++){
		workerControls[i].status = bitmapWorkerControl::WORKER_IDLE;
		workerControls[i].kill = false;
		workerControls[i].mipmap = mipmap;
		workerThreads[i] = std::thread(bitmapWorkerLoop, modman, &workerControls[i], nullptr);
	}

	int threadcounter = 0;

	for(auto globalId : bitmaps){
		if(!modman->assetIdItems.contains(globalId)){
			logger->log(LOG_LEVEL_ERROR, "Bitmap 0x%08x cannot be found in the loaded modules!\n", globalId);
			continue;
		}
		if(globalId == 0xffffffff){
			continue;
		}
		bool nextBtm = false;
		while(!nextBtm){
			for(; threadcounter < threadcount; threadcounter++){
				if(workerControls[threadcounter].status == bitmapWorkerControl::WORKER_IDLE){
					// give the work to this one
					workerControls[threadcounter].globalId = globalId;
					std::stringstream stream;
					stream << path << "/" << std::hex << std::setw(8) << std::setfill('0') << globalId;	// only png for now
					workerControls[threadcounter].path = stream.str();

					workerControls[threadcounter].status = bitmapWorkerControl::WORKER_NEW_WORK;	// all parameters have been set
					nextBtm = true;
					break;	// continue on the next global ID
				}
			}
			if(threadcounter == threadcount){
				threadcounter = 0;	// start over again with the first thread
			}
		}
	}

	// set all the worker threads to terminate once they're done
	for(int i = 0; i < threadcount; i++){
		workerControls[i].kill = true;	// stop the thread once it's idle again
	}
	// these two loops could be combined, but this way the threads might stop a bit faster
	for(int i = 0; i < threadcount; i++){
		workerThreads[i].join();
	}
}

void BitmapBatchExtractor::bitmapWorkerLoop(ModuleManager* modman, bitmapWorkerControl* control, Logger* logger){
	control->isRunning = true;

	while(!control->kill){
		// main loop of the thread
		if(control->status == bitmapWorkerControl::WORKER_IDLE){
			std::this_thread::yield();
		}
		if(control->status == bitmapWorkerControl::WORKER_NEW_WORK){
			control->status = bitmapWorkerControl::WORKER_WORKING;	// both states mean no modification of control data from other threads, but just to be sure

			if(!modman->assetIdItems.contains(control->globalId)){

				control->status = bitmapWorkerControl::WORKER_IDLE;	// ready for new work, control values can now be modified
				printf("Global ID not available\n");
				continue;
			}

			// the logger might be problematic, as I don't think that's really thread safe (at least not the GUI version)
			BitmapHandle bitmapHandle(modman->assetIdItems[control->globalId],logger);


			if(bitmapHandle.frameCount == 0 || bitmapHandle.frames[0].mipmapCount == 0){
				continue;
			}

			int idx = 0;
			for(;idx < bitmapHandle.frameCount; idx++){
				int lvl = 0;
				lvl = std::min((uint32_t)control->mipmap, bitmapHandle.frames[0].mipmapCount-1);
				void* data = bitmapHandle.frames[idx].getR8G8B8A8Data(lvl);
				if(data == nullptr){
					continue;
				}

				// export that image data as PNG
				png::image<png::rgba_pixel> pngimg(bitmapHandle.frames[idx].mipMaps[lvl].width, bitmapHandle.frames[idx].mipMaps[lvl].height);
				png::image<png::rgba_pixel>::pixbuf pixbuf(bitmapHandle.frames[idx].mipMaps[lvl].width, bitmapHandle.frames[idx].mipMaps[lvl].height);

				// copy the pixel data
				for(size_t y = 0; y < bitmapHandle.frames[idx].mipMaps[lvl].height; y++){
					for(size_t x = 0; x < bitmapHandle.frames[idx].mipMaps[lvl].width; x++){
						size_t offset = ((y * bitmapHandle.frames[idx].mipMaps[lvl].width) + x) * 4;
						pngimg.set_pixel(x, y, png::rgba_pixel(((char*)data)[offset], ((char*)data)[offset+1], ((char*)data)[offset+2], ((char*)data)[offset+3]));
					}
				}

				pngimg.write((idx == 0 ? control->path : control->path + "_" + std::to_string(idx)) + ".png");

				/*if(!stbi_write_png(control->path.c_str(), bitmapHandle.frames[idx].mipMaps[lvl].width, bitmapHandle.frames[idx].mipMaps[lvl].height,
						4, data, bitmapHandle.frames[idx].mipMaps[lvl].width * 4)){
					// write failed
					printf("png export failed\n");
				}*/
				free(data);	// no memory leaks with image data please
			}

			// done
			control->status = bitmapWorkerControl::WORKER_IDLE;	// ready for new work, control values can now be modified
		}
	}

	control->isRunning = false;
}
