#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include "BasicDisplayVisitor.h"
class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(AbstractFileSystem*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;
};