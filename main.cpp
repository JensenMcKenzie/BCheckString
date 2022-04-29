/*
BCheckString.cpp -
Author: Jensen McKenzie
Module: 13
Project: Homework 13
Problem Statement: Create custom class, extending string, that will throw a custom error if an invalid index is passed
 to the [] operator.

Algorithm/Plan:
  1. Create a BCheckString class, extending string
    1a. Create a constructor which calls the string constructor, with provided string s
    1b. Create a custom exception class, which contains an index out of bounds error message
    1c. Overwrite the [] operator, throwing a BoundsException if the provided index is out of bounds
  2. Test the overwritten [] operator in main, by:
    2a. Providing a valid index
    2b. Providing a negative index
    2c. Providing an index greater than the length of the string
*/

#include <iostream>

using namespace std;

class BCheckString : public string{
public:
    class BoundsException : public exception{
        public:
        //Override the throw function to contain a custom error message
        const char * what () const throw(){
            return "Index out of bounds.";
        }
    };

    BCheckString(string s) : string(s){}

    char operator[](int k){
        if(k > size()-1 || k < 0){
            throw BoundsException();
        }
        return data()[k];
    }
};

int main() {
    BCheckString b("ABC");
    cout << "String is: " << b << endl;
    cout << "Element 0: " << b[0] << endl;
    try {
        cout << "Element -1: " << b[-1] << endl;
    }catch (exception& e){
        cout << e.what() << endl;
    }
    try {
        cout << "Element 3: " << b[3] << endl;
    }catch (exception& e){
        cout << e.what() << endl;
    }
}
