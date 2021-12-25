#pragma once
#include "AbstractFile.h"
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, std::string);
	AbstractFile* clone(std::string);
	~PasswordProxy();
	std::vector<char> read();
	int write(std::vector<char>);
	int append(std::vector<char>);
	unsigned int getSize();
	std::string getName();
	void accept(AbstractFileVisitor* visitor);
	void setAccess();
protected:
	std::string passwordPrompt();
	bool passwordValid(std::string);
private:
	AbstractFile* pointer;
	std::string password;
};