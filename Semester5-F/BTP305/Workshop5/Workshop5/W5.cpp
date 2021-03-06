// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) 
{

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here
	auto letter = [](float mark)
	{
		if (mark >= 90)
			return Letter::A;
		else if (mark >= 80)
			return Letter::B;
		else if (mark >= 75)
			return Letter::C;
		else if (mark >= 70)
			return Letter::D;
		else if (mark >= 65)
			return Letter::E;
		else if (mark >= 60)
			return Letter::F;
		else if (mark >= 55)
			return Letter::G;
		else if (mark >= 50)
			return Letter::H;
		else if (mark >= 0)
			return Letter::I;
	};
	
	try
	{
		Grades grades(argv[1]);
		grades.displayGrades(ofs, letter);
	}
	catch (const char* err)
	{
		std::cout << err << std::endl;
	}
		
	


	ofs.close();
}