#pragma once
#include "AbstractParsingStrategy.h"

class TouchEditDisplayParsingStrategy :public AbstractParsingStrategy {
public:
	TouchEditDisplayParsingStrategy();
	std::vector<std::string> parse(std::string);
};