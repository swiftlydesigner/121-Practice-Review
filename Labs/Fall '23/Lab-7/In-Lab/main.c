//
//  main.c
//  Debugging
//
//  Created by main on 10/10/23.
//

#include "CWE.h"

void firstVoid(void) {
	double firstDouble = 12;
	int firstX = 10;
	printf("firstDouble addr = %p\n", &firstDouble);
	printf("firstX addr = %p\n", &firstX);
}

void secondVoid(void) {
	int secondX = 214;
	double secondDouble = 12;
	printf("secondDouble addr = %p\n", &secondDouble);
	printf("secondX addr = %p\n", &secondX);
}


int main(void) {
	
	/// Shows that if we work with the same type, then we may actually
	/// use the same memory space since they are completely unrelated.
	/// Note: when the order of declartion changes, so do the memory
	/// addresses.
	firstVoid();
	secondVoid();
	
	CWE787();
	
	CWE20();
	
	CWE119(2, (char*[]){"/path/exec", "Words H"});
	
	CWE120();
	
	CWE125();
	
	CWE170();
	
	CWE190();
	
	CWE193();
	
	CWE197();
	
	CWE369();
	
	return 0;
}


