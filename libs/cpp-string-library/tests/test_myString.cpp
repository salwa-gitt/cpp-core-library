#include "../include/myString.h"
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <utility>

int main()
{
    // Construction
    MyString a;
    assert(a.length() == 0);
    assert(a.empty());

    MyString b("Hello");
    assert(b.length() == 5);
    assert(!b.empty());

    // Copy
    MyString c(b);
    assert(c == b);

    // Assignment
    MyString d;
    d = b;
    assert(d == b);

    // Self assignment
    d = d;
    assert(d == b);

    // Move
    MyString e(std::move(b));
    assert(e == MyString("Hello"));

    // Character access
    assert(e[0] == 'H');
    assert(e.front() == 'H');
    assert(e.back() == 'o');
    assert(e.at(1) == 'e');

    // Modification
    e[0] = 'h';
    assert(e == MyString("hello"));

    // Append
    e.append(MyString(" world"));
    assert(e == MyString("hello world"));

    // Concatenation
    MyString x("Hello");
    MyString y(" World");
    MyString z = x + y;
    assert(z == MyString("Hello World"));

    // Push/pop
    z.push_back('!');
    assert(z == MyString("Hello World!"));

    z.pop_back();
    assert(z == MyString("Hello World"));

    // Insert
    MyString s("Helo");
    s.insert(2, MyString("l"));
    assert(s == MyString("Hello"));

    // Erase
    s.erase(1, 2);
    assert(s == MyString("Hlo"));

    // Replace
    MyString r("Hello World");
    r.replace(6, 5, MyString("C++"));
    assert(r == MyString("Hello C++"));

    // Search
    MyString search("Hello World");

    assert(search.find(MyString("World")) == 6);
    assert(search.contains(MyString("Hello")));
    assert(search.starts_with(MyString("Hello")));
    assert(search.ends_with(MyString("World")));

    // Empty search
    assert(search.find(MyString("")) == 0);
    assert(search.contains(MyString("")));
    assert(search.starts_with(MyString("")));
    assert(search.ends_with(MyString("")));

    // Substring
    MyString sub = search.substr(6, 5);
    assert(sub == MyString("World"));

    // Comparison
    assert(MyString("abc") < MyString("abd"));
    assert(MyString("abc") == MyString("abc"));
    assert(MyString("abd") > MyString("abc"));

    // Capacity
    MyString capacityTest;
    capacityTest.reserve(20);
    assert(capacityTest.capacity() >= 20);

    capacityTest.push_back('A');
    assert(capacityTest.length() == 1);

    // Exception
    bool threw = false;

    try
    {
        search.at(100);
    }
    catch (const std::out_of_range&)
    {
        threw = true;
    }

    assert(threw);

    std::cout << "All tests passed!\n";

    return 0;
}