/*
2/15/2023

Creates an ‘Array’ class that is able to hold multiple integer values. The
‘Array’ class will be given functionality through the use of various overloaded
operators implemented in Array.cpp
*/

#include <iostream>
#include <string>
#include "ARRAY.h"

using namespace std;

int main() {
    Array arr1(5), arr2(10);
    for (int i = 0; i < arr1.getSize(); i++) arr1[i] = i;
    for (int i = 0; i < arr2.getSize(); i++) arr2[i] = i;
    cout << "arr1 contains: " << arr1;
    cout << "arr2 contains: " << arr2;
    Array arr3(arr1);
    cout << "arr3 contains: " << arr3 << endl;
    arr2 = arr2;
    cout << "arr2 contains: " << arr2;
    arr3 = arr2;
    cout << "arr3 contains: " << arr3 << endl;
    cout << boolalpha;  // Display booleans as 'true' or 'false' instead of 1 or
    // 0
    cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
    cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
    cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
    arr3[0] = 100;
    cout << "New arr3: " << arr3;
    cout << "arr2 == arr3: " << (arr2 == arr3) << endl;
    cout << "arr1 == arr3: " << (arr1 == arr3) << endl;
    cout << "arr1 < arr3: " << (arr1 < arr3) << endl << endl;
    arr1 += arr2;
    cout << "arr1 += arr2: " << arr1 << endl;
    cout << "!arr1: " << !arr1;
    cout << "*arr1: " << *arr1 << endl << endl;
    cout << "arr1++: " << arr1++;
    cout << "arr1 is: " << arr1 << endl;
    cout << "--arr1: " << --arr1;
    cout << "arr1 is: " << arr1 << endl;
    cout << "Total number of elements in all arrays: "
        << Array::getNumberOfElements() << endl
        << endl;
    return 0;
}

/*
arr1 contains: 0 1 2 3 4
arr2 contains: 0 1 2 3 4 5 6 7 8 9
arr3 contains: 0 1 2 3 4

arr2 contains: 0 1 2 3 4 5 6 7 8 9
arr3 contains: 0 1 2 3 4 5 6 7 8 9

arr2 == arr3: true
arr1 == arr3: true
arr1 < arr3: false

New arr3: 100 1 2 3 4 5 6 7 8 9
arr2 == arr3: false
arr1 == arr3: false
arr1 < arr3: true

arr1 += arr2: 0 1 2 3 4 0 1 2 3 4 5 6 7 8 9

!arr1: 4 4 3 1 8 9 1 2 3 0 6 0 5 2 7
*arr1: 0

arr1++: 4 4 3 1 8 9 1 2 3 0 6 0 5 2 7
arr1 is: 5 5 4 2 9 10 2 3 4 1 7 1 6 3 8

--arr1: 4 4 3 1 8 9 1 2 3 0 6 0 5 2 7
arr1 is: 4 4 3 1 8 9 1 2 3 0 6 0 5 2 7

Total number of elements in all arrays: 35
*/