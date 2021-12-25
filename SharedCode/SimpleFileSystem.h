#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>
#include <string>
class SimpleFileSystem :public AbstractFileSystem {
public:
	friend class LSCommand;
	int addFile(std::string, AbstractFile*);
	//int createFile(std::string);
	int deleteFile(std::string);
	AbstractFile* openFile(std::string);
	int closeFile(AbstractFile*);
	std::set<std::string> getFileNames();
	std::map<std::string, AbstractFile*> getFileMap();
private:
	std::map<std::string,AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
};