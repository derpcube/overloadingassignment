#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>

using namespace std;

class Array {
public:
    Array(int size); // constructor
    Array(const Array& other); // copy constructor
    ~Array(); // destructor
    Array& operator=(const Array& other); // copy assignment operator

    bool operator==(const Array& other) const; // equality operator
    bool operator<(const Array& other) const; // less-than operator
    Array& operator!(); // not operator
    int& operator*(); // indirection operator
    Array& operator+=(const Array& other); // compound sum assignment operator
    Array& operator++(); // prefix
    Array operator++(int); // postfix
    Array& operator--(); // prefix
    Array operator--(int); // postfix
    int& operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& os, const Array& other);

    int getSize() const;
    static int getNumberOfElements();

private:
    int* arr;
    int size;
    static int numberOfElements;
};

#endif
