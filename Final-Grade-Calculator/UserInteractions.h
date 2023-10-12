//
//  UserInteractions.h
//  Final Grade Calculator
//
//  Created by Kyle Parker on 10/11/23.
//

#ifndef UserInteractions_h
#define UserInteractions_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getIntFromUser (void);
double getDoubleFromUser (void);

void printMenu (void);

void clearScreen(void);

void waitForReturn(bool shouldWait);

#endif /* UserInteractions_h */
