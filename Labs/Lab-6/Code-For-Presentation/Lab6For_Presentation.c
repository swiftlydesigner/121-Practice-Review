//
//  main.c
//  te
//
//  Created by main on 9/29/23.
//


#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");

	int i;
	int sum = 0;
	
INITALIZERS:
	i = 0;
	
BODY:
	sum += i;
	goto INCREMENT;
	
INCREMENT:
	i += 1;
	goto CONDITION;
	
CONDITION:
	if (i < 100) {
		goto BODY;
	} else {
		goto EXIT_LOOP;
	}
	
EXIT_LOOP:
	printf("Sum is: %d", sum);
	return 0;
	
	
	for (int i = 0; i < 100; i += 1) {
		sum += 1;
	}
}
