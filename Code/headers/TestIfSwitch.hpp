//
//  TestIfSwitch.hpp
//  121 Review
//
//  Created by Kyle Parker on 10/8/23.
//

#ifndef TestIfSwitch_hpp
#define TestIfSwitch_hpp

void testAllIfSwitch(void);

void testIfStatements(void);
void testIfStatements010(void);
void testIfStatements1020(void);
void testIfStatements2030(void);
void testIfStatements3040(void);
void testIfStatements4050(void);
void testIfStatements5060(void);
void testIfStatements6070(void);
void testIfStatements7080(void);
void testIfStatements8090(void);
void testIfStatements90100(void);
void testIfStatements101(void);

void testSwitchStatements(void);


inline OptionFuncPair* getTestIfSwitchPairs(void) {
	OptionFuncPair* ifSwitch = new OptionFuncPair();
	if (!ifSwitch) return ifSwitch;
	
	ifSwitch->insert(std::make_pair<string, void*>("All", (void*)(&testAllIfSwitch)));
	ifSwitch->insert(std::make_pair<string, void*>("[IF] testIfStatements", (void*)(&testIfStatements)));
	
	ifSwitch->insert(std::make_pair<string, void*>("[SWITCH] testSwitchStatements", (void*)(&testSwitchStatements)));
	
	return ifSwitch;
}

inline void testAllIfSwitch(void) {
	cout << "Testing all If and Switch statements!" << endl;
	testIfStatements();
	cout << "Finsihed testing!" << endl;
}


inline void testIfStatements(void) {
	testIfStatements010();
	testIfStatements1020();
	testIfStatements3040();
	testIfStatements5060();
	testIfStatements7080();
	testIfStatements90100();
	testIfStatements101();
}

inline void testIfStatements010(void) {
	printBreak(0);
	for (int iteration = 0; iteration <= 10; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(1, ifStatements(iteration));
	}
}

inline void testIfStatements1020(void) {
	printBreak(0);
	for (int iteration = 11; iteration <= 20; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(2, ifStatements(iteration));
	}
}

inline void testIfStatements2030(void) {
	printBreak(0);
	for (int iteration = 21; iteration <= 30; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(3, ifStatements(iteration));
	}
}

inline void testIfStatements3040(void) {
	printBreak(0);
	for (int iteration = 31; iteration <= 40; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(4, ifStatements(iteration));
	}
}

inline void testIfStatements4050(void) {
	printBreak(0);
	for (int iteration = 41; iteration <= 50; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(5, ifStatements(iteration));
	}
}

inline void testIfStatements5060(void) {
	printBreak(0);
	for (int iteration = 51; iteration <= 60; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(6, ifStatements(iteration));
	}
}

inline void testIfStatements6070(void) {
	printBreak(0);
	for (int iteration = 51; iteration <= 60; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(7, ifStatements(iteration));
	}
}

inline void testIfStatements7080(void) {
	printBreak(0);
	for (int iteration = 71; iteration <= 80; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(8, ifStatements(iteration));
	}
}

inline void testIfStatements8090(void) {
	printBreak(0);
	for (int iteration = 81; iteration <= 90; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(9, ifStatements(iteration));
	}
}

inline void testIfStatements90100(void) {
	printBreak(0);
	for (int iteration = 91; iteration <= 100; iteration += 1) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(10, ifStatements(iteration));
	}
}

inline void testIfStatements101(void) {
	printBreak(0);
	for (int iteration = 101; iteration <= 200; iteration += 25) {
		cout << "Testing ifStatements(" << iteration << ")..." << endl;
		printPassFail<int>(iteration, ifStatements(iteration));
	}
}


inline void testSwitchStatements(void) {
	string answers[10] = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
	};
	
	int input = 1;
	for ( auto answer : answers ) {
		printPassFail<string>(answers[input], switchStatements(input));
		++input;
	}
}

#endif /* TestIfSwitch_hpp */
