// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/ChmodCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/TouchEditDisplayParsingStrategy.h"
#include <vector>
#include <string>
using namespace std;


int main()
{
	//initial setup
	AbstractFileSystem* system = new SimpleFileSystem();
	AbstractFileFactory* factory = new SimpleFileFactory();
	CommandPrompt* prompt = new CommandPrompt();
	prompt->setFileFactory(factory);
	prompt->setFileSystem(system);

	//create commands
	CopyCommand* copy=new CopyCommand(system);
	RemoveCommand* remove=new RemoveCommand(system);
	TouchCommand* touch = new TouchCommand(system, factory);
	CatCommand* cat = new CatCommand(system);
	DisplayCommand* display = new DisplayCommand(system);
	LSCommand* list = new LSCommand(system);

	//rename command setup
	RenameParsingStrategy* renameStrategy=new RenameParsingStrategy();
	MacroCommand* rn = new MacroCommand(system);
	rn->addCommand(copy);
	rn->addCommand(remove);
	rn->setParseStrategy(renameStrategy);
	

	//ted command setup
	TouchEditDisplayParsingStrategy* teStrat = new TouchEditDisplayParsingStrategy();
	MacroCommand* ted = new MacroCommand(system);
	ted->addCommand(touch);
	ted->addCommand(cat);
	ted->addCommand(display);
	ted->setParseStrategy(teStrat);

	//extracredit chmod command setup;
	ChmodCommand* chmod = new ChmodCommand(system);

	//add commands to commandLine
	prompt->addCommand("rn", rn);
	prompt->addCommand("ted", ted);
	prompt->addCommand("touch", touch);
	prompt->addCommand("cat", cat);
	prompt->addCommand("ds", display);
	prompt->addCommand("rm", remove);
	prompt->addCommand("ls", list);
	prompt->addCommand("cp", copy);
	prompt->addCommand("chmod", chmod);
	//run the program
	return prompt->run();
}

