#include <iostream>
#include <string.h>
#include "myString.h"

// default constructor
String::String()
{
    str = "";
    size = 0;
}

// constructor from c-string
String::String(const char* c)
{
    str = c;
    size = strlen(c);
}

