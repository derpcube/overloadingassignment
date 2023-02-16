#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ARRAY.h"

using namespace std;

int Array::numberOfElements = 0;

// constructor. receives size of the array, returns nothing and creates a new
// array allocated on the heep with size size.
Array::Array(int size) {
    this->size = size;

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    numberOfElements += size;
}

// copy constructor. receives another array class, returns nothing and
// initializes an array using another array of the same class
Array::Array(const Array& other) {
    size = other.size;

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }

    numberOfElements += other.size;
}

// Destructor, cleans the heap
Array::~Array() {
    numberOfElements -= size;

    delete[] arr;
}

// copy assignment operator. receives array object. copies elements of one array
// object to another array object.
Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;

        numberOfElements -= size;

        size = other.size;

        numberOfElements += other.size;

        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// The equality operator (==) returns true if one Array object is an in-order
// subset of another Array object.
bool Array::operator==(const Array& other) const {
    if (size > other.size) {
        return false;
    }

    int i = 0, j = 0;

    while (i < size && j < other.size) {
        if (arr[i] == other.arr[j]) {
            i++;
        }
        j++;
    }

    return i == size;
}

// The less-than operator (<) compares two Array objects element-by-element,
// starting from the beginning.
bool Array::operator<(const Array& other) const {
    int i = 0, temp = 0;
    bool result = false;

    if (size < other.size) {
        temp = size;
    }
    else {
        temp = other.size;
    }

    while (i < temp) {
        if (arr[i] < other.arr[i]) {
            result = true;
            break;
        }
        else {
            result = false;
        }
        i++;
    }

    return result;
}

// The not operator (!) randomly shuffles the elements in the array
Array& Array::operator!() {
    srand(time(nullptr));

    for (int i = 0; i < size; i++) {
        int index1 = rand() % size;
        int index2 = rand() % size;
        int temp = arr[index1];

        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    return *this;
}

// The indirection operator (*) returns the smallest value inside the Array
// object
int& Array::operator*() {
    int min = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == min) {
            return arr[i];
        }
    }

    return arr[0];
}

// The compound sum assignment operator (+=) extends the left-hand object to
// include the elements of the right-hand object
Array& Array::operator+=(const Array& other) {
    int* temp = new int[size + other.size];

    numberOfElements -= size;

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    for (int i = 0; i < other.size; i++) {
        temp[size + i] = other.arr[i];
    }

    delete[] arr;

    arr = temp;

    size += other.size;

    numberOfElements += size;

    return *this;
}

// prefix increment. receives nothing. returns pointer to incremented array
// object.
Array& Array::operator++() {
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }

    return *this;
}

// postfix increment. receives nothing. returns pointer to incremented array
// object.
Array Array::operator++(int) { 
    Array temp(*this);

    for (int i = 0; i < size; i++) {
        arr[i]++;
    }

    return temp;
}

// prefix decrement. receives nothing. returns pointer to decremented array
// object.
Array& Array::operator--() {
    for (int i = 0; i < size; i++) {
        arr[i]--;
    }

    return *this;
}

// postfix decrement. receives nothing. returns pointer to decremented array
// object.
Array Array::operator--(int) {
    Array temp(*this);

    for (int i = 0; i < size; i++) {
        arr[i]--;
    }

    return temp;
}

// oveloading [](index) operator. accepts index as an integer and returns the
// value at the index at array object.
int& Array::operator[](int index) const { 
    return arr[index]; 
}

// overloading << operator. accepts ostream and array objects, returns printed
// array object elements in the form of ostream.
std::ostream& operator<<(std::ostream& os, const Array& other) {
    for (int i = 0; i < other.getSize(); i++) {
        os << other[i];

        if (i != other.getSize() - 1) {
            os << " ";
        }
    }

    cout << endl;

    return os;
}

// returns number of elements in array. accepts nothing.
int Array::getNumberOfElements() { 
    return numberOfElements; 
}

// returns size of array. accepts nothing.
int Array::getSize() const { 
    return size; 
}