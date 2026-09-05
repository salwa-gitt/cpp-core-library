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

void MyString::push_back(char c)
{
    str[len] = c;
    str[len+1] = '\0';
    len += 1;
}

void MyString::pop_back()
{
    if (len == 0)
    {
        return;
    }
    str[len - 1] = '\0';
    len -= 1; 
}

MyString& MyString::insert(size_t indx, const MyString& other)
{
    if (indx > length())
    {
        return *this;
    }
    size_t shift_len = other.length();

    // calculate new length
    size_t new_length = length() + shift_len;

    // preserver old length
    size_t old_length = length();

    // save a copy of other
    MyString savedOther(other);

    // allocate new buffer
    char* new_str = new char[new_length + 1];

    // putt old str into the new buffer
    strcpy(new_str, str);
    delete[] str;
    str = new_str;
    len = new_length;

    // shift char backwards
    for (int i = static_cast<int>(old_length); i >= static_cast<int>(indx); i--)
    {
        str[i + shift_len] = str[i];
    }

    // copy savedOther into the gap
    for ( int i = indx; i < (shift_len + indx); i++)
    {
        str[i] = savedOther.str[i - indx];
    }
    
    return *this;

}

// making erase func but it still works the same as the insert fun but in opposite i think
MyString& MyString::erase(size_t indx, size_t count)
{

    if (indx > length() || (indx + count) > length() || count == 0)
    {
        return *this;
    }

    // calculate new length
    size_t new_length = length() - count;


    for (int i = indx; i + count <= length(); i++)
    {
        str[i] = str[i+count];
    }

    len = new_length;

    return *this;

}
