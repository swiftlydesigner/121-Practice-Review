//
//  main.c
//  Sample Three File Format
//
//  Created by Kyle Parker on 1/7/24.
//

#include "myio.h"

/// The two acceptable arguments for main are `void` and
/// `int argc, const char * argv[]`.
/// Anything else will prevent your program from compiling and losing significant points.
int main(int argc, const char * argv[]) {
    int x, y, z, result;
    
    printHelloWorld();
    
    x = getIntFromUser();
    y = getIntFromUser();
    z = getIntFromUser();
    
    result = x + y + z;
    
    printResult(result);
    
    return 0;
}
