#pragma once
#include <string>

// string class that will stores characters and prevent memory leakage
class MyString
{
    private:
        char* str;
        size_t len;

    public:

        // default constructor
        MyString();

        // constructor from c-string
        MyString(const char* cStr);

        // copy constructor
        MyString(const MyString& cpyStr);

        // destructor for chars
        ~MyString();

        // finding the length of a string
        size_t length() const;

        // finding if the string is empty or not
        bool empty() const;

        // Returns a read-only C-style string pointer (const char*).
        const char* cStr() const;

        // Deletes the string and Returns an empty string instead
        void clear();

        // Copy assignment operator
        MyString& operator=(const MyString& other);

        // move assignment operator (it will move the data from A to B and A will be empty)
        MyString& operator=(MyString&& other);

        // non-const operator[] so i can assing a new char at a specific index
        char& operator[](size_t indx);

        // Gets the first char
        char& front();

        // Gets teh last char
        char& back();

        // it will varify if the indx is valid before returning it's char
        char& at(size_t indx);

        // const operator[] so i can assing a new char at a specific index
        const char& operator[](size_t indx) const;

        // const func to get the first char
        const char& front() const;

        // const func to get the last char
        const char& back() const;

        // a const version of at()
        const char& at(size_t indx) const;
        
};