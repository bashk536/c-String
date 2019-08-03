#include <iostream>
#include "string.hpp"
#include<cassert>


int main() {
    String s1("abcdefg");
    
    assert(s1[2] == 'c');
    assert(s1.length() == 7);
    
    std::cout<<"Done testing ctor_charArray_int()\n";
}
