#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class ChmodCommand : public AbstractCommand {
public:
	ChmodCommand(AbstractFileSystem*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;
};