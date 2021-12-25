#include "MacroCommand.h"
#include "SimpleFileSystem.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* setSystem):strat() {
	system = setSystem;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
	commandList.push_back(cmd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
	strat = strategy;
}

void MacroCommand::displayInfo() {
	cout << "Macro helps execute multiple commands, by storing each command sequentially into a vector" << endl;
}
int MacroCommand::execute(string command) {
   vector<string> vec=strat->parse(command);
   for(int i=0; i<vec.size();i++){
	   int a=commandList[i]->execute(vec[i]);
	   if(a!=0){
		   return a;
	   }
   }
   return 0;
}