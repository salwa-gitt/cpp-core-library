#pragma once
#include <string>

// string class that will stores characters and prevent memory leakage
class String
{
    private:
        char* str;
        size_t len;

    public:

        // default constructor
        String();

        // constructor from c-string
        String(const char* cStr);

        // copy constructor
        String(const String& cpyStr);

        // destructor for chars
        ~String();

};