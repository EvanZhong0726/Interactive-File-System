#include "WriteProxy.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
WriteProxy::WriteProxy(AbstractFile* point, char sign):writeAccess(false) {
	pointer = point;
	if (sign == '-') {
		writeAccess = false;
	}
	else if(sign=='+'){
		writeAccess = true;
	}
	else {
		pointer = nullptr;
		cout << "Please put in + for write access or - for read-only" << endl;
	}
}

AbstractFile* WriteProxy::clone(string name) {
	bool writable = this->writeAccess;
	char sign;
	if (writable) {
		sign = '+';
	}
	else {
		sign = '-';
	}
	AbstractFile* newFile = this->pointer->clone(name);	
	return new WriteProxy(newFile,sign);
}
WriteProxy::~WriteProxy() {
	delete pointer;
}


vector<char> WriteProxy::read() {
	return pointer->read();
}

int WriteProxy::write(vector<char> cont) {
	if (writeAccess) {
		return pointer->write(cont);
	}
	else {
		cout << "This file is read-only" << endl;
		return 1;
	}
}
void WriteProxy::setAccess() {
	writeAccess = true;
}
int WriteProxy::append(vector<char> cont) {
	if (writeAccess) {
		return pointer->append(cont);
	}
	else {
		cout << "This file is read-only" << endl;
		return 1;
	}
}

unsigned int WriteProxy::getSize() {
	return pointer->getSize();
}

string WriteProxy::getName() {
	return pointer->getName();
}

void WriteProxy::accept(AbstractFileVisitor* visitor) {
	pointer->accept(visitor);
}