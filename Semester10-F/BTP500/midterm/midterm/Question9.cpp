//Question9Tester.cpp - Tester source code for the programming portion of the Mid-Term (Question 9).
//                      Lines 11-59 test the non-sentinel case. Lines 61-108 test the sentinel case.
//
#include <iostream>

#include "Question9.h"

using namespace std;

int main() {
	//Tester section for non-sentinel nodes
	const int len = 10;
	int i = 0;
	DList<int> list;
	for (i = 0; i < len; ++i) {
		list.push_front((i * 15) % 23);
	}
	DList<int>::iterator it = list.begin();
	//Print out the list
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
	//Move three nodes to the back
	it = list.begin();
	list.moveToBack(it);
	//Print out the list
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
	it = list.begin();
	++it;
	list.moveToBack(it);
	//Print out the list
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
	it = list.end();
	--it;
	list.moveToBack(it);
	//Print out the list
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;

	//Erase five numbers
	for (i = 0; i < 5; ++i) {
		list.eraseFirstBiggerThan((i * 9) % 23);
	}
	//Print out the list
	for (it = list.begin(); it != list.end(); ++it) {
		cout << *(it) << " ";
	}
	cout << endl;
	cout << endl;

	////////////////////////////

	//Tester section for sentinel nodes
	Sentinel<int> list2;
	for (i = 0; i < len; ++i) {
		list2.push_front((i * 15) % 23);
	}
	Sentinel<int>::iterator it2 = list2.begin();
	//Print out the list2
	for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
		cout << *(it2) << " ";
	}
	cout << endl;
	//Move three nodes to the back
	it2 = list2.begin();
	list2.moveToBack(it2);
	//Print out the list2
	for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
		cout << *(it2) << " ";
	}
	cout << endl;
	it2 = list2.begin();
	++it2;
	list2.moveToBack(it2);
	//Print out the list2
	for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
		cout << *(it2) << " ";
	}
	cout << endl;
	it2 = list2.end();
	--it2;
	list2.moveToBack(it2);
	//Print out the list2
	for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
		cout << *(it2) << " ";
	}
	cout << endl;

	//Erase five numbers
	for (i = 0; i < 5; ++i) {
		list2.eraseFirstBiggerThan((i * 9) % 23);
	}
	//Print out the list2
	for (it2 = list2.begin(); it2 != list2.end(); ++it2) {
		cout << *(it2) << " ";
	}
	cout << endl;
	cout << endl;

	return 0;
}
