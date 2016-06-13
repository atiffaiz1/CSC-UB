//
// Created by Bill on 5/2/2016.
//

#include <iostream>
#include "derived_types.h"

using namespace std;

//Here all functions are preceded by abcd:: because they are part of the abcd
double abcd::func_one(double x){//A function that takes a double and returns a double
    double tmp = x;
    x *= 3;
    x -= tmp;
    return x;
}

int abcd::func_one(int x){//A function that takes an int and returns an int
    double tmp = x;
    x *= 3;
    x -= tmp;
    return x;
}

double abcd::pass_ref(double& x){//A function that uses pass by reference
    x = 2*x;//Here the value of the argument changes since x is a reference
    return x -3.7;
}

double abcd::pass_point(double* x){
    *x = 2*(*x);
    return *x - 3.7;
}

void abcd::swap1(int a, int b){//This looks good, but actually does nothing since only copies of the values are used
    int tmp = a;
    a = b;
    b = tmp;
}
void abcd::swap2(int& a, int& b){//Same function but using references so that it actually works
    int tmp = a;
    a = b;
    b = tmp;
}

double abcd::counter(int i, int j, bool a){//A recursive function with a default argument
    j += i;                                  //default arguments must be the trailing arguments
    i--;
    if (i <= 0) a = true;
    if (a) return j;
    else return counter(i, j, a);//recursion
}

int abcd::calc(){//A function using static local variables
    static bool first = true;
    static int a;
    if (first){
        a = 5;
        first = false;
    }
    return a;
}

int abcd::static_count(){
    static int count = 0;
    return ++count;
}