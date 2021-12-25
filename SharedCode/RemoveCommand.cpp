#include "RemoveCommand.h"
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* p1) {
	system = p1;
}
void RemoveCommand::displayInfo() {
	cout << "rm remove the file stated from the system, rm can be invoked by typing rm <filename>" << endl;
}
int RemoveCommand::execute(string command){
    return system->deleteFile(command);
}

