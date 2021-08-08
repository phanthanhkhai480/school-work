//Question8.cpp - Source code for the programming portion of the Mid-Term (Question 8)
//
#include <iostream>

using namespace std;
unsigned int multiply(unsigned int a, unsigned int b) {
	//Enter code here
	unsigned int total = 0;
	for (int i = 0; i < b; i++) {
		total += a;
		multiply(total, i);
	}
	return total;
}


int main() {
	int test[] = { 11,2,23,51,22,35,14,23,6,77 };
	int res;
	for (int i = 0; i < 5; ++i) {
		res = multiply(test[i], test[i + 1]);
		cout << test[i] << "x" << test[i + 1] << " = " << res << endl;
	}
}
