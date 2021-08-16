/**************************************************/
/*                                                */
/*  Lab 5 Starter file                            */
/*                                                */
/*  Name: Khai Phan                               */
/*  Student number: 100901164                     */
/*  Due Date: October 25						  */
/*                                                */
/**************************************************/

#include <iostream>
#include "Stack.h"

bool bracketCheck(const std::string& s){
	LStack<std::string> stack_;
	stack_.push(s);

	int openBracket_ = 0;
	int closeBracket_ = 0; 
	int openCurlyBracket_ = 0;
	int closeCurlyBracket_ = 0;
	int openSquareBracket_ = 0;
	int closeSquareBrack_ = 0;

	bool roundBracket_ = true;
	bool curlyBracket_ = true;
	bool squareBracket_ = true;

	std::string temp_ = stack_.top();
	for (int a = 0; a < temp_.length(); a++) {
		if (temp_[a] == '[')
			openBracket_++;
		if (temp_[a] == ']')
			closeBracket_++;

		if (temp_[a] == '{')
			openCurlyBracket_++;
		if (temp_[a] == '}')
			closeCurlyBracket_++;

		if (temp_[a] == '(')
			openSquareBracket_++;
		if (temp_[a] == ')')
			closeSquareBrack_++;
	}

	if (openBracket_ == closeBracket_ && openBracket_ > 0 && closeBracket_ > 0)
		roundBracket_ = false;
	if (openCurlyBracket_ == closeCurlyBracket_ && openCurlyBracket_ > 0 && closeCurlyBracket_ > 0)
		curlyBracket_ = false;
	if (openSquareBracket_ == closeSquareBrack_ && openSquareBracket_ > 0 && closeSquareBrack_ > 0)
		squareBracket_ = false;

	if (!roundBracket_ && !curlyBracket_ && !squareBracket_)
		return true;
	return false;
}

