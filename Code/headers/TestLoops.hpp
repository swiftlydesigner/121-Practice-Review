//
//  TestLoops.h
//  121 Review
//
//  Created by Kyle Parker on 10/7/23.
//

#ifndef TestLoops_h
#define TestLoops_h

void testAllLoops(void);

void testAllCount1100(void);
void testForCount1100(void);
void testWhileCount1100(void);
void testDoWhileCount1100(void);

void testAllFileLoops(void);
void testForRead10Lines(void);
void testWhileRead10Lines(void);

void testAllConvertLoops(void);
void testAllFor2WhileConvertLoops(void);
void testAllWhile2ForConvertLoops(void);
void testFor2WhileEasyConvertLoops(void);
void testFor2WhileHardConvertLoops(void);
void testWhile2ForEasyConvertLoops(void);
void testWhile2ForHardConvertLoops(void);


inline OptionFuncPair* getTestLoopsPairs(void) {
	OptionFuncPair* loops = new OptionFuncPair();
	if (!loops) return loops;
	
	loops->insert(std::make_pair<string, void*>("All", (void*)(&testAllLoops)));
	loops->insert(std::make_pair<string, void*>("[All] Range 1-100", (void*)(&testAllCount1100)));
	loops->insert(std::make_pair<string, void*>("[FOR] Range 1-100", (void*)(&testForCount1100)));
	loops->insert(std::make_pair<string, void*>("[WHILE] Range 1-100", (void*)(&testWhileCount1100)));
	loops->insert(std::make_pair<string, void*>("[DO WHILE] Range 1-100", (void*)(&testDoWhileCount1100)));
	
	loops->insert(std::make_pair<string, void*>("[All] File-based Loops", (void*)(&testAllFileLoops)));
	loops->insert(std::make_pair<string, void*>("[FOR] Read 10 Lines From a File", (void*)(&testForRead10Lines)));
	loops->insert(std::make_pair<string, void*>("[WHILE] Read 10 Lines From a File", (void*)(&testWhileRead10Lines)));
	
	loops->insert(std::make_pair<string, void*>("[All] for-to-while and while-to-for Loops", (void*)(&testAllConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[FOR2WHILE] for-to-while Loops", (void*)(&testAllFor2WhileConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[All] while-to-for Loops", (void*)(&testAllWhile2ForConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[FOR2WHILE] for-to-while EASY", (void*)(&testFor2WhileEasyConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[FOR2WHILE] for-to-while HARD", (void*)(&testFor2WhileHardConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[WHILE2WHILE] while-to-for EASY", (void*)(&testWhile2ForEasyConvertLoops)));
	loops->insert(std::make_pair<string, void*>("[WHILE2WHILE] while-to-for HARD", (void*)(&testWhile2ForHardConvertLoops)));
	
	return loops;
}

inline void testAllLoops(void) {
	cout << "Testing all loops!" << endl;
	testAllCount1100();
	testAllFileLoops();
	testAllConvertLoops();
	cout << "Finsihed testing!" << endl;
}

inline void testAllCount1100(void) {
	printBreak(0);
	cout << "Testing all functions summing from 1 to 100" << endl;
	testForCount1100();
	testWhileCount1100();
	testDoWhileCount1100();
}

inline void testForCount1100(void) {
	printBreak(0);
	cout << "Testing for1100()..." << endl;
	
	int sum = 0;
	for (int i = 1; i < 100; i += 1) {
		sum += i;
	}
	
	printPassFail<int>(sum, for1100());
}

inline void testWhileCount1100(void) {
	printBreak(0);
	cout << "Testing while1100()..." << endl;
	
	int sum = 0, i = 1;
	while (i < 100) {
		sum += i;
		i += 1;
	}
	
	printPassFail<int>(sum, while1100());
}

inline void testDoWhileCount1100(void) {
	printBreak(0);
	cout << "Testing dowhile1100()..." << endl;
	
	int sum = 0, i = 1;
	do {
		sum += i;
		i += 1;
	} while (i < 100);
	
	printPassFail<int>(sum, dowhile1100());
}

inline void testAllFileLoops(void) {
	printBreak(0);
	cout << "Testing all functions reading from a file" << endl;
	testForRead10Lines();
	testWhileRead10Lines();
}

inline void testForRead10Lines(void) {
	printBreak(0);
	cout << "Testing forRead10LinesFromFile()..." << endl;
	
	double product = 1, i = 2;
	do {
		product *= i;
		i *= 2;
	} while (i < 1025);
	
	product = cbrt(product);
	
	printPassFail<double>(product, forRead10LinesFromFile());
}

inline void testWhileRead10Lines(void) {
	printBreak(0);
	cout << "Testing forRead10LinesFromFile()..." << endl;
	
	double product = 1, i = 2;
	do {
		product *= i;
		i *= 2;
	} while (i < 1025);
	
	product = cbrt(product);
	
	printPassFail<double>(product, forRead10LinesFromFile());
}

inline void testAllConvertLoops(void) {
	printBreak(0);
	cout << "Testing all for2while and while2for loops..." << endl;
	testFor2WhileEasyConvertLoops();
	testFor2WhileHardConvertLoops();
	testWhile2ForEasyConvertLoops();
	testWhile2ForHardConvertLoops();
}

inline void testAllFor2WhileConvertLoops(void) {
	printBreak(0);
	cout << "Testing all for2whileloops..." << endl;
	testFor2WhileEasyConvertLoops();
	testFor2WhileHardConvertLoops();
}

inline void testAllWhile2ForConvertLoops(void) {
	printBreak(0);
	cout << "Testing all while2for loops..." << endl;
	testWhile2ForEasyConvertLoops();
	testWhile2ForHardConvertLoops();
}

inline void testFor2WhileEasyConvertLoops(void) {
	printBreak(0);
	cout << "Testing forToWhileEasy()..." << endl;
	
	unsigned int sum = 0;
	for (int i = 10; i < 200; i += 1) {
		sum += (unsigned)i;
	}
	
	printPassFail<unsigned int>(sum, forToWhileEasy());
}

inline void testFor2WhileHardConvertLoops(void) {
	printBreak(0);
	cout << "Testing forToWhileHard()..." << endl;
	
	long int sum = 0;
	for (int i = 10, increment = 0; i > -5000; i += increment) {
		if (i % 3 == 0) {
			increment--;
		}
		sum += i;
	}
	
	printPassFail<double>(sum, forToWhileHard());
}

inline void testWhile2ForEasyConvertLoops(void) {
	printBreak(0);
	cout << "Testing whileToForEasy()..." << endl;
	
	double divisor = 1;
	double next = 1.26765060023e+30;
	while (next != 0) {
		divisor /= next;
		next = sqrt(next);
	}
	
	printPassFail<double>(divisor, whileToForEasy());
}

inline void testWhile2ForHardConvertLoops(void) {
	printBreak(0);
	cout << "Testing whileToForHard()..." << endl;
	
	double something = 10;
	int x = 0;
	while (x < 1000) {
		if (x > 100) {
			something += cbrt(x);
		}
		++x;
	}
	
	printPassFail<double>(something, whileToForHard());
}

#endif /* TestLoops_h */
