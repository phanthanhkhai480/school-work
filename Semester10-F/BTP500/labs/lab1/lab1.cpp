/**************************************************/
/*                                                */
/*  Lab 1 Starter file                            */
/*                                                */
/*  Name: Khai Phan                               */
/*  Student number: 100901164                     */
/*  Due Date: September 27			  */
/*                                                */
/**************************************************/

/* remember to code these in an iterative only manner*/

unsigned int factorial (unsigned int n) {
	unsigned int result = 1;		//1
	for(unsigned int a = 2; a <= n; a++) {	//1 + (n-1) + (n-1)
		result=result*a;		//2(n-1)
	}
	return result;				//1
	//worst case complexity: T(n) = 4n-1
	//big-O notation: n-1
}

double power (double base, unsigned int n) {
	unsigned long long result = 1;		//1
	for(unsigned int b = 1; b <= n; b++) {	//1 + (n-1) + (n-1)
		result *= base;			//2(n-1)
	}
	return result;				//1
	//worst case complexity: T(n) = 4n-1
	//big-O notation: n-1
}
unsigned int fibonacci (unsigned int n) {
	int num[n + 2];					//1
	num[0] = 0;					//1
	num[1] = 1;					//1
	for(int c = 2; c <= n; c++){			//1 + (n-1) + (n-1)
		num[c] = num[c - 1] + num[c - 2];	//2(n-1)
	}
	return num[n];					//1
	//worst case complexity: T(n) = 4n+2
	//big-O notation: n+2
}

