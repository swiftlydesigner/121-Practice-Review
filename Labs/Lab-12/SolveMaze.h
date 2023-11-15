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

void solveMazeHelper(char maze[8][8], int x, int y, Coord ** result);

static void setCoord(int x, int y, Coord ** postion) {
    if (*postion != NULL) {
        free(*postion);
    }
    
    Coord * newPos = (Coord*)malloc(sizeof(Coord));
    
    *postion = newPos;
}

static bool compareCoords(Coord * a, Coord * b) {
    return a->x == b->x && a->y == b->y;
}

#endif /* SolveMaze_h */
