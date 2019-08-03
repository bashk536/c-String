#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    
    {
    
    String s1("Hello");
    
    assert(s1 == "Hello");
    
    std::cout<< "Hello == " << s1 << std::endl;
    }
    {
        String s2("a");
        
        assert(s2 == "a");
        
        std::cout<< "a == " << s2 << std::endl;
    }
    {
        String s3("Hello, My name is Bash");
        
        assert(s3 == "Hello, My name is Bash");
        
        std::cout<< "Hello, My name is Bash == " << s3 << std::endl;
    }
    
    std::cout<<"Done testing test_charArray()" << std::endl;
}

