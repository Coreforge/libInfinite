#include <module/ModuleManager.h>


// excludes files from the file list if their data isn't actually present in the modules
#define IGNORE_BROKEN_FILES 1

ModuleManager::ModuleManager(Logger* logger){
	rootNode = new ModuleNode();
	rootNode->path = "";
	rootNode->name = "/";
	rootNode->parent = rootNode;	// the roots parent is the root
	rootNode->type = NODE_TYPE_DIRECTORY;
	this->logger = logger;
}

void ModuleManager::buildNodeTree(){
	// exclusive lock, because we're modifying the tree
	mutex.lock();
	rootNode = new ModuleNode();
	rootNode->path = "";
	rootNode->name = "/";
	rootNode->parent = rootNode;	// the roots parent is the root
	rootNode->type = NODE_TYPE_DIRECTORY;
	for(int m = 0; m < modules.size(); m++){
		// each module
		//printf("Module %d\n",m);
		for(auto const&[key,value] : modules[m]->items){
			//printf("Item!\n");
			// each file
			if(value->dataOffset > modules[m]->data_size && IGNORE_BROKEN_FILES){
				// the actual data for this file is missing, so it's not getting added to the tree, as there is no point in doing so
				continue;
			}
			std::stringstream stream(key);
			std::string part;
			ModuleNode* currentParent = rootNode;
			int lastCount = 0;
			while(std::getline(stream,part,'/')){
				// path broken down into the individual segments
				lastCount = currentParent->children.count(part);
				if(currentParent->children.count(part) == 0){
					// this segment doesn't exist yet, create it
					//printf("adding node %s\n",part.c_str());
					ModuleNode* newNode = new ModuleNode();
					newNode->parent = currentParent;
					newNode->name = part;
					newNode->path = currentParent->path + "/" + part;
					newNode->type = NODE_TYPE_DIRECTORY;
					currentParent->children.insert({part,newNode});
				}
				// continue with the node of the current segment
				currentParent =  currentParent->children[part];
				//printf("Part: %s\n",part.c_str());
			}
			// currentParent is now the one for the lest segment (file name)
			if(lastCount != 0){
				if(value->tagType != -1){
					logger->log(LOG_LEVEL_WARNING,"Duplicate Path: %s tag class %c%c%c%c\n",key.c_str(), *(((uint8_t*)&value->tagType) + 3 ),*(((uint8_t*)&value->tagType) + 2 ),*(((uint8_t*)&value->tagType) + 1 ), *(((uint8_t*)&value->tagType) + 0 ) );
				} else {
					logger->log(LOG_LEVEL_WARNING,"Duplicate Path: %s tag class (not a tag file)\n",key.c_str());
				}
			}
			currentParent->type = NODE_TYPE_FILE;
			currentParent->item = value;
			currentParent->item->path = currentParent->path;
			currentParent->item->name = currentParent->name;

			// GlobalId stuff
			//assetIdItems.insert({currentParent->item->assetID,currentParent->item});
			assetIdItems[currentParent->item->assetID] = currentParent->item;
		}
	}
	mutex.unlock();
}

void ModuleManager::deleteNodeTree(){
	mutex.lock();
	deleteTreeRecursive(rootNode);
	mutex.unlock();
}

void ModuleManager::deleteTreeRecursive(ModuleNode* node){
	if(node->type == NODE_TYPE_FILE){
		// just a file node which has no children, just delete it (this check probably isn't necessary)
		delete node;
		return;
	}
	std::map<std::string,ModuleNode*>::iterator it;
	for(it = node->children.begin();it != node->children.end();it++){
		deleteTreeRecursive(it->second);
		it = node->children.erase(it);
	}
	// all children should be gone, delete this node
	delete node;
}

// first is uncompressed, second is compressed
std::pair<uint64_t,uint64_t> ModuleManager::getSizes(ModuleNode* node){
	uint64_t compressed = 0;
	uint64_t uncompressed = 0;
	if(node->type == NODE_TYPE_DIRECTORY){
		for(auto const&[key,cNode] : node->children){
			auto res = getSizes(cNode);
			compressed += res.second;
			uncompressed += res.first;
		}
	} else {
		if(node->item){
			compressed = node->item->compressedSize;
			uncompressed = node->item->decompressedSize;
		}
	}
	return {uncompressed, compressed};
}

ModuleNode* ModuleManager::getNode(std::string path){
	std::stringstream stream(path);
	std::string part;
	ModuleNode* currentParent = rootNode;
	while(std::getline(stream,part,'/')){
		if(part == ""){
			// empty part. Could be two slashes, could be the root node as "/"
			continue;
		}
		if(currentParent->children.count(part) == 0){
			// doesn't exist
			return nullptr;
		}
		currentParent = currentParent->children[part];
	}
	return currentParent;
}

int ModuleManager::addModule(Module* module){
	//module->logger = logger;
	modules.emplace_back(module);
	return 0;
}

int ModuleManager::addModule(const char* path){
	Module* module = new Module();
	module->logger = logger;
	int r = module->loadModule(path);
	if(r){
		return r;
	}
	return addModule(module);
}
