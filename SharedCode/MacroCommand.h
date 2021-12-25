#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include "AbstractParsingStrategy.h"
class MacroCommand : public AbstractCommand {
public:
	MacroCommand(AbstractFileSystem*);
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
    void displayInfo() override;
    int execute(std::string) override;
private:
	AbstractFileSystem* system;
	std::vector<AbstractCommand*> commandList;
	AbstractParsingStrategy* strat;
};
