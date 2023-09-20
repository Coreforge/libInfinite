#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "module/ModuleManager.h"
#include "logger/logger.h"
#include "BitmapHandle.h"

class BitmapBatchExtractor{
public:
	void extract(std::string path, std::vector<uint32_t> bitmaps, int mipmap = 0, int threadcount = 0);	// 0 means automatic
	BitmapBatchExtractor(ModuleManager* modman, Logger* logger);

private:
	struct bitmapWorkerControl{
		// I don't think anything in here really needs locks or atomicity
		// however, coherency between threads is assumed (which should be the case on x86 I think, and other architectures aren't really targeted currently)
		uint32_t globalId;	// ID to export
		std::string path;	// path to export to
		int mipmap;			// mipmap to export (if only lower ones exist, take the lowest one)
		enum workerStatus{
			WORKER_IDLE,
			WORKER_NEW_WORK,
			WORKER_WORKING
		} status;
		bool kill;
		bool isRunning;
	};

	static void bitmapWorkerLoop(ModuleManager* modman, bitmapWorkerControl* control, Logger* logger);
	ModuleManager* modman;
	Logger* logger;
};
