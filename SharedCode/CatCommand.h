#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;
};