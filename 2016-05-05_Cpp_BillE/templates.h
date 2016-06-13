//
// Created by Bill on 5/5/2016.
//

#ifndef C_INTRO_PRESENTATION_TEMPLATES_H
#define C_INTRO_PRESENTATION_TEMPLATES_H

#endif //C_INTRO_PRESENTATION_TEMPLATES_H

#include <iostream>
#include <string>
using namespace std;


//Example of a simple template class
template<class T>
class anything{
    T thing;
public:
    anything(T a) { thing = a; };//constructor

    void show() { cout << "In this case thing = " << thing << endl; };//function to print thing
};
//A specialization of something for example doesn't actually serve real purpose
template<>
class anything<int>{
    int thing;
public:
    anything(int a) { thing = a; };//constructor

    void show() { cout << "In this case thing = " << thing << " and here it is again " << thing << endl; };//function to print thing
};


//Example illustrating template parameters
template<class T, class C, C val, int i>//C val must come after class C
class something {//Need to be careful val and i must be constant expressions, or otherwise known at compile time
    T v[i];
    //parameter v of type T an array of some description
    int size;
    C d;//parameter d of type C
public:
    something(): d(val), size(i){//default constructor
        for (int j = 0; j < size; ++j) v[j] = 2*j;
    };
    void display() {//function to display contents
        cout << "Here is the value of d = " << d << endl;
        cout << "Here are the points in v are:\n";
        for (int j = 0; j < size; ++j) cout << v[j] << ", ";
        cout << endl;
    }
};

//The following are template functions

template <class T>
bool compare(T a, T b){//Function to compare two objects
    return a > b;//True if the first object is greater
}

inline bool operator>(const car& a, const car&b){//operator overloading for type car
    return a.where() > b.where();
}

template <class T>
void show(T a){
    cout << "Here is the argument: " << a << endl;
}

template <>//an example of function overloading for to handle strings
void show(string a){
    cout << "Here is the string: " << a << endl;
}

template <class T, class S>
T convert(S a){
    return a;
}

template <class T>
void showadd(T a, T b){
    cout << "The sum of these values is: " << a+b << endl;
}