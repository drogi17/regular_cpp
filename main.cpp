#include <iostream>
#include "include/regular.h"

using std::endl;
using std::cout;
using std::cin;

int main() {
    regular reg, reg1;
    reg1.add(1).add(4).add(10).add(228);
    for (int i = 0; i < 10; i++){
        reg.add(9-i);
    }
    // reg.add(10).add(123).add(20).add(99).add(123).add(2).add(0).add(-123).add(2).add(-123).add(-1123123);
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
