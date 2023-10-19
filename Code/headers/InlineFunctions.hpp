/// clears the screen using a macro defined per OS for cross platform compatability.
///
/// - Precondition: Screen needs to be cleared
/// - Postcondition: Screen is cleared
/// - Warning: Any information printed prior to this call may not be accessable.
/// - version: 1.0
inline void clearScreen(void) {
	system(CLEAR_SCREEN);
}

/// wait for return, wait on user
///
/// - Precondition: prompt or end of activity
/// - Postcondition: user pressed return/return
/// - Parameter shouldClear: boolean indicating if getLine should be called before prompt, so it does not return without waiting. By default, false.
/// - version: 1.1
inline void waitForReturn(bool shouldClear = false) {
	string wait;
	if (shouldClear) { getline(cin, wait); }
	cout << endl << "[PRESS " << RETURN_KEY_UPPER << " TO CONTINUE]" << endl;
	getline(cin, wait);
}

inline void printBreak(short mode = 0) {
	switch (mode) {
		case 0:
			cout << "---------------------" << endl;
			break;
		case 1:
			cout << "------" << endl;
			break;
		default:
			break;
	}
}

/// Print either pass or fail
///
/// - Parameter ex: Expected Value
/// - Parameter ac: Actual Value
/// - Date: October 10, 2023
///
/// - Version: 1.0
template <class TYPE>
inline void printPassFail(TYPE ex, TYPE ac, string prefix = "") {
	if (ex == ac) {
		cout << prefix << "PASS!" << endl;
	} else {
		cout << prefix << "FAIL! EXPECTED " << ex << " BUT GOT " << ac << "." << endl;
	}
}

/// Internal Failure
///
/// - Parameter ex: Expected Value
/// - Parameter ac: Actual Value
/// - Date: October 19, 2023
///
/// - Version: 1.0
inline void printInternalFailure(string input) {
	cout << "INTERNAL FAILURE! TRY RUNNING IT AGAIN. CONTACT REPO HOST IF THIS PROBLEM CONSISTS. Error: " << input;
}
