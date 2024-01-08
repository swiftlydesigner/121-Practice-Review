//
//  SolveMaze.c
//  t
//
//  Created by main on 11/15/23.
//

#include "SolveMaze.h"

Coord ** solveMaze(char maze[8][8]) {
    
    Coord ** result = (Coord **)malloc(sizeof(Coord * ) * 1000);
    
    // Verify `result` was allocated.
    if (result) {
        memset(result, 0, sizeof(Coord*) * 1000); // Set all eles to null.
        for (int i = 0; i < 100; ++i) {
            result[i] = malloc(sizeof(Coord));
            setCoord(-1, -1, result[i]);
        }
        
        // Start at 0, 1; per reqs.
        solveMazeHelper(maze, 0, 1, *result);
        
        /* SAMPLE CODE: PRINT MODIFICATIONS FROM SOLVE MAZE HELPER*/
        int i = 0;
        for (Coord * tmp = *result; i < 5; i++, tmp++) {
            printf("%d: X = %d; Y = %d\n", i, tmp->x, tmp->y);
        }
        
        /* END SAMPLE*/
    }
    
    return result;
}

/// Remeber, `result + 1` will go the next element, `result - 1` will go to the last element.
/// This is how we can go from the current possition to the next.
/// Make sure to use recusion (call itself).
/// set a coord at result by calling the function as such: `setCoord(x, y, result)`.
///     Call this funciton whenever you go to the next position.
/// You may need to set global variables or return a value. This depends on your style.
void solveMazeHelper(char maze[8][8], int x, int y, Coord * result) {
    /* SAMPLE CODE - SET coord array from 0 to 5, changing X over time */
    if (x < 5) {
        solveMazeHelper(maze, x + 1, y, result + 1);
    }
    
    setCoord(x, y, result);
    /* END SAMPLE */
    
    // if good in x dir
        // setCoord(x, y, result)
        // solveMazeHelper(maze, x + 1, y, result + 1);
    // if need to go back in x or y dir
        // return and do not make another recursive call
    
    // Only increment x OR y.
        // When x OR y is incremented, then setCoord should be called AND result should be incremented.
        // When x OR y is decermented, then result should be decremented.
}
