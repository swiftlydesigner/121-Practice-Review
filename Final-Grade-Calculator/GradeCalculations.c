//
//  GradeCalculations.c
//  Final Grade Calculator
//
//  Created by Kyle Parker on 10/11/23.
//

#include "Headers.h"
#include <math.h>
#include <string.h>

/// Run the grades routine.
///
/// - Postcondition: Grades will have been calculated.
/// - Date: October 11, 2023
///
/// - Version: 1.0

void runGrades (void) {
	double midterm1 = -1, midterm2 = -1, finalWritten = -1, finalLab = -1;
	double quizzes = -1, programmingAssignments = -1, labs = -1;
	double participation = -1;
	
	double grade = 0;
	
	char letterGrade[3] = "";
	
	clearScreen();
	
	printf("INFO: If you do not have grades for midterm 1 & 2, then midterm 1 will be worth 20%%.\n\n");
	
	printf("[10%%] What grade did you get on midterm 1?\n> ");
	
	while (midterm1 < 0 || finalWritten > 100) {
		midterm1 = getDoubleFromUser();
	}
	
	printf("\n[10%%] What grade did you get on midterm 2? (Enter 0.5 if you have not taken this yet)\n> ");
	
	while (midterm2 < 0 || midterm2 > 100) {
		midterm2 = getDoubleFromUser();
	}
	
	printf("\n[8%%] What is your average grade on quizzes?\n> ");
	
	while (quizzes < 0 || quizzes > 100) {
		quizzes = getDoubleFromUser();
	}
	
	printf("\n[30%%] What is your average grade on programming assignments?\n> ");
	
	while (programmingAssignments < 0 || programmingAssignments > 100) {
		programmingAssignments = getDoubleFromUser();
	}
	
	printf("\n[20%%] What is your average grade in labs?\n> ");
	
	while (labs < 0 || labs > 100) {
		labs = getDoubleFromUser();
	}
	
	printf("\n[10%%] What is your lab FINAL score?\n> ");
	
	while (finalLab < 0 || finalLab > 100) {
		finalLab = getDoubleFromUser();
	}
	
	printf("\n[10%%] What is your written FINAL score?\n> ");
	
	while (finalWritten < 0 || finalWritten > 100) {
		finalWritten = getDoubleFromUser();
	}
	
	clearScreen();
	
	double gradeArray[8] = {midterm1, midterm2 == 0.5 ? midterm2 : midterm1, finalLab, finalWritten, quizzes, programmingAssignments, labs, participation};
	double weightArray[8] = {0.1, 0.1, 0.1, 0.1, 0.08, 0.3, 0.2, 0.02};
	
	grade = calculateWeightedAverage(gradeArray, weightArray, 8);
	
	if (grade == NAN) {
		printf("Internal Grade Calculation Error: LINE=%d, FILE=%s, FUNC=%s", __LINE__, __FILE__, __FUNCTION__);
		return;
	}
	
	getLetterGrade(grade, letterGrade);
	
	printf("Your grade: %.2lf%% => %s!\n\n", grade * 100, letterGrade);
	
	waitForReturn(false);
}

/// Calculate the weighted average of some given input. It will return a value [0,1].
///
/// - Precondition: weights must sum to 1.0. Both arrays must have the same length
/// - Postcondition: Weighted average is calculated.
/// - Parameter grades: An array of grades for a particular section
/// - Parameter weights: An array of weights for the corresponding section.
/// - Parameter length: Length of arrays.
/// - Returns: The weighted average, NAN if sum of weights is not 1.0.
/// - Date: October 11, 2023
///
/// - Version: 1.0
inline double calculateWeightedAverage ( double * grades, double * weights, size_t length ) {
	double checkSum = 0;
	double points = 0;
	
	for (size_t i = 0; i < length; i += 1) {
		checkSum += weights[i];
	}
	
	if (checkSum != 1.0) {
		return NAN;
	}
	
	for (size_t i = 0; i < length; i += 1) {
		points += grades[i] * weights[i];
	}
	
	return points / 100;
}

/// Get the letter grade based on an input.
///
/// - Precondition: Grade has been calculated.
/// - Parameter grade: The calculated grade
/// - Parameter letterGrade: The outputted letterGrade.
/// - Returns: The letter corresponding with the grade.
/// - Date: October 11, 2023
///
/// - Version: 1.0
void getLetterGrade (double grade, char * letterGrade) {
	
	if (grade > 1) {
		grade /= 100;
	}
	
	if (grade >= 0.94) {
		strncpy(letterGrade, "A", 3);
	} else if (grade >= 0.9) {
		strncpy(letterGrade, "A-", 3);
	} else if (grade >= 0.86) {
		strncpy(letterGrade, "B+", 3);
	} else if (grade >= 82) {
		strncpy(letterGrade, "B", 3);
	} else if (grade >= 78) {
		strncpy(letterGrade, "B-", 3);
	} else if (grade >= 74) {
		strncpy(letterGrade, "C+", 3);
	} else if (grade >= 70) {
		strncpy(letterGrade, "C", 3);
	} else if (grade >= 66) {
		strncpy(letterGrade, "C-", 3);
	} else if (grade >= 62) {
		strncpy(letterGrade, "D+", 3);
	} else if (grade >= 58) {
		strncpy(letterGrade, "D", 3);
	} else {
		strncpy(letterGrade, "F", 3);
	}	
}
