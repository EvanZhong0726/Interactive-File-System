#pragma once
#include <string>
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"
#include <set>
#include <map>
class AbstractFileSystem {
public:
	virtual int addFile(std::string, AbstractFile*)=0;
	//virtual int createFile(std::string) = 0;
	virtual int deleteFile(std::string) = 0;
	virtual AbstractFile* openFile(std::string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
	virtual std::set<std::string> getFileNames() = 0;
	virtual std::map<std::string, AbstractFile*> getFileMap() = 0;
};