#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
   
    {
        String s1("a");
        assert(s1[0] == 'a');
        assert(s1 == "a");
        
    }
    {
        String s1("-a");
        assert(s1 == "-a");
        assert(s1[1] == 'a');
    }
    {
        String s1("abcdefghijklmnopqrstuvwxyz");
        assert(s1 == "abcdefghijklmnopqrstuvwxyz");
        assert(s1[25] == 'z');
        assert(s1.capacity() == 26);
    }
    
    std::cout<<"Done testing test_ctor_char() constructor"<< std::endl;
}

