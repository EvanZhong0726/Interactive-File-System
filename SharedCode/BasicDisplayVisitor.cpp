#include "BasicDisplayVisitor.h"

#include <iostream>
#include <vector>
// definitions of basic display visitor here
BasicDisplayVisitor::BasicDisplayVisitor() {

}
void BasicDisplayVisitor::visit_TextFile(TextFile* filetype) {

	for (int i = 0; i < filetype->getSize(); i++) {
		std::cout << filetype->read()[i];
	}
	std::cout << "\n";
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* filetype) {
	//formatted
	for (int i = filetype->retSize()-1; i >=0; i--) {//every row
		for (int j = 0; j < filetype->retSize(); j++) {//every column
			std::cout << filetype->read()[filetype->indexfunc(j,i)];
		}
		
		std::cout << "\n";
		
	}
}

