#include "TouchEditDisplayParsingStrategy.h"
#include <iostream>
using namespace std;

TouchEditDisplayParsingStrategy::TouchEditDisplayParsingStrategy(){

}

vector<string> TouchEditDisplayParsingStrategy::parse(string command) {
	//fileName then things you want to write q or wq and then display it
	vector<string> vec;
	if (command.find(' ') != string::npos) {
		int pos = command.find(' ');
		string fileName = command.substr(0, pos);
		string Cmd = command.substr(pos+1, string::npos);
		
			vec.push_back(fileName);
			vec.push_back(fileName);
			vec.push_back(fileName+" "+Cmd);
			return vec;
	}
	else {
		string fileName = command;
		vec.push_back(fileName);
		vec.push_back(fileName);
		vec.push_back(fileName);
		return vec;
	}
}
