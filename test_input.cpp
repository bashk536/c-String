#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("data.txt");
    if(!in) {
        std::cerr << "Could not open data.txt, exiting." << std::endl;
        return 1;
    }
    String s1;
    in >> s1;
    assert(s1 == "Hello");
    in >> s1;
    assert(s1 == "Hola");
    while(!in.eof()) {
        in >> s1;
    }
    std::cout << "Done testing input operator"<< std::endl;
    in.close();
    
}
