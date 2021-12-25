#include"TouchCommand.h"
#include<iostream>
#include "PasswordProxy.h"
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* p1, AbstractFileFactory* p2) {
	system = p1;
	factory = p2;
}
void TouchCommand::displayInfo() {
	cout << "Touch creates the file, touch can be invoked with the command: touch <filename>" << endl;
	cout << "To password protect add the flag -p after <filename>" << endl;
}
int TouchCommand::execute(string name) {

	if (name.find('-') != string::npos) {

		int pos = (int)name.find("-");

		if (name.substr(0, pos) != "") {
			if (name[(pos + 1)] == 'p') {
				//if -p
				string fileName = name.substr(0, pos - 1);
				map<string, AbstractFile*> fileMap = system->getFileMap();
				if (fileMap.find(fileName) == fileMap.end()) {
					//if filename doesn't exist
					AbstractFile* pointer = factory->createFile(fileName);
					if (pointer == nullptr) {
						cout << "Failed creating file! Did you include extension name?" << endl;
						return 1;
					}
					cout << "Enter a password:" << endl;
					string password;
					cin >> password;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					PasswordProxy* proxy = new PasswordProxy(pointer, password);
					system->addFile(fileName, proxy);
					return 0;
				}
				else {
					cout << "Please use a different name, already exists the file with the same name" << endl;
					return 1;
				}
			}
			else {
				cout << "Wrong command" << endl;
				return 1;
			}
		}
		else {
			cout << "put -p after filename!" << endl;
			return 1;
		}

			
	}
	else {
		AbstractFile* pointer = factory->createFile(name);
		map<string, AbstractFile*> fileMap = system->getFileMap();
		if (fileMap.find(name) == fileMap.end()) {
			if (pointer != nullptr) {
				AbstractFileSystem* p = system;

				int res = system->addFile(name, pointer);
				if (res != 0) {
					cout << "Failed to add file" << endl;
					return 1;
				}
				return 0;
			}
			else {
				cout << "Failed to create file" << endl;
				return 1;
			}
		}
		else {
			cout << "Please use a different name, already exists the file with the same name" << endl;
			return 1;
		}
	}
}