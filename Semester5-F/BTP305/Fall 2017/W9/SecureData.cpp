// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"

namespace W9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") + std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = -1;
		input >> std::noskipws;

		char temp;
		while (input.good()) {
			input >> temp;
			nbytes++;
		}

		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = -1;
		while (input.good())
			input >> text[i++];
		text[i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text " << file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		converter(text, key, nbytes, Cryptor());
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			   // open binary file
			   std::ofstream backupFile;
			
			   // write binary file here
			   backupFile.open(file);
			   backupFile << text;
			   backupFile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {

		// open binary file
		std::ifstream backupFile(file, std::ios::in);

		nbytes = -1;
		backupFile >> std::noskipws;

		char temp;

		while (backupFile.good()) {
			backupFile >> temp;
			nbytes++;
		}

		backupFile.clear();
		backupFile.seekg(0, std::ios::beg);

		// allocate memory here
		text = new char[nbytes + 1];

		// read binary file here
		int i = 0;

		while (backupFile.good()) { backupFile >> text[i++]; }

		text[--i] = '\0';


		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file " << file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";

		backupFile.close();
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}