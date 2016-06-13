#include <iostream>
#include "basic_types.h"
#include "derived_types.h"
#include "advanced.h"

using namespace std;
double extexample;

const int myint = 4;
#define myint2 5

class basic {   //Very basic class
private://Following members are private and can only be accessed by other class members or friends
    int first;
public://Following members are public
//    basic(int a){//a basic constructor
//        first = a;
//    }
    basic(int a = 0){//a default constructor
        first = a;
    }
    void display(){//a function to output our private variable
        cout << "The value of first is " << first << endl;
    }
};


//Probably the best way to use this tutorial would be to turn on or off (comment/uncomment)
//the appropriate function below ie. basic_types() or pointers() and then run the program while
//following along in the appropriate file
int main() {
    //cout << "Hello, World!" << endl;

    //The following functions are in basic_types.cpp and basic_types.h
    //basic_types();

    //scope();

    //expressions();

    //statements();

    //Following function in namespaces.cpp
    //namespaces();

    //Something about const and macros
    //cout << "Here is myint " << myint << endl;
    //cout << "Here is myint2 " << myint2 << endl;

    //The following functions are in derived_types.cpp and derived_types.h
    //enumerations();

    //arrays();

    //structs();

    //pointers();

    //functions();

//From here we demonstrate a basic class that is defined in the beginning of this file
//    basic a;
//    a.display();
//    basic b(5);
//    b.display();

    //The following functions are in advanced.cpp and advanced.h
    //class_stuff();

    //operator_overloading();

    //templates();

    //class_inheritance();

    return 0;
}