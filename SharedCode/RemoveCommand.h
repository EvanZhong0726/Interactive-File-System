#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;

};