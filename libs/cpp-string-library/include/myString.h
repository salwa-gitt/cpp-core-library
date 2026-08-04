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
        MyString(const String& cpyStr);

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
};