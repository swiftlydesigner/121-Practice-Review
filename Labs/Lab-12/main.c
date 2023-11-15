//
//  main.c
//  t
//
//  Created by main on 11/15/23.
//

#include "SolveMaze.h"

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
    
    // Not a good test! I was low on time
    
    Coord ** result = solveMaze(maze);
    
    Coord ** expectedResult = malloc(sizeof(Coord*) * 100);
    memset(expectedResult, 0, sizeof(Coord*) * 100); // Set all eles to null.
    
    Coord ** head = expectedResult;
    
    // x = 1, set all bad spots
    for (int y = 0; y < 7; ++y) {
        setCoord(1, y, expectedResult++);
    }
    
    // x = 3, set all bad spots
    for (int y = 2; y < 8; ++y) {
        setCoord(3, y, expectedResult++);
    }
    
    // y = 1, set all bad spots
    for (int x = 3; x < 7; ++x) {
        setCoord(x, 1, expectedResult++);
    }
    
    // y = 3, set all bad spots
    for (int x = 5; x < 8; ++x) {
        setCoord(x, 3, expectedResult++);
    }
    
    setCoord(4, 5, expectedResult++);
    setCoord(6, 6, expectedResult++);
    
    expectedResult = head;
    
    if (result == NULL) {
        fprintf(stderr, "TEST FAILURE! EXPECTED NON-NULL");
    } else {
        int resIndex = 0;
        bool isValid = true;
        
        for (; resIndex < 100 &&
             (result[resIndex] != NULL) &&
             isValid
             ; resIndex++) {
            
            for (int expectedIndex = 0; expectedIndex < 100 &&
                                        expectedResult[expectedIndex] != NULL &&
                                        isValid; expectedIndex++) {
                isValid = !compareCoords(result[resIndex], expectedResult[expectedIndex]); // Verify that the result is not in the unexpectedResult array. This means it went over an X.
            }
            
        }
        
        Coord * coord = malloc(sizeof(Coord));
        coord->x = 7;
        coord->y = 7;
        if (compareCoords(result[resIndex - 1], coord)) {
            fprintf(stderr, "TEST PASS!");
        } else {
            fprintf(stderr, "TEST FAIL!");
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
