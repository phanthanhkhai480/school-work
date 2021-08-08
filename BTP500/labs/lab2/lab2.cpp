/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Namei Khai Phan                               */
/*  Student number: 100901164                     */
/*  Due Date: Oct 4				  */
/*                                                */
/**************************************************/

/* remember to code these in an iterative only manner*/


unsigned int factorial (unsigned int n){
	unsigned int result = 1;
	for(int a = 2; a <= n; a++) {
		result = n * factorial(n-1);
	}
	return result;
	//worst case complexity:
	//big-O notation:
}

double power (double base, unsigned int n){
	unsigned int result = 1;
	for(int b = 1; b <= n; b++) {
		result = base * power(base, n-1);
	}
	return result;
	//worst case complexity:
	//big-O notation:
}
unsigned int fibonacci (unsigned int n){
	 int num[n + 2];                                 //1
	 num[0] = 0;                                     //1
	 num[1] = 1;                                     //1
	 for(int c = 2; c <= n; c++){                    //1 + (n-1) + (n-1)
		 num[c] = fibonacci(c - 1) + fibonacci(c - 2);       //2(n-1)
	}
	return num[n];                                   //1
	//worst case complexity: T(n) = 4n+2
	//big-O notation: n+2
}
