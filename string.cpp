#include "string.hpp"
#include <cassert>

String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
    
}
String::~String() {
    if(str != nullptr)
        delete[] str;
}
String::String(int size) {
    stringSize = size + 1;

    str = new char[stringSize];
    for(int i = 0; i < stringSize; i++)
        str[i] = 0;
}

String::String(char ch) {
  
    stringSize = 2;
    assert(stringSize == 2);
    
    str = new char[stringSize];
    
    str[0] = ch;
    str[1] = 0;
}
String::String(const char s[]) {
    stringSize = 0;
    
    while(s[stringSize] != 0) {
        ++stringSize;
    }
    //for null character
    ++stringSize;
    str = new char[stringSize];
    
    for(int i = 0; i < stringSize; ++i)
        str[i] = s[i];
    
    
    str[stringSize] = 0;    //last index
}
//copy constructor
String::String(const String& actual) {
    stringSize = actual.stringSize;
    str = new char[stringSize];
    
    for(int i = 0; i < stringSize; ++i)
        str[i] = actual.str[i];
}
void String::swap(String& strg) {
    char* temp = str;
    str = strg.str;
    strg.str = temp;
    
    int tmp = stringSize;
    stringSize = strg.stringSize;
    strg.stringSize = tmp;
    
}
String& String::operator=(String rhs) {
    swap(rhs);
    
    return *this;
}

void String:: resetCapacity(int size) {
    char *temp = new char[size + 1];
    int smaller = stringSize;
    if((size + 1) < smaller) smaller = size + 1;
    for(int i = 0; i < smaller - 1; i++) {
        temp[i] = str[i];
    }
    delete[] str;
    str = temp;
    stringSize = size + 1;
    
}
//concatenation
String& String::operator+= (const String& rhs) {
    //set capacity = length of both combined + 1 for null terminator
    int offset = length();
    int i = 0;
    resetCapacity(length() + rhs.length());
    
    while(rhs.str[i] != 0) {
        str[offset + i] = rhs.str[i];
        i++;
    }
    str[offset + i] = 0;
    return *this;
}

String String::operator+(const String& rhs) const {

    String result(length() + rhs.length());
    
    int i = 0;
    //copys chars from lhs
    while(str[i] != 0) {
        result.str[i] = str[i];
        i++;
    }
    //copys chars from rhs
    while(rhs.str[i - length()] != 0) {
        result.str[i] = rhs.str[i - length()];
        i++;
    }
    result.str[i] = 0;
    return result;
}


String operator+(char lhs,const String& rhs) {return String(lhs) + rhs; }
String operator+(const char lhs[], const String& rhs) {return String(lhs) + rhs; }

//Relational operators
bool String::operator==(const String& rhs) const {
    if (stringSize != rhs.stringSize) {
        return false;
    }
    
    for (int i = 0; i < stringSize; ++i) {
        if (str[i] != rhs.str[i]) {
            return false;
        }
    }
    
    return true;
}
bool String::operator<(const String& rhs) const {
    int i = 0;
    while((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    
    return str[i] < rhs.str[i];
}
bool operator ==(char lhs, const String& rhs) { return String(lhs) == rhs; }
bool operator ==(const char lhs[], const String& rhs) { return String(lhs) == rhs; }
bool operator <(char lhs, const String& rhs) { return String(lhs) == rhs; }
bool operator <(const char lhs[], const String& rhs) { return String(lhs) == rhs; }

bool operator!= (const String& lhs, const String& rhs) {return !(lhs == rhs); }
bool operator>= (const String& lhs, const String& rhs) {return !(lhs < rhs); }
bool operator<= (const String& lhs, const String& rhs) {return lhs < rhs || lhs == rhs; }
bool operator> (const String& lhs, const String& rhs) {return !(lhs <= rhs); }

//Requires: 0 <= i <length()
//Getter/Accessor
char String::operator[] (int i) const {
    assert(0 <= i);
    assert(i <= length());
    //if(i < 0) return str[0];
    // if(i >= length()) return str[length];
    return str[i];
}
//Requires: 0 <= i < length()
//Setter /Modifier
char& String::operator[] (int i) {
    assert(0 <= i);
    assert(i <= length());
    
    return str[i];
}
int String::capacity() const { return stringSize - 1; }

//Ensures: RetVal = i where (str[i] == 0)
int String::length() const {
    int result = 0;
    while(str[result] != 0) ++result;
    
    return result;
    
}
//Requires: 0 <= start < length() && 0 <= end < length() && start <= end
//Ensures: RetVal == str[start, ...,end]
String String::substr(int start, int end) const {
    if(start < 0) start = 0;
    if(start > end) return String();
    if(start >= length()) return String();
    
    int substrCapacity = end - start + 1;
    String result(substrCapacity);
    int i = start;
    while(i <= end && str[i] != 0) {
        result.str[i - start] = str[i];
        i++;
    }
    
    result.str[i - start] = 0;
    return result;
}
int String::findch(int pos, char ch) const {
    int i = pos;
    
    for(; i < length(); ++i) {
        if(str[i] == ch)
            return i;
    }
    return -1;
}
int String::findstr(int pos, const String& strg) const {
    
    int subLen = strg.length();
    int searchLen = length() - subLen;
    
    if(pos > length() || pos < 0) return -1;
    
    for(int i = pos; i <= searchLen; i++)
        if(substr(i, i + subLen - 1) == strg) return i;
    
    return -1;
}
//Output
//print out null terminating char array
//Need to be friend function to access variable str
std::ostream& operator<<(std::ostream& out, const String& rhs) {
    
    for(int i = 0; i < rhs.length(); ++i) {
        out<< rhs.str[i];
    }
    return out;
}
//Input
std::istream& operator>>(std::istream& in, String& rhs) {
    char buf[rhs.capacity() + 1];
    if(!in.eof()) {
        in>> buf;
        
    }
    rhs = String(buf);
    return in;
}
