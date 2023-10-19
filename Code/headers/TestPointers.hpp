//
//  TestPointers.h
//  121 Review
//
//  Created by Kyle Parker on 10/19/23.
//

#ifndef TestPointers_h
#define TestPointers_h

void testAllPointers(void);

void testSimplePointer(void);
void testEasyPointer(void);
void testModeratePointer(void);
void testDifficultPointer(void);

inline OptionFuncPair* getTestPointersPairs(void) {
	OptionFuncPair* pointers = new OptionFuncPair();
	if (!pointers) return pointers;
	
	pointers->insert(std::make_pair<string, void*>("All Pointers", (void*)(&testAllPointers)));
	pointers->insert(std::make_pair<string, void*>("Simple Pointer", (void*)(&testSimplePointer)));
	pointers->insert(std::make_pair<string, void*>("Easy Pointer", (void*)(&testEasyPointer)));
	pointers->insert(std::make_pair<string, void*>("Moderate Pointer", (void*)(&testModeratePointer)));
	pointers->insert(std::make_pair<string, void*>("Difficult Pointer", (void*)(&testDifficultPointer)));
	
	return pointers;
}

inline void testAllPointers(void) {
	cout << "Testing all pointer functions!" << endl;
	testSimplePointer();
	testEasyPointer();
	testModeratePointer();
	testDifficultPointer();
	cout << "Finsihed testing!" << endl;
}

inline void testSimplePointer(void) {
	/// Simply set the ouput to the input.
	printBreak(0);
	
	srand((unsigned int)time(0));
	
	for (int i = 0; i < 10; ++i) {
		int input = rand();
		int output = -1;
		cout << "Testing simplePointer()... [input = " << input << ", " << i + 1 << " of 10]" << endl;
		
		simplePointer(input, &output);
		
		printPassFail<int>(input, output);
	}
	
}

inline void testEasyPointer(void) {
	printBreak(0);
	
	srand((unsigned int)time(0));
	
	for (int i = 0; i < 10; ++i) {
		int input = rand();
		int output = -1;
		cout << "Testing easyPointer()... [input = " << input << ", " << i + 1 << " of 10]" << endl;
		
		easyPointer(input, &output);
		
		printPassFail<int>(input + 34, output);
	}
}

inline void testModeratePointer(void) {
	/// get the squreroot of input and set it to ouput.
	/// If there is a problem, set output to -1.
	/// Add the input to the ouput.
	printBreak(0);
	
	srand((unsigned int)time(0));
	
	for (int i = 0; i < 10; ++i) {
		int input = rand();
		double output = -2;
		cout << "Testing moderatePointer()... [input = " << input << ", " << i + 1 << " of 12]" << endl;
		
		moderatePointer(input, &output);
		
		double expectedOutput = sqrt(input) + input;
		
		printPassFail<double>(expectedOutput, output);
	}
	
	int input = -1;
	double output = -2;
	cout << "Testing moderatePointer()... [input = " << input << ", 11 of 12]" << endl;
	
	moderatePointer(input, &output);
	
	printPassFail<double>(-1, output);
	
	input = -98765435;
	output = -2;
	cout << "Testing moderatePointer()... [input = " << input << ", 12 of 12]" << endl;
	
	moderatePointer(input, &output);
	
	printPassFail<double>(-1, output);
}

inline void deleteList(struct list * pNode) {
	if (pNode) {
		deleteList(pNode->next);
	} else {
		return;
	}
	delete pNode;
}

inline struct list * getListNode(int value) {
	struct list * pHead = new list();
	
	if (pHead) {
		static int index = 0;
		pHead->value = value;
		pHead->index = index++;
	}
	
	return pHead;
}

inline void addNodeToList(struct list ** pHead, struct list * node) {
	struct list * pCur = *pHead;
	while (pCur->next != NULL) {
		pCur = pCur->next;
	}
	pCur->next = node;
}

inline void testDifficultPointer(void) {
	printBreak(0);
	
	struct list * pHead = getListNode(124);
	
	if (pHead) {
		bool allSucceed = true;
		
		// 43 is at indicies 3, 8
		int test[10] = {21, 643, 123, 43, 342, 6, 2, 86, 43, 124};
		
		for (int i = 0; i < 10 && allSucceed; i += 1) {
			struct list * pNode = getListNode(test[i]);
			if (pNode) {
				addNodeToList(&pHead, pNode);
			} else {
				allSucceed = false;
			}
		}
		
		if (!allSucceed) {
			deleteList(pHead);
		}
		
	} else {
		printInternalFailure("MALLOC ALLOCATION FAILURE!");
		return;
	}
	
	difficultPointer(&pHead);
	
	printPassFail<int>(43, pHead->value, "Value: ");
	printPassFail<int>(8, pHead->index, "Index: ");
	
	deleteList(pHead);
}

#endif /* TestPointers_h */
