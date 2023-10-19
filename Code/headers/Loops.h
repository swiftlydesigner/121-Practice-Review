//
//  Loops.h
//  121 Review
//
//  Created by Kyle Parker on 10/7/23.
//

#ifndef Loops_h
#define Loops_h

#include <math.h>

inline int for1100(void) {
	/// Write code that will sum every number from 1 to 100 using a FOR LOOP
	return (int)NAN;
}

inline int while1100(void) {
	/// Write code that will sum every number from 1 to 100 using a WHILE LOOP
	return (int)NAN;
}

inline int dowhile1100(void) {
	/// Write code that will sum every number from 1 to 100 using a DO WHILE LOOP
	return (int)NAN;
}

inline double forRead10LinesFromFile(void) {
	/// Using a FOR loop, read 10 lines from a file called "tenLines.txt" (assume each line contains one double).
	/// Then multiply each number. (similar to the summing functions above). Take the cube root and return it.
	return NAN;
}

inline double whileRead10LinesFromFile(void) {
	/// Using a WHIILE loop, read 10 lines from a file called "tenLines.txt" (assume each line contains one double).
	/// Then multiply each number. (similar to the summing functions above). Take the cube root and return it.
	return NAN;
}

inline unsigned int forToWhileEasy(void) {
	/// Convert the following for loop:
	/// `unsigned int sum = 0;
	/// `for (int i = 10; i < 200; i += 1) {
	///	`	if (i % 3 == 0) {
	///	`		sum -= 1;
	///	`		continue;
	///	`	}
	///	`	sum += i;
	///	`}
	///	`return sum
	return (unsigned int)NAN;
}

inline long int forToWhileHard(void) {
	/// Convert the following for loop:
	/// `long int sum = 0;
	/// `for (int i = 10, increment = 0; i > -5000; i += increment) {
	///	`	if (i % 3 == 0) {
	///	`		increment--;
	///	`	}
	///	`	sum += i;
	///	`}
	/// `return sum;
	return (long)NAN;
}

inline double whileToForEasy(void) {
	/// Convert the following while to a FOR. Use initalizer, condition, and increment arguments. One
	/// or more variables may be initalized and defined ouside the for loop.
	/// `double divisor = 1;
	/// `double next = 1.26765060023e+30;
	/// `while (next != 0) {
	/// `	divisor /= next;
	/// `   next = sqrt(next);
	/// `}
	/// `return divisor;
	
	return NAN;
}

inline double whileToForHard(void) {
	/// Convert the following while to a FOR. Use initalizer, condition, and increment arguments. One
	/// or more variables may be initalized and defined ouside the for loop. Merge the inner if statement
	/// into the for statement.
	///
	///	`double something = 10;
	/// `int x = 0;
	/// `while (x < 1000) {
	/// `	if (x > 100) {
	/// `		something += cbrt(x);
	/// `	}
	/// `	++x;
	/// `}
	/// `return something;
	///
	
	return NAN;
}

#endif /* Loops_h */
