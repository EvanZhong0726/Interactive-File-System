#pragma once
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFileVisitor;
class AbstractFile {
public:
	virtual AbstractFile* clone(std::string) = 0;
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual void accept(AbstractFileVisitor* visitor) = 0;
	virtual ~AbstractFile() = default;
	virtual void setAccess() = 0;
	
};

