//
//  myio.c
//  Sample Three File Format
//
//  Created by Kyle Parker on 1/7/24.
//

#include "myio.h"
#include <strings.h> // memset
#include <ctype.h> // isdigit
#include <stdlib.h> // atoi

// MARK: Begin Output Functions

/// Print `Hello, World~` to the console.
///
/// - Postcondition: `Hello, World!` is printed.
/// - Date: 01/07/24
///
/// - Version: 1.0
void printHelloWorld(void) {
    printf("Hello, World!\n");
}

/// Print the argued int in the format of `Result = $VAL`
///
/// - Precondition: Result was calculated.
/// - Postcondition: Result was printed.
/// - Parameter result: The value to print
/// - Date: 01/07/2024
///
/// - Version: 1.0
void printResult(int result) {
    printf("Result = %d\n", result);
}

// MARK: Begin Input Functions

/// Get an integer from the user. Prompt is printed before-hand.
///
/// - Precondition: Prompt is printed and expecting non-negative result.
/// - Postcondition: User input is returned or -1 on error.
/// - Warning: Negative int is possible.
/// - Returns: User's input, -1 on error
/// - Date: 01/07/2024
///
/// - Version: 1.0
int getIntFromUser(void) {
    // Input buffer (100 character array)
    char input[100];
    // The return value to set (set to -1 incase of error)
    int returnValue = -1;
    // Ensure that input's buffer is null chars upfront
    memset(input, 0, 100);
    
    // Get first 100 chars in stdin. Note: This may leave some input
    // in the buffer. Be sure to clear stdin **Do not call fflush**.
    // First param: where to store
    // Second param: how many chars to read
    // Third param: What file to read from (we set it to keyboard (stdin))
    fgets(input, 100, stdin);
    
    // This will ensure we can call atoi without causing undefined behavior
    // See: https://cplusplus.com/reference/cctype/isdigit/
    if (isdigit(input[0])) {
        // call a system function to convert as much of the string
        // as possible to an int.
        // See: https://cplusplus.com/reference/cstdlib/atoi/
        returnValue = atoi(input);
    }
    
    return returnValue;
}
