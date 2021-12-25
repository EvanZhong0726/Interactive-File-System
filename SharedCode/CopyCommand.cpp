#include "CopyCommand.h"
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* p1) {
	system = p1;
}
void CopyCommand::displayInfo() {
	cout << "cp copies a file into another file with a different name. cp <file_to_copy> <new_name_with_no_extension>" << endl;
}
int CopyCommand::execute(string command) {
   if(command.find(' ') != string::npos) {
	   int pos=command.find(" ");
	   string fileName=command.substr(0,pos); 
	   string newFileName=command.substr(pos+1,string::npos);
       map<string, AbstractFile*> fileMap=system->getFileMap();
	   if (fileMap.find(fileName) != fileMap.end()) {
		   AbstractFile* actualFile = fileMap.find(fileName)->second;
		   if (system->closeFile(actualFile) == 1) {
			   int pos = (int)fileName.find(".");
			   string realFileName = fileName.substr(0, pos);
			   string extension = fileName.substr(pos + 1, string::npos);
			   if (realFileName != newFileName) {
				   string newFileNameExt = newFileName + "." + extension;
				   if (fileMap.find(newFileNameExt) == fileMap.end()) {
					   AbstractFile* cloneFile = actualFile->clone(newFileName);
					   system->addFile(cloneFile->getName(), cloneFile);
					   return 0;
				   }
				   else {
					   return 1;
				   }
			   }
			   else {
				   return 1;
			   }
		   }
		   else {
			   return 1;
		   }
	   }
	   else {
		   return 1;
	   }
   }
   else {
	   return 1;
   }
  
   
   
}