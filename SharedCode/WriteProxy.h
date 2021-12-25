#pragma once
#include "AbstractFile.h"
class WriteProxy : public AbstractFile {
public:
	WriteProxy(AbstractFile*, char);
	~WriteProxy();
	AbstractFile* clone(std::string);
	std::vector<char> read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* visitor);
	void setAccess();
private:
	AbstractFile* pointer;
	bool writeAccess;
};
