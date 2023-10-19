//
//  Pointers.h
//  121 Review
//
//  Created by main on 10/8/23.
//

#ifndef Pointers_h
#define Pointers_h

struct list {
	int value;
	int index;
	struct list * next;
};

void simplePointer(int input, int * output) {
	/// Simply set the ouput to the input.
}

void easyPointer(int input, int * output) {
	/// Set the ouput to the input.
	/// Then, modify the output by adding 34.
}

void moderatePointer(int input, double * output) {
	/// get the squreroot of input and set it to ouput.
	/// If there is a problem, set output to -1.
	/// Add the input to the ouput.
}

void difficultPointer(struct list ** pHead) {
	/// Search for the LAST occurence of List.value = 43.
	/// Set pHead to that object. Ignore index field.
	/// Create helper functions as needed.
	///
	
}

#endif /* Pointers_h */
