#include <cassert>
#include <iostream>
#include "string.hpp"

int main() {
    String s1;
    assert(s1 == "");
    assert(s1[0] == '\0');
    
    
    
    std::cout<<"Default constructor test passed"<<std::endl;
    
    return 0;
}
