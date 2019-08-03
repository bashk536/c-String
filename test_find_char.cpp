#include "string.hpp"
#include <cassert>


int main ()
{
    
     {
     // Setup
     String str1;
     // Test & Verify
     assert(str1 == "");
     assert(str1.findch(0, 'a') == -1);
     }
    
     {
     // Setup
     String str1 = "This is a test";
     // Test & Verify
     assert(str1 == "This is a test");
     assert(str1.findch(10, 't') == 10);
     assert(str1.findch(0, 'T') == 0);
     assert(str1.findch(0, 'z') == -1);
     }

    std::cout<<"Done testing findch()"<<std::endl;
}
