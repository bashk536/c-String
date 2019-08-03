#include <iostream>
#include "string.hpp"
#include<cassert>


int main() {
    String s1("Hello");
    String s2;
    
    s2.swap(s1);
    
    assert(s2 == "Hello");
    
    
    
    std::cout<<"Done testing swap_assign()\n";
}
