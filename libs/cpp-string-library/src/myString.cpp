#include <string.h>
#include "myString.h"

// default constructor
MyString::MyString()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
}

// constructor from c-string
MyString::MyString(const char* cStr)
{
    if (cStr == nullptr)
    {
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        len = std::strlen(cStr);
        str = new char[len + 1];
        std::strcpy(str, cStr);
    }
}

// copy constructor
MyString::MyString(const MyString& cpyStr)
{
    
    len = cpyStr.len;
    str = new char[len + 1];
    std::strcpy(str, cpyStr.str);
    
}

// destructor for chars
MyString::~MyString()
{
    delete[] str;
}


/*
functions to implement
length()
empty()
c_str() ?? idk about this one
clear()
*/
// returning the size of the string
size_t MyString::length() const
{
    return len;
}

// checking out if the string is empty or not
bool MyString::empty() const
{
    return len == 0;
}

// Returns a read-only C-style string pointer (const char*).
const char* MyString::cStr() const
{
    return str ? str : "";
}

// Deletes the string and Returns an empty string instead
void MyString::clear()
{
    delete[] str;
    str = new char[1];
    str[0] = '\0';
    len = 0;
}