// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include"ImageFile.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include <string>
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string name) {
	string txt = "txt";
	string img = "img";
	int pos = name.find(".");
	string extension = name.substr(pos + 1, name.size() - 1);
		if (extension == txt) {
			TextFile* txtFile = new TextFile(name);
			
			return txtFile;
		}
		if (extension == img) {
			ImageFile* imgFile = new ImageFile(name);
			
			return imgFile;
		} 

		return nullptr;
	
}