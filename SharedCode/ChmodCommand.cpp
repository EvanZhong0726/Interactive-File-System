#include "ChmodCommand.h"
#include "WriteProxy.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
ChmodCommand::ChmodCommand(AbstractFileSystem* p1) {
	system = p1;
}
void ChmodCommand::displayInfo() {
	cout << "chmod changes if a file can be written. - for read only, + to convert it back" << endl;
}
int ChmodCommand::execute(string command) {
	if (command.find(" ") != string::npos) {
		int pos = command.find(" ");
		string fileName = command.substr(0, pos);
		map<string, AbstractFile*> fileMap = system->getFileMap();
		if (fileMap.find(fileName) != fileMap.end()) {
			AbstractFile* pointer = fileMap.find(fileName)->second;
			if (command[pos + 1] == '-') {
				WriteProxy* proxy = new WriteProxy(pointer, '-');
				system->deleteFile(fileName);
				system->addFile(fileName, proxy);
				return 0;
			}
			else {
				if (command[pos + 1] == '+') {
					pointer->setAccess();
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		else {
			cout << "Cannot find the file" << endl;
			return 1;
		}
	}
	else {
		return 1;
	}
}