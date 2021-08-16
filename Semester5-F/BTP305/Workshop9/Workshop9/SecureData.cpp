 // Workshop 10 - Multi-Threading
 // SecureData.cpp

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <thread>
 #include <functional>
 #include "SecureData.h"

 namespace w10 {

     void converter(char* t, char key, int n, const Cryptor& c) {
         for (int i = 0; i < n; i++)
             t[i] = c(t[i], key);
     }

     SecureData::SecureData(const char* file, char key, std::ofstream* pOfs) {

		 ofs = pOfs;

		 // open text file
         std::fstream input(file, std::ios::in);
         if (!input)
             throw std::string("\n***Failed to open file ") +
              std::string(file) + std::string(" ***\n");

         // copy from file into memory
         nbytes = 0;
         input >> std::noskipws;
         while (input.good()) {
             char c;
             input >> c;
             nbytes++;
         }
         nbytes--;
         input.clear();
         input.seekg(0, std::ios::beg);
         text  = new char[nbytes + 1];

         int i = 0;
         while (input.good())
             input >> text[i++];
         text[--i] = '\0';
         *ofs << "\n" << nbytes << " bytes copied from text "
          << file << " into memory (null byte added)\n";
         encoded = false;

         // encode using key
         code(key);
         *ofs << "Data encrypted in memory\n";
     }

     SecureData::~SecureData() {
         delete [] text;
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
 
		 int div = this->nbytes / 4;
		 auto connect1 = std::bind(converter, text + div * 3, key, this->nbytes - (div * 3), Cryptor());
		 std::thread c1(connect1);
		 auto connect2 = std::bind(converter, text + div * 2, key, this->nbytes - (div * 2), Cryptor());
		 std::thread c2(connect2);
		 auto connect3 = std::bind(converter, text + div, key, div, Cryptor());
		 std::thread c3(connect3);

		 converter(text, key, div, Cryptor());
		 c3.join();
		 c2.join();
		 c1.join();
		 
         encoded = !encoded;
     }

     void SecureData::backup(const char* file) {
         if (!text)
             throw std::string("\n***No data stored***\n");
         else if (!encoded)
             throw std::string("\n***Data is not encoded***\n");
         else {
    		// open binary file
			std::ofstream myFile;
			
	        // write binary file here
			myFile.open(file);
			myFile << text;
			myFile.close();
         }
     }

     void SecureData::restore(const char* file, char key) {
         // open binary file
		 std::ifstream myFile(file, std::ios::binary);
		
		 myFile.seekg(0, myFile.end);
		 int temp = myFile.tellg();
		 myFile.seekg(0, myFile.beg);

         // allocate memory here
		 text = new char[temp+1];
		 
         // read binary file here
		 myFile.read(this->text, temp);
		 myFile.close();

         *ofs << "\n" << nbytes + 1 << " bytes copied from binary file "
          << file << " into memory (null byte included)\n";

         // decode using key
         code(key);
         *ofs << "Data decrypted in memory\n\n";
     }

     std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
         sd.display(os);
         return os;
     }

 }
