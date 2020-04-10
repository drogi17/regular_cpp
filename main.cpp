#include <iostream>
#include "include/regular.h"

using std::endl;
using std::cout;
using std::cin;

void regular_show(regular &reg, int num){
	cout << "regular: " << num << endl;
	reg.view();
}

void print_regular(regular &reg){
    reg.view();
    reg.add(1312);
}

int main() {
    regular reg, reg1;
    cout << "Add: " << endl;
    reg.add(1).add(4).add(10).add(228).add_to_start(121).add_to_start(121).add_to_start(414123);
    for (int i = 0; i < 10; i++){
        reg.add(9-i);
    }
    regular_show(reg, 1);
    cout << endl << endl;
    cout << "Sort: " << endl;
    regular_show(reg, 1);
    reg.sort();
    regular_show(reg, 1);
    // regular_show(reg1, 2);
    cout << endl << endl;
    cout << "Operator (=): " << endl;
    reg1 = reg;
    regular_show(reg, 1);
    regular_show(reg1, 2);
    cout << endl << endl;
    cout << "clear: " << endl;
    regular_show(reg1, 2);
    reg1.clear();
    regular_show(reg1, 2);
    reg1.add(1).add(4).add(10).add(228).view();
    cout << endl << endl;
    cout << "len1: " << reg.len() <<endl;
    cout << "len2: " << reg1.len() <<endl;
    cout << "get: " << reg.get(3) <<endl;
    cout << endl << endl;
    cout << "remove: " << endl;
    reg.remove(3);
    cout << "get: " << reg[3] <<endl;
    reg[3] = 10;
    cout << "get: " << reg[3] <<endl;
    reg += 228;
    reg.view();
    return 0;
}
