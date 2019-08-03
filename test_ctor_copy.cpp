#include "string.hpp"
#include <iostream>
#include <cassert>

int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String a("My name is Bash");
        String b(a);
        
        // VERIFY
        assert(a == "My name is Bash");
        assert(b == "My name is Bash");
        
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        String a("Hello Hola Namaste");
        String b = a;
        
        // VERIFY
        assert(a == "Hello Hola Namaste");
        assert(b == "Hello Hola Namaste");
        
    }
    std::cout << "Done testing copy constructor. \n";
}
