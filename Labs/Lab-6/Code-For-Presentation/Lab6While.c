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

	int i = 0;
	
	do {
		i += 1;
	} while (i < 100);
	
BODY:
	i += 1;
	goto CONDITION;
	
CONDITION:
	if (i < 100) {
		goto BODY;
	} else {
		goto EXIT_LOOP;
	}
	
EXIT_LOOP:
	printf("i: %d", i);
	return 0;
	
	
}
