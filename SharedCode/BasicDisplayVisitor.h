#pragma once
#include "AbstractFileVisitor.h"
#include "AbstractFile.h"
#include "TextFile.h"
#include "ImageFile.h"
// declaration of BasicDisplayVisitor here
class BasicDisplayVisitor : public AbstractFileVisitor{
public:
	BasicDisplayVisitor();
	void visit_TextFile(TextFile* filetype);
	void visit_ImageFile(ImageFile* filetype);
};