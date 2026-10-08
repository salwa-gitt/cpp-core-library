#include <cstring>
#include <stdexcept>

#include "../include/myString.h"


// default constructor
MyString::MyString()
{
    len = 0;
    cap = 0;
    str = new char[1];
    str[0] = '\0';
}

// constructor from c-string
MyString::MyString(const char* cStr)
{
    if (cStr == nullptr)
    {
        len = 0;
        cap = 0;
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        len = std::strlen(cStr);
        cap = len;
        str = new char[cap + 1];
        std::strcpy(str, cStr);
    }
}

// copy constructor
MyString::MyString(const MyString& cpyStr)
{
    
    len = cpyStr.len;
    cap = cpyStr.cap;
    str = new char[cap + 1];
    std::strcpy(str, cpyStr.str);
    
}

// move constructor
MyString::MyString(MyString&& other)
{
    str = other.str;
    len = other.len;
    cap = other.cap;

    other.str = nullptr;
    other.len = 0;
    other.cap = 0;
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

    len = 0;
    cap = 0;

    str = new char[1];
    str[0] = '\0';
    
}

//Copy assignment operator
MyString& MyString::operator=(const MyString& other)
{
    // Protect against self-assignment (e.g., str = str)
    if (this == &other)
    {
        return *this;
    }

    char* new_str = new char[other.cap + 1];
    std::strcpy(new_str, other.str);
    delete[] str;

    str = new_str;
    len = other.len;
    cap = other.cap;
    
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

    delete[] str;
    
    str = other.str;
    len = other.len;
    cap = other.cap;

    // free memory of A so when destructor is called it will do nothing to the data
    other.str = nullptr;
    other.len = 0;
    other.cap = 0;

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
        for (size_t i = 0; i < lhs.length(); i++)
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
    if (this == &other)
    {
        MyString copy(other);
        return append(copy);
    }

    if (other.len == 0)
    {
        return *this;
    }

    size_t old_len = len;
    size_t new_len = len + other.len;

    if (new_len > cap)
    {
        size_t new_cap = cap;

        if (new_cap == 0)
        {
            new_cap = 1;
        }

        while (new_cap < new_len)
        {
            new_cap *= 2;
        }

        reserve(new_cap);
        
    }

    for (size_t i = 0; i < other.len; i++)
    {
        str[old_len + i] = other.str[i];
    }

    len = new_len;
    str[len] = '\0';
    
    return *this;

}

MyString& MyString::operator+=(const MyString& other)
{
    return append(other);
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
    if (len == cap)
    {
        size_t new_cap = (cap == 0) ? 1 : cap * 2;
        reserve(new_cap);
    }

    str[len] = c;
    len++;
    str[len] = '\0';
}

void MyString::pop_back()
{
    if (len == 0)
    {
        return;
    }

    len--;
    str[len] = '\0';
}

MyString& MyString::insert(size_t indx, const MyString& other)
{
    if (indx > len || other.len == 0)
    {
        return *this;
    }

    // Make a copy so self-insertion is safe.
    MyString copy(other);

    size_t new_len = len + copy.len;

    // Make sure there is enough space.
    if (new_len > cap)
    {
        size_t new_cap = (cap == 0) ? 1 : cap;

        while (new_cap < new_len)
        {
            new_cap *= 2;
        }

        reserve(new_cap);
    }

    // Shift the existing characters (including '\0')
    // to the right to make room.
    for (size_t i = len + 1; i > indx; --i)
    {
        str[i + copy.len - 1] = str[i - 1];
    }

    // Copy the new string into the gap.
    for (size_t i = 0; i < copy.len; ++i)
    {
        str[indx + i] = copy.str[i];
    }

    len = new_len;

    return *this;

}

// making erase func but it still works the same as the insert fun but in opposite i think
MyString& MyString::erase(size_t indx, size_t count)
{

    if (indx >= len || count == 0)
    {
        return *this;
    }

    if (count > len - indx)
    {
        count = len - indx;
    }

    for (size_t i = indx; i + count <= len; i++)
    {
        str[i] = str[i + count];
    }

    len -= count;

    return *this;

}

MyString& MyString::replace(size_t indx, size_t count, const MyString& other)
{

    if (indx > len)
    {
        return *this;
    }

    if (count > len - indx)
    {
        count = len - indx;
    }

    MyString copy(other);

    erase(indx, count);
    insert(indx, copy);

    return *this;

}

