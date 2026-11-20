# MyString

A custom C++ string class built from scratch as a learning project.

The goal of this project was to understand how a string-like class manages memory internally rather than simply using `std::string`.

## Features

* Dynamic character storage
* C-string construction
* Deep copying
* Copy assignment
* Move constructor
* Move assignment
* Rule of Five
* Character access
* Bounds-checked access
* String comparison
* Concatenation
* String modification
* Searching
* Substrings
* Capacity management
* Iterators
* Exception handling

## Concepts Practiced

* Heap allocation and deallocation
* Ownership
* Deep copy
* RAII
* Rule of Three / Rule of Five
* Move semantics
* Operator overloading
* References and const correctness
* Dynamic memory management
* Buffer manipulation
* Capacity and reallocation
* Iterators
* Exception safety

## Project Structure

```text
MyString/
├── include/
│   └── myString.h
├── src/
│   └── myString.cpp
├── tests/
│   └── test_myString.cpp
├── .gitignore
│
└── README.md

```

## Why I Built This

This project was created as part of my C++ learning journey.

Instead of only learning C++ concepts theoretically, I wanted to understand what happens underneath a commonly used data type such as a string.

The project intentionally uses manual dynamic memory management so that concepts such as ownership, copying, moving, allocation, and capacity become concrete.

## Current Status

This project is a learning implementation and is **not intended to replace `std::string`**.

The main goal is understanding the underlying C++ concepts and practicing implementing a non-trivial class from scratch.
