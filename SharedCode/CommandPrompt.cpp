#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include <iterator>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
CommandPrompt::CommandPrompt() {
	system = nullptr;
	factory = nullptr;
}
CommandPrompt::~CommandPrompt() {
	delete system;
	delete factory;
}
void CommandPrompt::setFileSystem(AbstractFileSystem* pointer) {
	system = pointer;
}
void CommandPrompt::setFileFactory(AbstractFileFactory* pointer) {
	factory = pointer;
}

int CommandPrompt::addCommand(string name, AbstractCommand* pointer) {
	int size = commandMap.size();
	commandMap.insert(pair<string, AbstractCommand*>(name, pointer));
	int newSize = commandMap.size();
	if (newSize = size + 1) {
		return 0;
	}
	else {
		return 1;
	}

}
void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	for (it = commandMap.begin(); it != commandMap.end(); it++) {
		cout << it->first << " ";
		cout << "\n";
	}
}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command" << endl;
	cout << "$ ";
	string input;
	getline(cin, input);
	return input;
}
int CommandPrompt::run() {
	while (1) {
		string result = prompt();
		if (result == "q") {
			return 1;
		}
		
		if (result == "help") {
			listCommands();
		}
		else {
			if (result.find(" ") == string::npos) {
				if (commandMap.find(result) != commandMap.end()) {
					
					if (commandMap.find(result)->second->execute("") == 0) {
						//command executes
					}
					else {
						cout << "Error in the command. Try again" << endl;
					}
				}
				else {
					cout << "The command does not exist" << endl;
				}
			}
			else {
				istringstream iss(result);
				string isHelp;
				iss >> isHelp;
				if (isHelp == "help") {
					string command;
					iss >> command;
					if (commandMap.find(command) != commandMap.end()) {
						commandMap.find(command)->second->displayInfo();
					}
					else {
						cout << "The command does not exist" << endl;
					}

				}
				else {
					//commands with 3 total args get picked up here
					int pos = result.find(" ");
					string commandname = result.substr(0,pos);
					string command= result.substr(pos + 1, string::npos);
					
					if (commandMap.find(commandname) != commandMap.end()) {
						int res=commandMap.find(commandname)->second->execute(command);
						if (res != 0) {
							cout << "Command failed" << endl;
						}
					}
					else {
						cout << "The command does not exist" << endl;
					}
				}
			}
			
		}

	}
}
