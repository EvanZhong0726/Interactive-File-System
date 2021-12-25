#include "RenameParsingStrategy.h"
#include "CopyCommand.h"
#include "SimpleFileSystem.h"

using namespace std;

RenameParsingStrategy::RenameParsingStrategy() {

}

vector<string> RenameParsingStrategy::parse(string command) {
	vector<string> vec;
	if (command.find(' ') != string::npos) {
		int pos = command.find(' ');
		string becopiedFileName = command.substr(0, pos);
		string newFileName = command.substr(pos + 1, string::npos);
		string first = becopiedFileName +" "+newFileName;
		string second = becopiedFileName;
		vec.push_back(first);
		vec.push_back(second);
		//return vec;
		//need to make password persist after rename
	}
	return vec;
}