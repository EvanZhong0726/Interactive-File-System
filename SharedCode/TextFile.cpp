//  Define the TextFile class here
#include "TextFile.h"
#include <vector>
using namespace std;
TextFile::TextFile(std::string name) {
	this->name = name;
}
TextFile::TextFile(const TextFile& txt):name(""){
	name=txt.name;
	for(int i=0; i<txt.contents.size();i++){
      contents.push_back(txt.contents[i]);
	}
}

AbstractFile* TextFile::clone(string name) {
	TextFile* txtClone=new TextFile(*this);
	txtClone->name=name+".txt";
	return txtClone;

}
unsigned int TextFile::getSize() {
	return (unsigned int)this->contents.size();
}
std::string TextFile::getName() {
	return name;
}
int TextFile::write(std::vector<char> vec) {
	try {
		this->contents = vec;
	}
	catch (...) {
		return -1;
	}
	return 0;
}
void TextFile::setAccess() {

}
int TextFile::append(std::vector<char> vec) {
	for (int i = 0; i < vec.size(); i++) {
		this->contents.push_back(vec[i]);
	}
	return 0;
}
vector<char> TextFile::read() {
	//for (int i = 0; i < this->contents.size(); i++) {
	//	//std::cout << contents[i];
	//	contents.push_back(contents[i]);
	//}
	return contents;
}
void TextFile::accept(AbstractFileVisitor* file) {
	if (file != nullptr) {
		file->visit_TextFile(this);
	}
	
}