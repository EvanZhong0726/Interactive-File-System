// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int SimpleFileSystem::addFile(string name, AbstractFile* p){
	if (files.find(name) != files.end()) {
		//file already exists
		return 1;
	}
	else {
		if (p == 0) {
			return 1;
		}
		else {
			pair<string, AbstractFile*> newFile = make_pair(name, p);
			files.insert(newFile);
			return 0;


		}
	}
}

AbstractFile* SimpleFileSystem::openFile(string name) {
	if (files.find(name) != files.end()) {
		AbstractFile* theFile = files.find(name)->second;
		if (openFiles.find(theFile) == openFiles.end()) {
			openFiles.insert(theFile);
			return theFile;
		}
	}
	return nullptr;
}
int SimpleFileSystem::closeFile(AbstractFile* p) {
	if (openFiles.find(p) != openFiles.end()) {
		openFiles.erase(p);
		return 0;
	}
	return 1;
}
set<string> SimpleFileSystem::getFileNames()
{
	set<string> fileNames;
	map<string,AbstractFile*>::iterator it;
	for (it = files.begin(); it != files.end(); it++) {
		fileNames.insert(it->first);
	}
	
	return fileNames;
}

map<string, AbstractFile*> SimpleFileSystem::getFileMap() {
	return files;
}


int SimpleFileSystem::deleteFile(string name) {
	if (files.find(name) != files.end()) {
		AbstractFile* theFile = files.find(name)->second;
		if (openFiles.find(theFile) != openFiles.end()) {
			return 2;
		}
		else {
			files.erase(name);
			theFile = nullptr;
			return 0;
		}
	}
	//file not found
	return 1;
}