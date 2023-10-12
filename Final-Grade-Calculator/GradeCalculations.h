//
//  GradeCalculations.h
//  Final Grade Calculator
//
//  Created by Kyle Parker on 10/11/23.
//

#ifndef GradeCalculations_h
#define GradeCalculations_h

#include <stdio.h>

void runGrades (void);

double calculateWeightedAverage ( double * grades, double * weights, size_t length );

void getLetterGrade (double grade, char * letterGrade);

#endif /* GradeCalculations_h */
