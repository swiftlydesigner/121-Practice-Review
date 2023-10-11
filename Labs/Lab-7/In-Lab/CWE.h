//
//  CWE.h
//  Debugging
//
//  Created by main on 10/10/23.
//
// All code from https://github.com/conikeec/seeve/tree/master, unless otherwise noted.
/// Comments not describing the code are from https://cwe.mitre.org/
/// https://cwe.mitre.org/top25/archive/2023/2023_top25_list.html

#ifndef CWE_h
#define CWE_h

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



/*This function attempts to extract a pair of numbers from a user-supplied string.*/
void parse_data(char *untrusted_input){
	int m, n, error;
	error = sscanf(untrusted_input,"%d:%d",&m,&n);
	if (EOF == error){
		printf("Did not specify integer value. Die evil hacker!\n");
	}
	printf("m is %d and n is %d",m,n);
}



/// CWE-20: Improper Input Validation
/**
 Input validation is a frequently-used technique for checking potentially dangerous inputs in order to ensure that the inputs are safe for processing within the code, or when communicating with other components. When software does not validate input properly, an attacker is able to craft the input in a form that is not expected by the rest of the application. This will lead to parts of the system receiving unintended input, which may result in altered control flow, arbitrary control of a resource, or arbitrary code execution.
 
 Input validation is not the only technique for processing input, however. Other techniques attempt to transform potentially-dangerous input into something safe, such as filtering (CWE-790) - which attempts to remove dangerous inputs - or encoding/escaping (CWE-116), which attempts to ensure that the input is not misinterpreted when it is included in output to another component. Other techniques exist as well (see CWE-138 for more examples.)
 
 Input validation can be applied to:
 
 raw data - strings, numbers, parameters, file contents, etc.
 metadata - information about the raw data, such as headers or size
 
 Data can be simple or structured. Structured data can be composed of many nested layers, composed of combinations of metadata and raw data, with other simple or structured data.
 
 Many properties of raw data or metadata may need to be validated upon entry into the code, such as:
 
 specified quantities such as size, length, frequency, price, rate, number of operations, time, etc.
 implied or derived quantities, such as the actual size of a file instead of a specified size
 indexes, offsets, or positions into more complex data structures
 symbolic keys or other elements into hash tables, associative arrays, etc.
 well-formedness, i.e. syntactic correctness - compliance with expected syntax
 lexical token correctness - compliance with rules for what is treated as a token
 specified or derived type - the actual type of the input (or what the input appears to be)
 consistency - between individual data elements, between raw data and metadata, between references, etc.
 conformance to domain-specific rules, e.g. business logic
 equivalence - ensuring that equivalent inputs are treated the same
 authenticity, ownership, or other attestations about the input, e.g. a cryptographic signature to prove the source of the data
 
 Implied or derived properties of data must often be calculated or inferred by the code itself. Errors in deriving properties may be considered a contributing factor to improper input validation.
 
 Note that "input validation" has very different meanings to different people, or within different classification schemes. Caution must be used when referencing this CWE entry or mapping to it. For example, some weaknesses might involve inadvertently giving control to an attacker over an input when they should not be able to provide an input at all, but sometimes this is referred to as input validation.
 
 Finally, it is important to emphasize that the distinctions between input validation and output escaping are often blurred, and developers must be careful to understand the difference, including how input validation is not always sufficient to prevent vulnerabilities, especially when less stringent data types must be supported, such as free-form text. Consider a SQL injection scenario in which a person's last name is inserted into a query. The name "O'Reilly" would likely pass the validation step since it is a common last name in the English language. However, this valid name cannot be directly inserted into the database because it contains the "'" apostrophe character, which would need to be escaped or otherwise transformed. In this case, removing the apostrophe might reduce the risk of SQL injection, but it would produce incorrect behavior because the wrong name would be recorded.
*/
void CWE20(void) {
	parse_data("123:");
}

#define MAX_SIZE 16
/// CWE-119: Improper Restriction of Operations within the Bounds of a Memory Buffer
/**
 Certain languages allow direct addressing of memory locations and do not automatically ensure that these locations are valid for the memory buffer that is being referenced. This can cause read or write operations to be performed on memory locations that may be associated with other variables, data structures, or internal program data.
 
 As a result, an attacker may be able to execute arbitrary code, alter the intended control flow, read sensitive information, or cause the system to crash.
 
 The programmer attempts to encode the ampersand character in the user-controlled string,
however the length of the string is validated before the encoding procedure is applied.
Furthermore, the programmer assumes encoding expansion will only expand a given character by a factor of 4,
while the encoding of the ampersand expands by 5. As a result,
when the encoding procedure expands the string it is possible to overflow the destination buffer if the attacker provides a string of many ampersands.*/
void CWE119(int argc, char *argv[]) {
	int i, j=0;
	char a[MAX_SIZE];
	
	/*checks if the user provided an input*/
	if (argc<2) return;
	
	/*checks if the input provided by the user fits in the array a*/
	if (MAX_SIZE <= strlen(argv[1])){
		printf("user string too long");
		return;
	}
	
	/*performs the encoding*/
	for (i=0; i < strlen(argv[1]); i++){
		if( '&' == argv[1][i] ){
			a[j++] = '&';
			a[j++] = 'a';
			a[j++] = 'm';
			a[j++] = 'p';
			a[j++] = ';';
		}
		else a[j++]=argv[1][i];
	}
	printf("The encoded string is %s \n",a);
}

