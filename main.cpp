#include <iostream>
#include "include/regular.h"

using std::endl;
using std::cout;
using std::cin;


int main() {
    regular reg, reg1;
    reg1.add(1).add(4).add(10).add(228).add_to_start(121).add_to_start(121).add_to_start(414123);
    reg1.view();
    // reg1;
    reg1.view();
    cout << reg1[0];
    reg1.view();
    for (int i = 0; i < 10; i++){
        reg.add(9-i);
    }
    reg1.view();
    reg.view();
    reg1 = reg;
    reg1.view();
    reg1.clear();
    reg1.add(1).add(4).add(10).add(228).view();
    reg.view();
    reg.sort();
    reg.view();
    cout << "len1: " << reg.len() <<endl;
    cout << "len2: " << reg1.len() <<endl;
    cout << "get: " << reg.get(3) <<endl;
    reg.remove(3);
    cout << "get: " << reg[3] <<endl;
    reg[3] = 10;
    cout << "get: " << reg[3] <<endl;
    reg += 228;
    reg.view();
    return 0;
}
