//
// Created by Bill on 5/4/2016.
//

#ifndef C_INTRO_PRESENTATION_CLASSES_H
#define C_INTRO_PRESENTATION_CLASSES_H

#endif //C_INTRO_PRESENTATION_CLASSES_H

#include <iostream>

class truck;//Forward declaration of truck

class car {                 //This is a class for a car
private:    //Following members are private and can only be accessed by other class members or friends
    int max_speed;          //The cars max speed
    double acceleration;    //The cars acceleration
    double current_speed;   //The cars current speed
    double location;        //The cars current location
    static int wheels;      //Static int wheels
    mutable int example;    //A mutable int
public:     //Following members are public
    car(int = 100, double = 5, double = 0, double = 0);
    void display();
    double where() const;
    void accelerate(int);
    void drive(int);
    void stop();
    void muta() const;
    static void set_wheels(int = 4);
    friend bool collide(car, truck);//This is a friend can be part of many classes and still access private members
};

class truck {                 //This is a class for a truck
private:    //Following members are private and can only be accessed by other class members or friends
    int max_speed;          //The trucks max speed
    double acceleration;    //The trucks acceleration
    double current_speed;   //The trucks current speed
    double location;        //The trucks current location
public:     //Following members are public
    truck(int = 75, double = 2, double = 0, double = 0);
    void display();
    void accelerate(int);
    void drive(int);
    void stop();
    friend bool collide(car, truck);//This is a friend can be part of many classes and still access private members
};

class copy_example{ //A class to demonstrate copy constructors and assignment
    int* numbers;   //This is still private since members are private by default
public:
    copy_example();//base constructor
    ~copy_example() {delete[] numbers;}//destructor
    copy_example(const copy_example&);//copy constructor
    copy_example& operator=(const copy_example&);//copy assignment
    void display();
};

class two_cars {//A class made of 2 other classes
private:
    car one;
    car two;
public:
    two_cars(car, car);//constructor
    void display();
};

class pt_to_members {//A class for the pointer to members example
private:
    double one(double a) { return 1*a;}
    double two(double a) { return 2*a;}
public:
    void three(pt_to_members*, pt_to_members);
};

class op_ov {//A class to show operator overloading examples
private:
    int number;
    double* vector;
public:
    op_ov();//default constructor
    op_ov(const op_ov&);//copy constructor
    ~op_ov() {delete[] vector;}//destructor

    void num() const;
    void num2() const;
    op_ov& operator=(const op_ov&);
    op_ov& operator+=(const op_ov&);//defined to only effect the vector
    op_ov& operator-=(const op_ov&);//defined to only effect the vector
    double& operator[](int i) const { return vector[i]; }//This allows subscripting of op_ov
    op_ov operator++();//prefix defined to only effect the number
    op_ov operator++(int);//postfix defined to only effect the number
};

class exim {//A class to demonstrate explicit vs implicit conversion
private:
    double a;
public:
    exim(double i) { a = i; }//constructor from double to exim
    void show() { std::cout << "Here is the value of the exim: " << a << std::endl; }
    void fshow(exim e) { e.show(); }
};

class exim2 {//A class to demonstrate explicit vs implicit conversion
private:
    double a;
public:
    explicit exim2(double i) { a = i; }//constructor from double to exim
    void show() { std::cout << "Here is the value of the exim: " << a << std::endl; }
    void fshow(exim2 e) { e.show(); }
};

class Shape {// An abstract class
protected:
    int width;
    int length;
public:
    virtual double area() = 0;//pure virtual function
    virtual void set(int,int) = 0;
    virtual ~Shape() { }//empty virtual destructor
};

class Rectangle: public Shape{
public:
    void set(int, int);
    double area();
};

class Square: public Rectangle{
public:
    Square();
    double area();
    bool am_i_really();
};