/// CWE-120: Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')
/**
 A buffer overflow condition exists when a product attempts to put more data in a buffer than it can hold, or when it attempts to put data in a memory area outside of the boundaries of a buffer. The simplest type of error, and the most common cause of buffer overflows, is the "classic" case in which the product copies the buffer without restricting how much is copied. Other variants exist, but the existence of a classic overflow strongly suggests that the programmer is not considering even the most basic of security protections.
 */
void CWE120(void) {
	char last_name[20];
	printf ("Enter your last name: ");
	scanf ("%s", last_name);
}

/// CWE-125: Out-of-bounds Read
/**
 Typically, this can allow attackers to read sensitive information from other memory locations or cause a crash. A crash can occur when the code reads a variable amount of data and assumes that a sentinel exists to stop the read operation, such as a NUL in a string. The expected sentinel might not be located in the out-of-bounds memory, causing excessive data to be read, leading to a segmentation fault or a buffer overflow. The product may modify an index or perform pointer arithmetic that references a memory location that is outside of the boundaries of the buffer. A subsequent read operation then produces undefined or unexpected results.
 +
 */
void CWE125(void) {
	int a[10];
	a[10] = 0;
	
	int x;
	int y=10;
	x = a[y];
}

#define MAXLEN 1024
/// CWE-170: Improper Null Termination
/**
 Null termination errors frequently occur in two different ways. An off-by-one error could cause a null to be written out of bounds, leading to an overflow. Or, a program could use a strncpy() function call incorrectly, which prevents a null terminator from being added at all. Other scenarios are possible.
 */
void CWE170(void) {
	char *inputbuf = NULL;
	char pathbuf[MAXLEN];
	/*for some file descriptor fd*/
	read(0,inputbuf,MAXLEN); //does not null terminate
	strcpy(pathbuf,inputbuf); //requires null terminated input
}


/// CWE-190: Integer Overflow or Wraparound
/**
 An integer overflow or wraparound occurs when an integer value is incremented to a value that is too large to store in the associated representation. When this occurs, the value may wrap to become a very small or negative number. While this may be intended behavior in circumstances that rely on wrapping, it can have security consequences if the wrap is unexpected. This is especially the case if the integer overflow can be triggered using user-supplied inputs. This becomes security-critical when the result is used to control looping, make a security decision, or determine the offset or size in behaviors such as memory allocation, copying, concatenation, etc.
 */
void CWE190(void) {
	char *buf;
	int len;
	/* for some file descriptor fd*/
	read(0, &len, sizeof(len));
	/* We forgot to check for input < 0 */
	
	if (len > 8000) {return; }
	buf = malloc(len);
	read(0, buf, len); /* len casted to unsigned and overflows */
	/// Also causes memory leak CWE-401
}

/// CWE-193: Off-by-one Error (OBOE)
/**
 Offical description: A product calculates or uses an incorrect maximum or minimum value that is 1 more, or 1 less, than the correct value.
 n this example,the code does not account for the terminating null character,
 and it writes one byte beyond the end of the buffer.The first call to strncat() appends up to 20 characters
 plus a terminating null character to fullname[]. There is plenty of allocated space for this,
 and there is no weakness associated with this first call. However, the second call to strncat() potentially
 appends another 20 characters. The code does not account for the terminating null character that is automatically added by strncat().
 This terminating null character would be written one byte beyond the end of the fullname[] buffer.
 Therefore an off-by-one error exists with the second strncat() call, as the third argument should be 19.*/
void CWE193(void) {
	char firstname[20];
	char lastname[20];
	char fullname[40];
	firstname[0]='\0';
	strncat(fullname, firstname, 20);
	strncat(fullname, lastname, 20);
	return;
}

/// CWE-197: Numeric Truncation Error
/**
 When a primitive is cast to a smaller primitive, the high order bits of the large value are lost in the conversion, potentially resulting in an unexpected value that is not equal to the original value. This value may be required as an index into a buffer, a loop iterator, or simply necessary state data. In any case, the value cannot be trusted and the system will be in an undefined state. While this method may be employed viably to isolate the low bits of a value, this usage is rare, and truncation usually implies that an implementation error has occurred.
 */
void CWE197(void) {
	int intPrimitive;
	short shortPrimitive;
	intPrimitive = (int)(~((int)0) ^ (1 << (sizeof(int)*8-1)));
	shortPrimitive = intPrimitive;
	printf("Int MAXINT: %d\nShort MAXINT: %d\n", intPrimitive, shortPrimitive);
}

/// CWE-369: Divide By Zero
/**
 This weakness typically occurs when an unexpected value is provided to the product, or if an error occurs that is not properly detected. It frequently occurs in calculations involving physical dimensions such as size, length, width, and height.
 */
void CWE369(void) {
	int x;
	int a[10];
	a[0]=0;
	x=1/a[0];
}

/// Authored by Kyle Parker.
/// CWE-787: Out-of-bounds Write
/**
 Typically, this can result in corruption of data, a crash, or code execution. The product may modify an index or perform pointer arithmetic that references a memory location that is outside of the boundaries of the buffer. A subsequent write operation then produces undefined or unexpected results.
 */
void CWE787(void) {
	/// Note: My computer puts secondArray in memory before firstArray.
	int firstArray[5];
	int secondArray[5];
	/// Show the memory addresses
	printf("firstArray addr = %p\n", firstArray);
	printf("secondArray addr = %p\n", secondArray);
	/// Set first and second array values.
	for ( int i = 0; i < 20; i += 1 ) {
		secondArray[i] = i;
		if (i < 5) {
			printf("secondArray[%d] = %d\n", i, secondArray[i]);
		} else {
			printf("firstArray[%d] = %d\n", i % 5, firstArray[i % 5]);
		}
	}
	return;
}
#endif /* CWE_h */
