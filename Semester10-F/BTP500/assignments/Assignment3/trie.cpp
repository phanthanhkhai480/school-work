/*******************************************************************/
/*                                                                 */
/*  A3									                           */
/*                                                                 */
/*  Author Name: Khai Phan	(1001901164)	 	                   */
/*				 Mamadou Diallo (035905156)                        */
/*  Due Date: Dec 7						                           */
/*                                                                 */
/*******************************************************************/

#include "trie.h"
#include <string>
#include <iostream>
#include <list>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

//completed
Trie::Trie() {	this->root_ = nullptr;	}

//completed
Trie::Trie(std::string data[], int sz) {
	for (int a = 0; a < sz; a++) {
		addWord(data[a]);
	}
}

//completed
void Trie::addWord(const std::string& newWord){
	Node* curr = this->root_;
	bool check_ = lookup(newWord);
	if (!check_) {
		// start from root node
		for (int a = 0; a < newWord.length(); a++) {
			// create a new node if path doesn't exists
			size_t index_ = CHAR_TO_INDEX(newWord[a]);
			if (curr->character[index_] == nullptr) {
				curr->character[index_] = new Node();
				curr->character[index_]->letter_ = newWord[a];
				curr->character[index_]->terminal_ = false;
			}
			curr = curr->character[index_];
		}
		//mark current node as leaf
		curr->terminal_ = true;
	}
 }

//completed
bool Trie::lookup(const std::string& word) const {
	//METHOD 1:
	//this method will directly check at the Trie, and compare each element
	//to see if there is match value or not. 
	//this method will be faster if tree has less to no value
	
	int counter_ = 0;
	Node* temp_ = this->root_;
	if (temp_ != nullptr) {
		for (int i = 0; i < word.length(); i++)
		{
			//find the letter position in array 26
			size_t index = CHAR_TO_INDEX(word[i]);
			//if letter position doesn't have any data, return false
			if (temp_->character[index] == nullptr)
				return false;
			else {
				if (temp_->character[index]->letter_ == word[i]) {
					counter_++;
					//if it does, continue the path
					temp_ = temp_->character[index];
				}
			}
		}

		//check if entire word is on Trie and end with a terminal
		if (counter_ == word.length() && temp_->terminal_ == true)
			 return true;
	}
	return false;
}

//completed
void Trie::Suggestion(Node* tmp_, const std::string& partialWord, std::string suggestions[], int& numOfWords) const
{
	if (tmp_->terminal_ == true) {
		//if letter is terminal, add into list of suggestion
		//and increase # of word found
		suggestions[numOfWords] = partialWord;
		numOfWords++;
	}

	for (int a = 0; a < NUMCHAR; a++)	{
		if (tmp_->character[a] != nullptr) {
			//adding new letter in to finding word
			char newLetter = tmp_->character[a]->letter_;
			std::string temp_ = partialWord;
			temp_ += newLetter;
			//if there is an existing node this recusive will keep the path going down
			//until the word is found and then it will continue its journey where it stop to go down
			Suggestion(tmp_->character[a], temp_, suggestions, numOfWords);
		}
	}
}

 //completed
 int Trie::suggest(const std::string& partialWord, std::string suggestions[]) const {
	 Node* temp_ = this->root_;			//positionings
	 int counter_ = 0;					//count the number of suggest
	 int count = 0;

	 //check if Trie exist
	 if (temp_ != nullptr) {
		 for (int a = 0; a < partialWord.length(); a++) {
			 //find the location of each letter
			 size_t index_ = CHAR_TO_INDEX(partialWord[a]);

			 //if letter not exist, return false
			 if (temp_->character[index_] == nullptr)
				 return false;
			 else {
				 //Check each letter of partial word
				 if (temp_->character[index_]->letter_ == partialWord[a]) {
					 counter_++;
					 //move to the next letter in Trie	
					 temp_ = temp_->character[index_];
				 }
			 }

			 //check if all character in partial are actually in the Trie before searching
			 if (counter_ == partialWord.length())
				 //pass the partial word into another function for finding similar word
				 Suggestion(temp_, partialWord, suggestions, count);
		 }
	 }
	 return count;
 }

//completed
Trie::~Trie() {		this->root_ = nullptr;	}