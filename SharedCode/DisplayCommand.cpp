#include "DisplayCommand.h"
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* p1) {
	system = p1;
}
void DisplayCommand::displayInfo() {
	cout << "ds displays the content of the file. adding the flag -d displays the file unformatted" << endl;
}
int DisplayCommand::execute(string command) {
	if (command.find('-') != string::npos) {
		int pos = command.find('-');
		if (command[pos + 1] == 'd') {
			string fileName = command.substr(0, pos - 1);
			BasicDisplayVisitor* visitor = new BasicDisplayVisitor();
			int pos1 = fileName.find(".");
			string extension = fileName.substr(pos1 + 1, string::npos);
			map<string, AbstractFile*>fileMap = system->getFileMap();
			if (fileMap.find(fileName) != fileMap.end()) {
				AbstractFile* actualFile = fileMap.find(fileName)->second;
				if (extension == "txt") {
					actualFile->accept(visitor);
				}
				if (extension == "img") {
					vector<char> copied = actualFile->read();
					copied.pop_back();
					for (int i = 0; i < copied.size(); i++) {
						cout << copied[i];
					}
					cout << " ";
					cout << '\n';
				}

			}
			return 0;
		}
		else {
			return 1;
		}
	}
    else{
        BasicDisplayVisitor* visitor = new BasicDisplayVisitor();
        map<string,AbstractFile*>fileMap=system->getFileMap();
		if (fileMap.find(command) != fileMap.end()){
		AbstractFile* actualFile = fileMap.find(command)->second;
		actualFile->accept(visitor);
		return 0; 
        }
		else {
			return 1;
		}
    }
	     

}
