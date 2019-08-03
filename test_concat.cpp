#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    
    String s1("");
    String s2("");
    
    assert(s1 + s2 == "");
    s1 += s2;
    assert(s1 == "");
    
    
    String s3("a");
    String s4("A");
    String s11 = s3 + s4;
    
    
    assert(s11 == "aA");
    assert(s4 + s3 == "Aa");
   
   
    String s5("A");
    String s6("A");
    
    assert(s5 + s6 == "AA");
    assert(s6 + s5 == "AA");
   
    
    String s7("ABC");
    String s8("A");
    assert(s7 + s8 == "ABCA");
    assert(s8 + s7 == "AABC");
    
    String s9("A-Z ");
    String s10("A-Z");
    assert(s9 + s10 == "A-Z A-Z");
    
    
    std::cout<<"Done testing concatenation" <<std::endl;
}

