//
//  Tests.hpp
//  121 Review
//
//  Created by Kyle Parker on 10/7/23.
//

#ifndef Tests_hpp
#define Tests_hpp

typedef void (*voidNoArg)(void);

class Tests {
public:
	Tests(void) {
#ifdef UNSUPPORTED_OS
		cout << "TERM REASON: UNSUPPORTED OS: " << UNSUPPORTED_OS << endl;
		exit(1);
#endif
		
		this->buildObjects();
	}
	
	virtual ~Tests(void) {
		if (objects) {
			for (auto obj : *objects) {
				if (obj.second)
					delete obj.second;
			}
			delete objects;
		}
	}
	
	/// Start of program, prints menu and interacts with user.
	///
	/// - Postcondition: Menu is displayed
	/// - Date: Oct 7, 2023
	///
	/// - Version: 1.0
	void enguageWithUser(void) {
		void * option;
		while (1) {
			option = nullptr;
			this->printMenu();
			option = this->getOption();
			
			if (option) {
				if ((signed int)(unsigned long int)option != -1) {;
					((voidNoArg)option)(); // Run selected test
				}
				waitForReturn(true);
			}
			clearScreen();
			cout << "Bad input!" << endl << endl;
		}
		
	}
	
private:
	/// Build all options for objects funciton.
	///
	/// - Postcondition: Object will be populated with methods
	/// - Warning: May fail if there is not enough space in heap.
	/// - Date: Oct 7, 2023
	///
	/// - Version: 1.0
	void buildObjects(void) {
		objects = new ObjectPair();
		
		OptionFuncPair* loops = getTestLoopsPairs();
		OptionFuncPair* ifSwitch = getTestIfSwitchPairs();
		OptionFuncPair* pointers = getTestPointersPairs();
		if (loops) {
			this->objects->insert(ObjectPair::value_type("Loops", loops));
			this->objects->insert(ObjectPair::value_type("If/Switch", ifSwitch));
			this->objects->insert(ObjectPair::value_type("Pointers", pointers));
		}
		
		
		
	}
	
	/// Print menu for user
	///
	/// - Postcondition: Menu is displayed
	/// - Date: Oct 7, 2023
	///
	/// - Version: 1.0
	void printMenu(void) {
		cout << "-1: Exit" << endl;
		
		int index = 0;
		for (auto obj : *objects) {
			cout << obj.first << ":" << endl;
			for (auto ele : *obj.second) {
				cout << '\t' << index++ << " : " << ele.first << endl;
			}
		}
		
		cout << "> ";
	}
	
	/// Get option from user
	///
	/// - Postcondition: Get userinput and return the option, if valid.
	/// - Returns: Returns the function pointer of the option, nullptr if invalid.
	/// - Date: Oct 7, 2023
	///
	/// - Version: 1.0
	void * getOption(void) {
		int input;
		
		cin >> input;
		
		if (input == -1) {
			return (void*)((unsigned long int)input);
		}
		
		int index = 0;
		for (auto obj : *objects) {
			for (auto ele : *obj.second) {
				if (index++ == input) {
					return ele.second;
				}
			}
		}
		
		return nullptr;
	}
	
	ObjectPair * objects;
};

#endif /* Tests_hpp */



/// <#DESCRIPTION OF FUNCTION#>
///
/// - Precondition: <#WHAT DO WE NEED TO CALL *BEFORE* CALLING?#>
/// - Postcondition: <#WHAT DO WE NEED TO KNOW *AFTER* CALLING?#>
/// - Warning: <#IS THERE SOMETHING THAT COULD GO WRONG? CRASH? PURPOSEFUL EXIT? POINTER IS POSSIBLY NULL?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Parameter <#PARAM NAME#>: <#WHY DO WE USE THIS PARAM?#>
/// - Returns: <#WHAT DOES IT RETURN?#>
/// - Seealso: <#NAME OF OTHER FUNCTION#>
/// - Date: <#UPDATE DATE#>
///
/// - Version: <#1.0#>
