#pragma once
#include "AbstractFile.h"
// studio 18 - file factory interface declared here
class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string) = 0;
};
