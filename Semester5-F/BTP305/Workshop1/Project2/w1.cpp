// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
//Author:  Dr. Elliott Coleshill
//Date:    2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"
using namespace std;

extern int MAX;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab1Output.txt");

	ofs << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		ofs << argv[i] << ' ';
	}
    if (argc < 2) {
        ofs << "\nInsufficient number of arguments\n";
        return 1;
	}
	ofs << "\n The Maximum number of characters stored : "
		<< MAX << std::endl;
	

	/****
	TO DO:  Add code here that will print out the max characters stored
	              by your CString object
	*****/

	for (int i = 1; i < argc; i++) {
		process(argv[i], ofs);
	}

	int WaitKey;
	std::cin >>  WaitKey;

	ofs.close();
	return 0;
}
