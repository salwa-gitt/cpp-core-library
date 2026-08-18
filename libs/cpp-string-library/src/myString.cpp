#include <string.h>
#include "../include/myString.h"
#include <iostream>

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
    std::cout << ">>> COPY ASSIGNMENT CALLED <<<\n";
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

MyString& MyString::operator=(MyString&& other)
{
    std::cout << ">>> MOVE ASSIGNMENT CALLED <<<\n";
    // checking if we are trying to move the obj to itself
    // if so do nothing
    if (this == &other)
    {
        return *this;
    }

    // B might have old memory do something to prevent memory leak so we are clearing it 
    clear();
    
    // move Data, Size, Capacity of A to B directly even the memory address
    str = other.str;
    len = other.len;

    // free memory of A so when destructor is called it will do nothing to the data
    other.str = nullptr;
    other.len = 0;

    return *this;

}

// non-const operator[] so i can assing a new char at a specific index
char& MyString::operator[](size_t indx)
{
    return str[indx];
}