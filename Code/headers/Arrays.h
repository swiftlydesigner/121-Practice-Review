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


inline long * sum2DArray(int ** twoDArray, size_t * dims) {
	/// A 2D array will consist of row A and column B. Return an array S of length len(row A).
	/// Each element in S should be the sum of the respective B column (that is, start at 0th position in A
	/// then sum all of B and that is S's 0th value; continue until you have gone over the entire array.)
	/// dims[0] = A's length, dims[1] = B's length. Use malloc as needed.
	
	return NULL;
}


inline long sum2DFlattenArray(int ** twoDArray, size_t * dims) {
	/// Similar to `sum2DArray`, but you need to sum the array S to produce a long L rather than an array S.
	/// Use malloc as needed.
	/// If you need a hint, use a base64 decoder for the following (Linux/macOS: `echo "<MSG>" | base64 -d`).
	///
	/// SElOVDogSW1wbGVtZW50IGBzdW0yREFycmF5YCB0aGVuIGNhbGwgdGhhdCBhbmQgc3VtIHRoZSAx
	/// RCBhcnJheS4K
	
	return NULL;
}

inline long ** sum3DArray(int *** threeDArray, size_t * dims) {
	/// `threeDArray` will consist of A (array of arrays), B (array of arrays), and C (array of ints). A consists of
	/// B which consists of C. dims[0] = len(A). dims[1] = len(B). dims[2] = len(C).
	/// A's final value will consist of an array of arrays B's Final values will be an array of ints.
	/// Use malloc as needed.
	
	return NULL;
}

inline long sum3DFlattenArray(int *** threeDArray, size_t * dims) {
	/// Similar to `sum3DArray`, but return the sum of the arrays. Use malloc as needed.
	/// If you need a hint, use a base64 decoder for the following (Linux/macOS: `echo "<MSG>" | base64 -d`).
	///
	/// SElOVDogSW1wbGVtZW50IGBzdW0yREFycmF5YCBhbmQgYHN1bTNEQXJyYXlgIHRoZW4gY2FsbCB0
	/// aGF0IGFuZCBzdW0gdGhlIDFEIGFycmF5Lgo=
	
	return NULL;
}

#endif /* Arrays_h */
