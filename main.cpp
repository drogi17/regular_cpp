#include <iostream>
#include "include/regular.h"

using std::endl;
using std::cout;
using std::cin;


void print_regular(regular &reg){
    reg.view();
    reg.add(1312);
}

int main() {
    regular reg, reg1;
    reg.add(1).add(4).add(10).add(228).add_to_start(121).add_to_start(121).add_to_start(414123);
    for (int i = 0; i < 10; i++){
        reg.add(9-i);
    }
    reg.view();
    cout << endl << endl;
    reg.sort();
    reg.view();
    reg1.view();
    reg1.view();
    cout << reg1[0];
    reg1.view();
    reg1.view();
    cout << endl << endl;
    reg.view();
    reg1.view();
    cout << endl << endl;
    reg1 = reg;
    reg.view();
    reg1.view();
    cout << endl << endl;
    print_regular(reg1);
    reg1.view();
    reg1.clear();
    reg1.add(1).add(4).add(10).add(228).view();
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
