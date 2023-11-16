//
//  SolveMaze.h
//  t
//
//  Created by main on 11/15/23.
//

#ifndef SolveMaze_h
#define SolveMaze_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _coord {
    int x;
    int y;
} Coord;

Coord ** solveMaze(char maze[8][8]);

void solveMazeHelper(char maze[8][8], int x, int y, Coord * result);

// set x and y val to required fields in the argued coord obj.
static void setCoord(int x, int y, Coord * coordEle) {
    // Ensure coordEle exists.
    if (coordEle == NULL) {
        return;
    }
    
    // Set x any y coords.
    coordEle->x = x;
    coordEle->y = y;
}

#endif /* SolveMaze_h */
