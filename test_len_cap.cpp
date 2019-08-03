#include "string.hpp"
#include <cassert>
#include <iostream>


int main ()
{
    {
        
        // TEST
        String str;
        
        // VERIFY
        assert(str.length() == 0);
    }
    
    {
        // Setup
        String str('a');
        
        // Verify
        assert(str.length() == 1);
    }
    
    {
        // Setup
        String str("a");
        
        // Verify
        assert(str.length() == 1);
    }
    
    {
        // Test
        String str("There is 22 chars here");
        
        // Verify
        assert(str.length() == 22);
    }
    std::cout<<"Done testing test_len_cap() constructor"<<std::endl;
}
