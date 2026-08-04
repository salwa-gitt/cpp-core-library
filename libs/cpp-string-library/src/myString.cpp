#include <string.h>
#include "../include/myString.h"

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
        len = strlen(cStr);
        str = new char[len + 1];
        strcpy(str, cStr);
    }
}

// copy constructor
MyString::MyString(const MyString& cpyStr)
{
    
    len = cpyStr.length();
    str = new char[len + 1];
    strcpy(str, cpyStr.cStr());
    
}

// destructor for chars
MyString::~MyString()
{
    delete[] str;
}


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

//Copy assignment operator
MyString& MyString::operator=(const MyString& other)
{
    // Protect against self-assignment (e.g., str = str)
    if (this == &other)
    {
        return *this;
    }

    clear();
    len = other.length();
    str = new char[len + 1];
    strcpy(this->str, other.cStr());

    return *this;
}

