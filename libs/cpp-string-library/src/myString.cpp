#include <string.h>
#include "../include/myString.h"
#include <iostream>
#include <stdexcept>

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

MyString& MyString::operator=(MyString&& other)
{
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

// Gets the first char
char& MyString::front()
{
    return str[0];
}

// Gets the last char
char& MyString::back()
{
    return str[length() - 1];
}

// same at the operator[] but first making sure the indx is valid
char& MyString::at(size_t indx)
{
    if (indx >= length())
    {
        throw std::out_of_range("Index out of bounds!");
    }
    else
    {
        return str[indx];
    }
}

// const operator[] so i can assing a new char at a specific index
const char& MyString::operator[](size_t indx) const
{
    return str[indx];
}

// const func for getting the first char
const char& MyString::front() const
{
    return str[0];
}

// const func for getting the last char
const char& MyString::back() const
{
    return str[length() - 1];
}

// const version of at()
const char& MyString::at(size_t indx) const
{
    if (indx >= length())
    {
        throw std::out_of_range("Index out of bounds!");
    }
    else
    {
        return str[indx];
    }
}


bool operator==(const MyString& lhs, const MyString& rhs)
{
    if (lhs.length() != rhs.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < lhs.length(); i++)
        {
            if (lhs.str[i] != rhs.str[i])
            {
                return false;
            }
        }

        return true;
    }
}


bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyString& lhs, const MyString& rhs)
{

    // Find the length of the shorter string
    int shorterLength = (lhs.length() < rhs.length()) ? lhs.length() : rhs.length();

    // Compare characters at the same position
    for (int i = 0; i < shorterLength; i++)
    {
        if (lhs.str[i] != rhs.str[i])
        {
            // If characters are different, we already know the answer
            return lhs.str[i] < rhs.str[i];
        }
    }

    // If no characters were different, compare the string lengths
    return lhs.length() < rhs.length();
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return rhs < lhs;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs < rhs);
}


MyString& MyString::append(const MyString& other)
{
    int totalLen = this->length() + other.length();
    char* newStr = new char[totalLen + 1];

    strcpy(newStr, this->str);
    strcat(newStr, other.str);
    
    
    delete[] this->str;

    this->str = newStr;
    this->len = totalLen;
    return *this;

}

MyString& MyString::operator+=(const MyString& other)
{
    this->append(other);
    return *this;
}


MyString MyString::operator+(const MyString& other) const
{
    MyString temp;

    temp = *this;
    temp += other;
    return temp;
}