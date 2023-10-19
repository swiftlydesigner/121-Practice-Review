//
//  TestHeaders.hpp
//  121 Review
//
//  Created by main on 10/7/23.
//

#ifndef TestHeaders_h
#define TestHeaders_h

// following macros definitons were found at https://sourceforge.net/p/predef/wiki/OperatingSystems/
/* BEGIN MACROS */

#if defined(_WIN16)
#define UNSUPPORTED_OS _WIN16 // warn depictated version of Windows (Windows 16-bit env)
#elif defined(__WINDOWS__)
#define UNSUPPORTED_OS __WINDOWS__ // warn depictated version of Windows (Watcom C/C++)
#elif defined(MSDOS) || defined (__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#define UNSUPPORTED_OS MSDOS // warn MSDOS is not supported
#elif defined(macintosh) || defined(Macintosh)
#define UNSUPPORTED_OS Macintosh // warn depictated version of Mac OS (Mac OS 9)
#elif defined(_WIN32) || defined(_WIN64)
// import Windows-specific libraries as needed
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS // disable secure warnings
#endif
#define CLEAR_SCREEN "cls"
#define RETURN_KEY_UPPER "ENTER"
#define RETURN_KEY_LOWER "enter"
#elif defined(__APPLE__) || defined(__MACH__)
// import macOS-specific libraries as needed.
#define CLEAR_SCREEN "clear"
#define RETURN_KEY_UPPER "RETURN"
#define RETURN_KEY_LOWER "return"
#elif defined(__linux__) || defined(linux) || defined(__linux)
// import Linux-specific libraries as needed.
#define CLEAR_SCREEN "clear"
#define RETURN_KEY_UPPER "RETURN"
#define RETURN_KEY_LOWER "return"
#else
#define UNSUPPORTED_OS UNKNOWN // was not caught by one of the above cases.
#endif

/* END MACROS */

/* YOUR IMPLEMENTED FILES */

#include "Headers.h"

/* END YOUR IMPLEMENTED FILES */

/* LIBRARY */

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;

typedef map<string, void*> OptionFuncPair;
typedef map<string, OptionFuncPair* > ObjectPair;

/* END LIBRARY*/

#include "InlineFunctions.hpp"

#include "TestLoops.hpp"
#include "TestIfSwitch.hpp"
#include "TestPointers.hpp"
#include "TestArrays.hpp"

#include "Tests.hpp" /* Included last so it can see all test functions. */

#endif /* TestHeaders_h */
