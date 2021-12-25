#pragma once
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

// TextFile declaration goes here
class TextFile : public AbstractFile {
public:
	TextFile(std::string);
	TextFile(const TextFile&);
	AbstractFile* clone(std::string);
	unsigned int getSize();
	std::string getName();
	int write(std::vector<char>);
	int append(std::vector<char>);
	std::vector<char> read();
	void accept(AbstractFileVisitor* visitor);
	void setAccess();
private:
	std::vector<char> contents;
	std::string name;
};