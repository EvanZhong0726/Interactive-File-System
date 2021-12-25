#include "CatCommand.h"
#include "BasicDisplayVisitor.h"
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* p1) {
	system = p1;
}
void CatCommand::displayInfo() {
	cout << "cat concatenates information onto a file, cat can be invoked with the command: cat <filename> [-a]  . -a is optional for append" << endl;
}
int CatCommand::execute(string command) {
	if (command.find("-") != string::npos) {
		int pos = command.find("-");
		if (command[pos+1] == 'a') {
			string fileName = command.substr(0, pos-1);
			int pos1 = fileName.find(".");
			string extension = fileName.substr(pos1 + 1, string::npos);
			map<string, AbstractFile*> fileMap = system->getFileMap();
			if (fileMap.find(fileName) != fileMap.end()) {
				cout << fileName << endl;
				AbstractFile* actualFile = fileMap.find(fileName)->second;
				BasicDisplayVisitor* visitor = new BasicDisplayVisitor();
				actualFile->accept(visitor);
				cout << "\n";
				cout << "Enter data you would like to append to the existing file. Enter :wq to save and quit. Enter :q to quit without saving." << endl;
				vector<string> inputstore;
				string input;
				//while not wq or q
				//when its q discard changes, when its wq save
				if (extension == "txt") {
					while (input != ":wq" && input != ":q") {
						getline(cin, input);
						inputstore.push_back(input);
					}
					if (input == ":wq") {
						vector<char> vec;
						for (int i = 0; i < inputstore.size() - 1; i++) {
							for (int j = 0; j < inputstore[i].size(); j++) {
								vec.push_back(inputstore[i][j]);
							}
							if (i != inputstore.size() - 2) {
								vec.push_back('\n');
							}
						}
						actualFile->append(vec);
					}
				}
				if (extension == "img") {
					return 1;
				}
			}
			else {
				return 1;
			}

		}
        return 0;
	}
	else {
		string fileName = command;
		int pos = (int)fileName.find(".");
		string extension = fileName.substr(pos+1, string::npos);
		map<string, AbstractFile*> fileMap = system->getFileMap();
		if (fileMap.find(fileName) != fileMap.end()) {
			cout << fileName << endl;
			cout << "Enter data you would like to write to the file. Enter :wq to save and quit. Enter :q to quit without saving." << endl;
			AbstractFile* actualFile = fileMap.find(fileName)->second;

			string input;
			//while not wq or q
			//when its q discard changes, when its wq save
			vector<string> inputstore;
			while (input != ":wq" && input != ":q") {
				getline(cin, input);
				inputstore.push_back(input);
			}
			if (extension == "txt") {
				if (input == ":wq") {
					vector<char> vec;
					for (int i = 0; i < inputstore.size() - 1; i++) {
						for (int j = 0; j < inputstore[i].size(); j++) {
							vec.push_back(inputstore[i][j]);
						}
						if (i != inputstore.size() - 2) {
							vec.push_back('\n');
						}
					}
					actualFile->write(vec);
				}
			}
			if (extension == "img") {
				if (input == ":wq") {
					vector<char> vec;
					for (int i = 0; i < inputstore.size() - 1; i++) {
						for (int j = 0; j < inputstore[i].size(); j++) {
							vec.push_back(inputstore[i][j]);
						}
					}
					actualFile->write(vec);
				}
			}
			return 0;
		}
	}
}