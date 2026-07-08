#include <string.h>
#include "myString.h"

// default constructor
String::String()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

// constructor from c-string
String::String(const char* cStr)
{
    if (cStr == nullptr)
    {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        len = std::strlen(cStr)
        str = new char[len + 1];
        std::strcpy(str, cStr);
    }
}

// copy constructor
String::String(const String& cpyStr)
{
    
    len = cpyStr.len;
    str = new char[len + 1];
    std::strcpy(str, cpyStr.str);
    
}

// destructor for chars
String::~String()
{
    delete[] str;
}
