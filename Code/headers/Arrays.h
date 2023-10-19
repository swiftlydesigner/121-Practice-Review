//
//  Arrays.h
//  121 Review
//
//  Created by Kyle Parker on 10/19/23.
//

#ifndef Arrays_h
#define Arrays_h

#include <math.h>

struct findMaxArrayReturn {
	int value;
	int index;
};

inline int fixSumArray(int * myArr, size_t count) {
	/// Fix this function to properly sum the input array.
	/// Reduce the amount of variables we use - do not delcare more vars. Decrement count (as given) then
	/// figure out why we do not sum it properly.
	/// Challenge: Only modify the line with `for (; count > 0 ; --count)`
	/// If you need a hint, use a base64 decoder for the following (Linux/macOS: `echo "<MSG>" | base64 -d`).
	///
	/// SElOVDogV2UgYXJlIGN1cnJlbnRseSByZWFkaW5nIG91dHNpZGUgb2YgdGhlIGJvdW5kcy4KCUZp
	/// Z3VyZSBvdXQgaG93IHRvIHJlYWQgdGhlIGFycmF5IGZyb20gMC4uPFNJWkUuCglGb3IgYW4gYXJy
	/// YXkgb2Ygc2l6ZSAxMCwgd2UgY2FuIHJlYWQgdGhlIGFycmF5IGF0IGluZGljaWVzIDAuLi45Lgo=

	int sum = 0;
	
	for (; count > 0 ; --count) {
		sum += myArr[count];
	}
	
	return sum;
}

inline int fixMinArrayHard(int * myArr, size_t count) {
	/// Fix this code to find the min of the given array. Find the min value.
	/// Do not modify the signature of the given function.
	
	double minVal = 0;
	
	for (size_t index = 0; count <= index ; ++index) {
		minVal += fmin(-*(myArr - count), minVal);
	}
	
	return (unsigned int)minVal;
}

inline findMaxArrayReturn * findMaxArray(int * myArr, size_t size) {
	/// Find the max element and return a structure of type findMaxArrayReturn.
	/// Use malloc to allocate space so we can return the value. HINT: Use `sizeof()`
	/// Important Note: see findMaxArrayReturn at the top of this file.
	
	struct findMaxArrayReturn * returnVal = NULL;
	
	
	
	return returnVal;
}

#endif /* Arrays_h */
