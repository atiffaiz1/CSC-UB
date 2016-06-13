//
// Created by Bill on 5/4/2016.
//

#include <iostream>
#include <cstdlib>
#include "classes.h"

using namespace std;
//Here will be the implementations of classes in classes.h

//The Car class
car::car(int m, double a, double c, double l){
    max_speed = m;
    acceleration = a;
    current_speed = c;
    location = l;
    example = 0;
}

void car::display(){//Function to display attributes of a car
    cout << "This is a car with\nMax speed = " << max_speed << "\nAcceleration = " << acceleration
    << "\nCurrent speed = " << current_speed << "\nLocation = " << location << "\nNumber of wheels = "<< wheels << "\n\n";
}

double car::where() const{ return location; }

void car::accelerate(int time){//Function to accelerate
    double increase = acceleration*time;
    if (increase <= (max_speed-current_speed)){//Don't want to exceed max speed
        current_speed += increase;
    }
    else {
        current_speed = max_speed;
    }
    location += current_speed*time;//Need to update location
}

void car::drive(int time){//Function to drive
    this->location += this->current_speed*time;
}

void car::stop(){//Function to stop
    current_speed = 0;
}

void car::muta() const {
    cout << "Normally a const member function can't change objects of a class\n";
    cout << "example = " << example << endl;
    example = 10;
    cout << "However they can change mutable members; example = " << example << endl;
}

void car::set_wheels(int a) {
    wheels = a;
}





//The Truck class
truck::truck(int m, double a, double c, double l){
    max_speed = m;
    acceleration = a;
    current_speed = c;
    location = l;
}

void truck::display(){//Function to display attributes of a truck
    cout << "This is a truck with\nMax speed = " << max_speed << "\nAcceleration = " << acceleration
    << "\nCurrent speed = " << current_speed << "\nLocation = " << location << "\n\n";
}

void truck::accelerate(int time){//Function to accelerate
    double increase = acceleration*time;
    if (increase <= (max_speed-current_speed)){//Don't want to exceed max speed
        current_speed += increase;
    }
    else {
        current_speed = max_speed;
    }
    location += current_speed*time;//Need to update location
}

void truck::drive(int time){//Function to drive
    this->location += this->current_speed*time;
}

void truck::stop(){//Function to stop
    current_speed = 0;
}



//This next one is a friend and belongs to both car and truck
bool collide(car a, truck b){//Function to check if a car and a truck collide
    bool tmp = false;
    if ((a.location - b.location) <= 0.1 && a.location != 0 && b.location != 0){
        tmp = true;
    }
    return tmp;
}



//The copy_example class
copy_example::copy_example() {
    numbers = new int[5];
    for (int i = 0; i < 5; ++i) numbers[i] = rand();
}

copy_example::copy_example(const copy_example& c) {//copy constructor
    numbers = new int[5];
    for (int i = 0; i < 5; ++i) numbers[i] = c.numbers[i];
}

copy_example& copy_example::operator=(const copy_example& c) {//copy assignment
    if (this != &c)//in case of self assignment ie. a=a
        for (int i = 0; i < 5; ++i) numbers[i] = c.numbers[i];
    return *this;
}

void copy_example::display() {
    cout << "Here are the points in the copy_example\n";
    for (int i = 0; i < 5; ++i) cout << numbers[i] << ", ";
    cout << endl;
}



//The two_cars class
two_cars::two_cars(car a, car b): one(a), two(b) { }
//Use of member initializer list

//This also works but is inefficient as it first initializes one and two using the default car constructor
//and then copies a and b to them

//two_cars::two_cars(car a, car b){
//    one = a;
//    two = b;
//}

void two_cars::display() {
    cout << "Car one: ";
    one.display();
    cout << "Car two: ";
    two.display();
}


//The pt_to_members class
typedef double (pt_to_members::*pf)(double);//define pf to be pointer to member

void pt_to_members::three(pt_to_members * pt, pt_to_members cl) {
    double a = pt->one(5);
    double b = pt->two(5);
    double c = cl.one(10);
    double d = cl.two(10);

    pf first = &pt_to_members::one;//pointer to member one
    pf second = &pt_to_members::two;//pointer to member two
    a = (pt->*first)(5);
    b = (pt->*second)(5);
    c = (cl.*first)(10);
    d = (cl.*second)(10);
}



//The op_ov class
op_ov::op_ov() {
    number = 0;
    vector = new double[5];
    for (int i = 0; i < 5; ++i) vector[i] = i;
}

op_ov::op_ov(const op_ov& op) {
    number = op.number;
    vector = new double[5];
    for (int i = 0; i < 5; ++i) vector[i] = op.vector[i];
}

void op_ov::num() const {
    cout << "The value of number = " << number << endl;
}

void op_ov::num2() const {
    cout << "Here are the points in the vector\n";
    for (int i = 0; i < 5; ++i) cout << vector[i] << ", ";
    cout << endl;
}

op_ov& op_ov::operator=(const op_ov& op) {
    if (this != &op)//in case of self assignment ie. a=a
        for (int i = 0; i < 5; ++i) vector[i] = op.vector[i];
    return *this;
}

op_ov& op_ov::operator+=(const op_ov& op) {
    for (int i = 0; i < 5; ++i) vector[i] += op.vector[i];
    return *this;
}

op_ov& op_ov::operator-=(const op_ov& op) {
    for (int i = 0; i < 5; ++i) vector[i] -= op.vector[i];
    return *this;
}

op_ov op_ov::operator++() {
    number++;
    return *this;
}

op_ov op_ov::operator++(int i) {
    op_ov tmp = *this;
    number++;
    return tmp;
}


//The Shape and Rectangle class
void Rectangle::set(int a, int b){
    width = a;
    length = b;
}

double Rectangle::area() {
    return width*length;
}

Square::Square(){//default constructor for a Square
    width = length = 5;
}

bool Square::am_i_really() {
    return width == length;
}

double Square::area() {
    return width*width;
}