#include "string.hpp"
#include <cassert>
#include <iostream>

int main ()
{
    {
        // Setup
        String s1;
        
        // Verify
        assert(s1[0] == '\0');
    }
    
    {
        // Setup
        String s1('a');
        
        // Verify
        assert(s1[0] == 'a');
    }
    
    {
        // Setup
        String s1("a");
        
        // Verify
        assert(s1[0] == 'a');
    }
    
    {
        // Setup
        String s1("My name is Bash!");
        
        // Verify
        assert(s1[0] == 'M');
        assert(s1[1] == 'y');
        assert(s1[11] == 'B');
    }
    std::cout<< "Done testing subscript operator"<< std::endl;
}
