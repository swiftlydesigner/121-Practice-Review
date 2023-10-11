//
//  main.c
//  121 Review
//
//  Created by main on 10/7/23.
//

#include "TestHeaders.hpp"

int main(void) {
	// insert code here...
	auto tests = new Tests();
	
	tests->enguageWithUser();
	
	delete tests;
	return 0;
}

