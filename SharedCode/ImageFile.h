#pragma once
#include "AbstractFile.h"
#include<string>
#include <vector>
// Image file class declaration here
class ImageFile : public AbstractFile {
public:
	ImageFile(std::string);
	ImageFile(const ImageFile&);
	AbstractFile* clone(std::string);
	unsigned int getSize();
	std::string getName();
	int write(std::vector<char>);
	int append(std::vector<char>);
	std::vector<char> read();
	void accept(AbstractFileVisitor* file);
	int indexfunc(int, int);
	int retSize();
	void setAccess();
private:
	std::string filename;
	std::vector<char> contents;
	char size;
};