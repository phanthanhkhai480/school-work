// Final Project Milestone 2
// Submission Tester program
// File 200_ms2_tester_prof.cpp
// Version 1.0
// Date 3/15/2017
// Author       Fardad Soleimanloo
// 
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace ict;
int main(){  
  fstream file("200_ms2.txt", ios::out);
  file << "one" << endl << "two" << endl;
  file.close();
  MyFile F("200_ms2.txt");
  F.load(file);
  cout << "Linear: " << F << endl;
  cout << "As is: " << endl;
  F.print();
  cout << "Enter the folowing: " << endl << "three<ENTER>" << endl << "four<ENTER>" << endl << "Ctrl-D" << endl << endl;
  cin >> F;
  F.save(file);
  F.load(file);
  cout << F << endl;
  F.print();
  return 0;
}
