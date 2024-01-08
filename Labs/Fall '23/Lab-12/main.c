//
//  main.c
//  t
//
//  Created by main on 11/15/23.
//

#include "SolveMaze.h"
#include <math.h>

// see if the coords are equal position
bool compareCoords(Coord * a, Coord * b) {
    // Ensure both a and b exist
    if (!a || !b) {
        return false;
    }
    
    // Verify x & y coords match
    return a->x == b->x && a->y == b->y;
}

void testMaze1(void) {
    char maze[8][8] = {
        {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X', 'X', 'X', ' '},
        {' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'},
        {' ', 'X', ' ', 'X', ' ', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', 'X', ' ', ' ', ' '},
        {' ', 'X', ' ', 'X', ' ', ' ', 'X', ' '},
        {' ', ' ', ' ', 'X', ' ', ' ', ' ', ' '},
    };
    
    // Not the best test!
    
    Coord ** result = solveMaze(maze);
    
    Coord ** badResult = malloc(sizeof(Coord*) * 1000);
    memset(badResult, 0, sizeof(Coord*) * 1000); // Set all eles to null.
    for (int i = 0; i < 100; ++i) {
        badResult[i] = malloc(sizeof(Coord));
    }
    
    Coord * currentEle = *badResult;
    
    // x = 1, set all bad spots
    for (int y = 0; y < 7; ++y) {
        setCoord(1, y, currentEle++);
    }
    
    // x = 3, set all bad spots
    for (int y = 2; y < 8; ++y) {
        setCoord(3, y, currentEle++);
    }
    
    // y = 1, set all bad spots
    for (int x = 3; x < 7; ++x) {
        setCoord(x, 1, currentEle++);
    }
    
    // y = 3, set all bad spots
    for (int x = 5; x < 8; ++x) {
        setCoord(x, 3, currentEle++);
    }
    
    setCoord(4, 5, currentEle++);
    setCoord(6, 6, currentEle++);
    
    if (result == NULL) {
        fprintf(stderr, "TEST FAILURE! EXPECTED NON-NULL");
    } else {
        bool isValid = true;
        int testIndex = 0;
        Coord * lastValidResult = NULL;
        
        // Go through result from user
        for (Coord * resultPtr = *result;
                testIndex < 1000 &&
                resultPtr->x >= 0 && resultPtr->y >= 0 &&
                isValid ;
             ++testIndex, ++resultPtr) {
            
            // Ensure the result is not on the `badResult` list
            int badIndex = 0;
            for (Coord * badCoordPtr = *badResult;
                 badIndex < 1000 &&
                 isValid ;
                 ++badIndex, ++resultPtr) {
                
                isValid = !compareCoords(badCoordPtr, resultPtr);
                
            }
            
            if (lastValidResult) {
                // If isValid is false, retain false state. (thus, set it to itself && COND2)
                // If inValid is true, then check if the the change is at most one in the X or Y direction. != acts as XOR (i.e., X can change, and Y cannot, OR Y can change and X cannot).
                isValid = isValid && (abs(lastValidResult->x - resultPtr->x) == 1 != abs(lastValidResult->y - resultPtr->y) == 1);
            }
            
            // Save last ptr, when this loop ends, the last valid is still in memory, so we can make sure it is 7, 7.
            lastValidResult = resultPtr;
            
        }
        
        Coord expectedLastCoord = { .x = 7, .y = 7 };
        
        if (isValid && compareCoords(lastValidResult, &expectedLastCoord)) {
            fprintf(stderr, "TEST PASS!\n");
        } else {
            fprintf(stderr, "TEST FAIL!\n");
        }
    }
    
    for (int i = 0; i < 1000; ++i) {
        free(result[i]);
        free(badResult[i]);
    }
    
    free(result);
    free(badResult);
}

void showRecursion(int x) {
    if (x == 10) {
        return;
    }
    showRecursion(x+1);
    printf("%d\n", x);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    showRecursion(1);
    
    testMaze1();
    
    return 0;
}


