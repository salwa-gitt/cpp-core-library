#pragma once
#include <cstddef>
#include <utility>

// string class that will stores characters and prevent memory leakage
class MyString
{
    private:
        char* str;
        size_t len;
        size_t cap;

    public:

        static constexpr size_t npos = static_cast<size_t>(-1);

        // default constructor
        MyString();

        // constructor from c-string
        MyString(const char* cStr);

        // copy constructor
        MyString(const MyString& cpyStr);

        // move constructor
        MyString(MyString&& other);

        // destructor for chars
        ~MyString();

        // Basic information
        // finding the length of a string
        size_t length() const;

        // finding if the string is empty or not
        bool empty() const;

        // Returns a read-only C-style string pointer (const char*).
        const char* cStr() const;

        // Deletes the string and Returns an empty string instead
        void clear();

        // Assignment
        // Copy assignment operator
        MyString& operator=(const MyString& other);

        // move assignment operator (it will move the data from A to B and A will be empty)
        MyString& operator=(MyString&& other);

        // Character access
        // non-const operator[] so i can assing a new char at a specific index
        char& operator[](size_t indx);

        // Gets the first char
        char& front();

        // Gets teh last char
        char& back();

        // it will varify if the indx is valid before returning it's char
        char& at(size_t indx);

        const char& operator[](size_t indx) const;

        // const func to get the first char
        const char& front() const;

        // const func to get the last char
        const char& back() const;

        // a const version of at()
        const char& at(size_t indx) const;

        // Comparison
        friend bool operator==(const MyString& lhs, const MyString& rhs);
        friend bool operator!=(const MyString& lhs, const MyString& rhs);
        friend bool operator<(const MyString& lhs, const MyString& rhs);
        friend bool operator>(const MyString& lhs, const MyString& rhs);
        friend bool operator<=(const MyString& lhs, const MyString& rhs);
        friend bool operator>=(const MyString& lhs, const MyString& rhs);

        // Concatenation
        MyString& append(const MyString& other);

        MyString& operator+=(const MyString& other);

        MyString operator+(const MyString& other) const;

        // Modification
        void push_back(char c);
        void pop_back();

        MyString& insert(size_t indx, const MyString& other);
        MyString& erase(size_t indx, size_t count);
        MyString& replace(size_t indx, size_t count, const MyString& other);

        // Searching
        size_t find(const MyString& other, size_t pos = 0) const;
        size_t rfind(const MyString& other, size_t pos = npos) const;
        bool contains(const MyString& other) const;
        bool starts_with(const MyString& other) const;
        bool ends_with(const MyString& other) const;

        // Utility
        MyString substr(size_t pos = 0, size_t count = npos) const;
        int compare(const MyString& other) const;
        void swap(MyString& other);

        // Capacity
        size_t capacity() const;
        void reserve(size_t new_cap);
        void resize(size_t new_len);
        void shrink_to_fit();

        // Iterators
        char* begin();
        char* end();

        const char* begin() const;
        const char* end() const;

        const char* cbegin() const;
        const char* cend() const;
        
};

// Non-member comparison operators
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);