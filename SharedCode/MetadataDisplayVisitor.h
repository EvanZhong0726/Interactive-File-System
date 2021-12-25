#pragma once
#include "AbstractFileVisitor.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
// declaration of MetadataDisplayVisitor here
class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	MetadataDisplayVisitor();
	void visit_TextFile(TextFile* filetype);
	void visit_ImageFile(ImageFile* filetype);
};