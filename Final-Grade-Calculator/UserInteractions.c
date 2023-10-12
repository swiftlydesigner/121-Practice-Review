//
//  UserInteractions.c
//  Final Grade Calculator
//
//  Created by Kyle Parker on 10/11/23.
//

#include "Headers.h"
#include <string.h>


/// Get input from the user
///
/// - Precondition: Integer is needed from user
/// - Returns: Integer value from user
/// - Date: October 11, 2023
///
/// - Version: 1.0
int getIntFromUser (void) {
	char userInput[100];
	char * end;
	int value = 0;
	
	while (value != 1 && value != 2) {
		fgets(userInput, 100, stdin);
		userInput[2] = '\0';
		value = (int)strtod(userInput, &end);
		if (end && *end != '\n') {
			printf("Bad entry. Try again!\n> ");
			value = 0;
		}
	}
	
	return value;
}

/// Get input from the user
///
/// - Precondition: Double is needed from user
/// - Returns: Double value from user.
/// - Date: October 11, 2023
///
/// - Version: 1.0
double getDoubleFromUser (void) {
	char userInput[100];
	char * end;
	double value = -1;
	
	while (value < 0) {
		fgets(userInput, 100, stdin);
		userInput[99] = '\0';
		value = strtod(userInput, &end);
		if (end && *end != '\n') {
			printf("Bad entry. Try again!\n> ");
			value = -1;
		}
	}
	
	return value;
}

/// Print the user's menu.
///
/// - Date: October 11, 2023
///
/// - Version: 1.0
inline void printMenu(void) {
	clearScreen();
	printf("1) Calculate Grade\n2) Exit");
}

/// clears the screen using a macro defined per OS for cross platform compatability.
///
/// - Precondition: Screen needs to be cleared
/// - Postcondition: Screen is cleared
/// - Warning: Any information printed prior to this call may not be accessable.
/// - Date: October 11, 2023
///
/// - version: 1.0
inline void clearScreen(void) {
	system(CLEAR_SCREEN);
}

/// wait for return, wait on user
///
/// - Precondition: prompt or end of activity
/// - Postcondition: user pressed return/return
/// - Parameter shouldClear: boolean indicating if getLine should be called before prompt, so it does not return without waiting. By default, false.
/// - Date: October 11, 2023
///
/// - version: 1.1
inline void waitForReturn(bool shouldClear) {
	char userInput[100];
	if (shouldClear) { fgets(userInput, 100, stdin); }

	printf("[PRESS %s TO CONTINUE]", RETURN_KEY_UPPER);
	fgets(userInput, 100, stdin);
}

/// <#DESCRIPTION OF FUNCTION#>
///
/// - Precondition: <#WHAT DO WE NEED TO CALL *BEFORE* CALLING?#>
/// - Postcondition: <#WHAT DO WE NEED TO KNOW *AFTER* CALLING?#>
/// - Warning: <#IS THERE SOMETHING THAT COULD GO WRONG? CRASH? PURPOSEFUL EXIT? POINTER IS POSSIBLY NULL?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Returns: <#WHAT DOES IT RETURN?#>
/// - Seealso: <#NAME OF OTHER FUNCTION#>
/// - Date: <#UPDATE DATE#>
///
/// - Version: <#1.0#>
