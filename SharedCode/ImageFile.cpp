// definition of ImageFile class here
#include"ImageFile.h"
#include "AbstractFileVisitor.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

ImageFile::ImageFile(string name) {
	filename = name;
}
unsigned int ImageFile::getSize() {
	return (unsigned int) contents.size();
}
ImageFile::ImageFile(const ImageFile& img):filename(""),size(0) {
	filename=img.filename;
	size=img.size;
	for(int i=0; i<img.contents.size();i++){
      contents.push_back(img.contents[i]);
	}
}

AbstractFile* ImageFile::clone(string name) {
	ImageFile* imgClone=new ImageFile(*this);
	imgClone->filename=name+".img";
	return imgClone;

}
void ImageFile::setAccess() {

}
int ImageFile::retSize() {
	return size - '0';
}
string ImageFile::getName() {
	return filename;
}
int ImageFile::write(vector<char> vec) {
	size = vec[vec.size() - 1];
	for (int i = 0; i < vec.size() - 1; i++) {
		//we need to add a check if there is size mismatch in this if statement
		if ((vec[i] != 'X' && vec[i] != ' ')) {
			size = 0;
			contents.clear();
			return 1;
		}
		else {
			int truesize = (int)size - 48;
			int realsize = truesize * truesize;
			if (realsize == vec.size() - 1) {
				contents.push_back(vec[i]);
			}
			else {
				return 1;
			}
		}
	}
	return 0;
}
int ImageFile::append(vector<char> vec) {
	return 1;
}
int ImageFile::indexfunc(int x, int y) {
	int truesize = (int)size - 48;
	return x + truesize * y;
}
vector<char> ImageFile::read() {
	//int truesize = (int)size - 48;
	//  COMMENTING OUT DISPLAYING TO TEST NEW READ
	//for (int i = truesize-1; i >=0; i--) {//every row
	//	for (int j = 0; j < truesize; j++) {//every column
	//		cout << this->contents[indexfunc(j, i)];
	//	}
	//	cout << "\n";
	//}
	return contents;
}
void ImageFile::accept(AbstractFileVisitor* file) {
	file->visit_ImageFile(this);
}