#include "PasswordProxy.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;
PasswordProxy::PasswordProxy(AbstractFile* point, string pass) {
	pointer = point;
	password = pass;
}

AbstractFile* PasswordProxy::clone(string name){
	string newPass = this->password;
	AbstractFile* newFile = this->pointer->clone(name);
	return new PasswordProxy(newFile, newPass);
     
}
PasswordProxy::~PasswordProxy() {
	delete pointer;
}

string PasswordProxy::passwordPrompt() {
	cout << "Enter file password" << endl;
	string s;
	cin >> s;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return s;
}

void PasswordProxy::setAccess() {

}

bool PasswordProxy::passwordValid(string pass) {
	return (pass == password);
}

vector<char> PasswordProxy::read() {
	string prompt = passwordPrompt();
	vector<char> v;
	if (passwordValid(prompt)) {
		return pointer->read();
	}
	else {
		return v;
	}
}

int PasswordProxy::write(vector<char> cont) {
	string prompt = passwordPrompt();
	if (passwordValid(prompt)) {
		return pointer->write(cont);
	}
	else {
		//pass not valid
		return 1;
	}
}

int PasswordProxy::append(vector<char> cont) {
	string prompt = passwordPrompt();
	if (passwordValid(prompt)) {
		return pointer->append(cont);
	}
	else {
		return 1;
	}
}

unsigned int PasswordProxy::getSize() {
	return pointer->getSize();
}

string PasswordProxy::getName() {
	return pointer->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	string prompt = passwordPrompt();
	if (passwordValid(prompt)) {
		pointer->accept(visitor);
	}
}