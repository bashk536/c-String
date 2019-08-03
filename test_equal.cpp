#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
    String s1("Hi");
    String s2("Hi");
    
    assert(s1 == s2);
    }
    {
        String s1("Lets see if this equals out");
        String s2("Lets see if this equals out");
        
        assert(s1 == s2);
    }
    {
        String s1("This can't be equal");
        String s2("This can't be eqqual");
        
        assert(!(s1 == s2));
    }
    
    std::cout<< "Done testing = operator"<< std::endl;
    
}
