#include "string.hpp"
#include <cassert>
#include <iostream>

int main ()
{
    {
        // Setup
        String str1 = "abcdefghijk",
        result1,
        result2,
        result3,
        result4;
        
        // Test
        result1 = str1.substr(0, 0);
        result2 = str1.substr(1, 1);
        result3 = str1.substr(0, 3);
        result4 = str1.substr(1, 10);
        
        
         // Verfiy
         assert(str1 == "abcdefghijk");
         assert(result1 == "a");
         assert(result2 == "b");
         assert(result3 == "abcd");
         assert(result4 == "bcdefghijk");
         }
         
         {
         // Setup
         String str = "Why is this class so hard?";
         // Test & Verify
         assert(str.substr(0, 2) == "Why");
         assert(str.substr(7, 10) == "this");
         assert(str.substr(25,25) == "?");
         
    }
    std::cout<< "Done testing substring method"<< std::endl;
}
