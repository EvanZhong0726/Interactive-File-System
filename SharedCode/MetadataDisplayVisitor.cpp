// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"

using namespace std;
// definitions of basic display visitor here
MetadataDisplayVisitor::MetadataDisplayVisitor() {
  
}
void MetadataDisplayVisitor::visit_TextFile(TextFile* filetype) {

	
	cout << filetype->getName() << " ";
	
	cout << "text" << " ";
	cout << filetype->getSize() << endl;
	
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* filetype) {

	
	cout << filetype->getName()<< " ";
	cout << "image" << " ";
	cout << filetype->getSize() << endl;

}