//
// Created by Bill on 4/29/2016.
//

#ifndef INTRO_PRESENTATION_DERIVED_TYPES_H
#define INTRO_PRESENTATION_DERIVED_TYPES_H

#endif //INTRO_PRESENTATION_DERIVED_TYPES_H


void enumerations();

void arrays();

void structs();

void pointers();

void functions();

//Following functions defined in functions.cpp
//This also an example of namespaces
namespace abcd {

    double func_one(double);

    int func_one(int);

    double pass_ref(double &);

    double pass_point(double *);

    void swap1(int, int);

    void swap2(int &, int &);

    double counter(int, int, bool=false);

    int calc();

    int static_count();

}