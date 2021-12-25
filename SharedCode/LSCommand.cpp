#include "LSCommand.h"
#include<iostream>
#include "MetadataDisplayVisitor.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* p1) {
	system = p1;
}
void LSCommand::displayInfo() {
	cout << "ls lists all the files in the system, ls can be invoked by typing ls  , or ls -m for file details" << endl;
}

int LSCommand::execute(string name) {
	if (name == "") {
		set<string>::iterator file;
		int track = 0;
		int width = 0;
		set<string> fileSet = system->getFileNames();
		for (file = fileSet.begin(); file != fileSet.end(); file++) {
			if (width < (*file).size()) {
				width = (*file).size();
			}

		}
		for (file = fileSet.begin(); file != fileSet.end(); file++) {
			cout.width(width+1);
			cout << *file;
			if (track % 2 == 1) {
				cout << "" << endl;
			}
			track++;
		}
		cout << "" << endl;
		return 0;//ask
	 }
	if (name == "-m") {
		map<string,AbstractFile*>::iterator file;
		set<string> fileSet = system->getFileNames();
		map<string, AbstractFile*> fileMap = system->getFileMap();
		for(file=fileMap.begin();file!=fileMap.end();file++){
			AbstractFile* actualFile=file->second;
			string actualFileName=file->first;
			MetadataDisplayVisitor *visitor=new MetadataDisplayVisitor();
			actualFile->accept(visitor);
		}
		cout << "" << endl;
		return 0; //question
	}
}