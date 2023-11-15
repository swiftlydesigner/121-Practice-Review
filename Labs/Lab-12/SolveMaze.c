//
//  SolveMaze.c
//  t
//
//  Created by main on 11/15/23.
//

#include "SolveMaze.h"

Coord ** solveMaze(char maze[8][8]) {
    Coord ** result = (Coord **)malloc(sizeof(Coord * ) * 100);
    
    // Verify `result` was alloced.
    if (result) {
        memset(result, 0, sizeof(sizeof(Coord * ) * 100));
        
        // Start at 0, 1; per instructions.
        solveMazeHelper(maze, 0, 1, result);
    }
    
    
    return result;
}

/// Remeber, `result++` will go the next element, `result--` will go to the last element.
/// This is how we can go from the current possition to the next.
/// Make sure to use recusion (call itself).
/// set a coord at result by calling the function as such: `setCoord(x, y, result)`.
///     Call this funciton whenever you go to the next position.
/// You may need to set global variables or return a value. This depends on your style.
void solveMazeHelper(char maze[8][8], int x, int y, Coord ** result) {
    // if good in x dir
        // setCoord(x, y, result)
        // solveMazeHelper(maze, x++, y, result++);
    // if need to go back in x or y dir
        // return and do not make another recursive call
    
    // Only increment x OR y.
        // When x OR y is incremented, then setCoord should be called AND result should be incremented.
        // When x OR y is decermented, then result should be decremented.
}
