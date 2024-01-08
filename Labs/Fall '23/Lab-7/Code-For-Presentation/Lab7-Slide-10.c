#include <stdio.h>

#define N 0

void setIntToNum(int* ptr, int num) {
	*ptr = num;
	num = 250;
}

int main(void) {
	int myNumber = 100;
	printf("myNumber = %d\n&myNumber = %p\n", myNumber, &myNumber);
	printf("sizeof(char*) = sizeof(void*) = %lu\n", sizeof(char*));

	int * myNumPtr = &myNumber; // Declare pointer type
	*myNumPtr = 10; // Dereference pointer (use/modify value)	
	myNumber = 10 * 10; // Product

	// Assume myNumPtr is an array //
	myNumPtr++; // Go to the next int
	myNumPtr--; // Go to the last int
	myNumPtr += N; // Go to N ints away
	myNumPtr -= N; // Go to -N ints away
	(myNumPtr + N); // Look at int N away // myNumPtr is unmodified
	(myNumPtr - N); // Look at int -N away // myNumPtr is unmodified
	*myNumPtr = N; // Dereference and set myNumPtr to N

	int myPtrDst = 599;
	int myNum = 124;
	printf("myPtrDst = %d\tmyNum = %d\n", myPtrDst, myNum);
	setIntToNum(&myPtrDst, myNum);
	printf("myPtrDst = %d\tmyNum = %d\n", myPtrDst, myNum);

	printf("Observe memory addresses (Listed in order of declration):\n");
	printf("[int] myNumber = %p\n", &myNumber);
	printf("[int *] myNumPtr = %p\n", &myNumPtr);
	printf("[int] myPtrDst = %p\n", &myPtrDst);
	printf("[int] myNum = %p\n", &myNum);

	return 0;
}
