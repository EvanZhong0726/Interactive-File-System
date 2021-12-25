#pragma once


class TextFile;
class ImageFile;
// declaration of the file visitor interface here
class AbstractFileVisitor{
public:
	virtual void visit_TextFile(TextFile* filetype) = 0;
	virtual void visit_ImageFile(ImageFile* filetype) = 0;
private:
};