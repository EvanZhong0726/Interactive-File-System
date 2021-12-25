#pragma once
#include "AbstractCommand.h"
#include"AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class TouchCommand : public AbstractCommand {
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	void displayInfo() override;
	int execute(std::string) override;
private:
	AbstractFileSystem* system;
	AbstractFileFactory* factory;

};