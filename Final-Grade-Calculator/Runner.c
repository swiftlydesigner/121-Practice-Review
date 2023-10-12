//
//  Runner.c
//  Final Grade Calculator
//
//  Created by Kyle Parker on 10/11/23.
//

#include "Headers.h"

/// Runner for application. All logic handled in here.
///
/// - Postcondition: Program is done executing.
/// - Returns: Program exit code.
/// - Date: October 11, 2023
///
/// - Version: 1.0
int runner(void) {
	
	while (1) {
		clearScreen();
		printMenu();
		printf("\n> ");
		int choice = getIntFromUser();
		if (choice == 1) {
			runGrades();
		} else if (choice == 2) {
			return 0;
		}
	}
	
	return 0;
}
