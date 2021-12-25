#pragma once
#include "AbstractCommand.h"
#include	"AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;
	

};