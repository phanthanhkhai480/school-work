
/*!\File SecureData.h
// \Brief BTP305 Workshop 9: Multi-Threading
// \Details    Longer description of file
// \Version 1.0
// \Date 10/11/2018
// \Author Eden Burton
// \copyright GNU Public License.
/*!\*/

#ifndef SECURE_DATA_H
#define SECURE_DATA_H
#include <iostream>

 namespace w10 
 {
     class Cryptor 
	 {
       public:
         char operator()(char in, char key) const 
			{ return in ^ key; } 
     };
     void converter(char*, char, int, const Cryptor&);

     class SecureData 
	 {
         char* text;			/*!< Array of char for receiving text !>*/
		 std::ofstream* ofs;	/*!< Ofstream variable !>*/
         int nbytes;			/*!< Number of bytes !>*/
         bool encoded;			/*!< Check for encoded data !>*/
         void code(char);		/*!<  !>*/
       public:
         SecureData(const char*, char, std::ofstream*);
			/*!< Custom Constructor !>*/
         SecureData(const SecureData&) = delete;
			/*!< Copy Constructor !>*/
         SecureData& operator=(const SecureData&) = delete;
			/*!< Copy Assignment Operator !>*/
         ~SecureData();
			/*!< Destructor !>*/
         void display(std::ostream&) const;
			/*!< Display function !>*/
         void backup(const char*);
			/*!< Data Backup Function !>*/
         void restore(const char*, char);
			/*!< Data Restore Function !>*/
     };
     std::ostream& operator<<(std::ostream&, const SecureData&);
		/*!< Helper Function !>*/
 }

#endif
