#pragma once
#include "AbstractParsingStrategy.h"
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <string>
#include <vector>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	RenameParsingStrategy();
	std::vector<std::string> parse (std::string);
};