size_t MyString::find(const MyString& other, size_t pos) const
{
    // Empty string is found at pos
    if (other.len == 0)
    {
        return (pos <= len) ? pos : npos;
    }

    // Search starts beyond the possible range
    if (pos >= len)
    {
        return npos;
    }

    // Not enough characters remaining
    if (other.len > len - pos)
    {
        return npos;
    }

    for (size_t i = pos; i <= len - other.len; ++i)
    {
        bool match = true;

        for (size_t j = 0; j < other.len; ++j)
        {
            if (str[i + j] != other.str[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return i;
        }
    }

    return npos;
}

size_t MyString::rfind(const MyString& other, size_t pos) const
{
    
    if (other.len == 0)
    {
        return (pos == npos || pos > len) ? len : pos;
    }

    if (other.len > len)
    {
        return npos;
    }

    size_t start = len - other.len;

    if (pos != npos && pos < start)
    {
        start = pos;
    }

    for (size_t i = start + 1; i-- > 0;)
    {
        bool match = true;

        for (size_t j = 0; j < other.len; j++)
        {
            if (str[i + j] != other.str[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return i;
        }
    }

    return npos;

}

bool MyString::contains(const MyString& other) const
{
    return find(other) != npos;
}

bool MyString::starts_with(const MyString& other) const
{
    if (other.len > len)
    {
        return false;
    }

    for (size_t i = 0; i < other.len; i++)
    {
        if (str[i] != other.str[i])
        {
            return false;
        }
    }

    return true; 
}

bool MyString::ends_with(const MyString& other) const
{
    if (other.len > len)
    {
        return false;
    }

    size_t start = len - other.len;

    for (size_t i = 0; i < other.len; i++)
    {
        if (str[start + i] != other.str[i])
        {
            return false;
        }
    }

    return true;
}


MyString MyString::substr(size_t pos, size_t count) const
{
    if (pos > len)
    {
        throw std::out_of_range("Substring position out of bounds");
    }

    size_t available = len - pos;

    if (count == npos || count > available)
    {
        count = available;
    }

    MyString result;

    if (count == 0)
    {
        return result;
    }

    result.reserve(count);

    for (size_t i = 0; i < count; i++)
    {
        result.str[i] = str[pos + i];
    }

    result.len = count;
    result.str[count] = '\0';

    return result;
}

int MyString::compare(const MyString& other) const
{
    size_t loop_len = (len < other.len) ? len : other.len;

    if (length() < other.length())
    {
        loop_len = static_cast<int>(length());
    }
    else if (other.length() < length())
    {
        loop_len = static_cast<int>(other.length());
    }

    for (size_t i = 0; i < loop_len; i++)
    {
        if (str[i] < other.str[i])
        {
            return -1;
        }
        else if (str[i] > other.str[i])
        {
            return 1;
        }
        
    }

    if (length() < other.length())
    {
        return -1;
    }
    else if (length() > other.length())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MyString::swap(MyString& other)
{
    char* temp_str = str;

    str = other.str;
    other.str = temp_str;

    size_t temp_len = len;
    len = other.len;
    other.len = temp_len;
}

size_t MyString::capacity() const
{
    return cap;
}

void MyString::reserve(size_t new_cap)
{
    if (new_cap <= cap)
    {
        return;
    }

    char* new_str = new char[new_cap + 1];

    for (size_t i = 0; i < len; i++)
    {
        new_str[i] = str[i];
    }

    new_str[len] = '\0';

    delete[] str;

    str = new_str;
    cap = new_cap;
}

void MyString::resize(size_t new_len)
{
    if (new_len == len)
    {
        return;
    }

    if (new_len > cap)
    {
        reserve(new_len);
    }

    if (new_len > len)
    {
        for (size_t i = len; i < new_len; i++)
        {
            str[i] = '\0';
        }
    }

    len = new_len;
    str[len] = '\0';
    
}

void MyString::shrink_to_fit()
{
    if (cap == len)
    {
        return;
    }

    char* new_str = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        new_str[i] = str[i];
    }

    new_str[len] = '\0';
    delete[] str;
    str = new_str;
    cap = len;
}

char* MyString::begin()
{
    return str;
}

char* MyString::end()
{
    return str + len;
}

const char* MyString::begin() const
{
    return str;
}

const char* MyString::end() const
{
    return str + len;
}

const char* MyString::cbegin() const
{
    return str;
}
const char* MyString::cend() const
{
    return str + len;
}