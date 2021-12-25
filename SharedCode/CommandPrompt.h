#pragma once
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include <map>
class CommandPrompt {
public:
	CommandPrompt();
	~CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();
protected:
	void listCommands();
	std::string prompt();
private:
	AbstractFileSystem* system;
	AbstractFileFactory* factory;
	std::map<std::string, AbstractCommand*> commandMap;
};


