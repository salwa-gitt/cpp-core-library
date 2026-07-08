#pragma once
#include <iostream>

// string class that will stores characters and prevent memory leakage
class String
{
    private:
        char* str;
        int size;

    public:

        // default constructor
        String();

        // constructor from c-string
        String(const char* c);

};