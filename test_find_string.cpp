#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    

    {
        String test = "abcd";
        assert(test.findstr(0, "abcd") == 0);
    }
    
    {
        String test = "I suck at Data Structures";
        
        {
            String find = "suck";
            assert(test.findstr(2, find) == 2);
        }
        
        {
            String find = "Data";
            assert(test.findstr(10, find) == 10);
        }
        
        {
            String find = "Str";
            assert(test.findstr(15, find) == 15);
        }
        
        {
            String find = "at";
            assert(test.findstr(7, find) == 7);
        }
    }
    
    std::cout << "Done testing the findstring method" << std::endl;
    
}
