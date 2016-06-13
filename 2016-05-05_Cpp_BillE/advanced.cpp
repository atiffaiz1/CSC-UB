//
// Created by Bill on 5/4/2016.
//

#include <iostream>
#include <string>
#include "advanced.h"
#include "classes.h"
#include "templates.h"

using namespace std;

int car::wheels = 4;//Setting static variable wheels

void class_stuff(){//The calsses for this demonstration are in classes.cpp and classes.h
    //Here will be class stuff
    cin.get();
    cout << "\nClass Stuff\n";

    //We can show that the car class can be initialized with varying numbers of
    //arguments because of its default constructor
    car a;//Here is a default car
    a.display();
    car b(200);//Here is a car with max speed 200
    b.display();
    car c(250,20,10,10);//A fully specified car
    c.display();

    //To demonstrate friends we will initialize a truck since cars can't collide
    //with each other
    truck t(100,5);//For ease sets its acceleration same as a car
    a.accelerate(5);
    t.accelerate(5);
    bool collided = collide(a,t);
    cin.get();
    if (collided) cout << "The car and truck have collided with each other\n";

    //Something about copy constructors and copy assignments
    cin.get();
    cout << "\nCopy Constructors and Copy Assignment\n";

    //For classes that don't allocate space and then delete with a destructor
    //using delete default copy constructors and copy assignment is provided
    cout << "Default copy construction and assignment\n";
    car d = b;//copy construction
    d.display();
    d = c;//copy assignment
    d.display();

    //On the other hand if space is allocated and deleted a copy constructor and
    //copy assignment has to be defined or bad things happen
    cin.get();
    cout << "Examples where we need our own\n";
    {//New scope
        copy_example first;
        cout << "first\n";
        first.display();
        copy_example second = first;//copy construction
        cout << "second\n";
        second.display();
        copy_example third;
        cout << "third\n";
        third.display();
        second = third;//copy assignment
        cout << "second\n";
        second.display();
        second=second;//This works because we check for it
        cout << "second\n";
        second.display();
        first=second;
        cout << "first\n";
        first.display();
    }//Here end of scope all three destructors called
    //with defaults we would have had a memberwise copy of the pointers
    //and then deleted the same 5 pointers 3 times which is undefined behavior

    //Talk about static members and const and mutable members
    //Static members are part of a class, but not part of objects of said class
    //const mutable example
    cin.get();
    a.muta();


    //Talk about classes as members of other classes
    cin.get();
    cout << "Classes as members of other classes\n";
    two_cars abcd(a, b);
    abcd.display();

    //Arrays of classes
    cin.get();
    cout << "\nArrays of classes\n";
    car test[4];//An array of 4 default cars
    test[0] = a;
    test[1] = b;
    test[2] = c;
    test[3] = a;
    for (int i = 0; i < 4; ++i) test[i].display();
    //This can only be done for classes that either have no constructor or a default constructor
    //If no default is available need to use pointers
    two_cars** tc = new two_cars* [2];
    for (int i = 0; i < 2; i++){
        tc[i] = new two_cars(test[i],test[i+2]);
    }
    tc[0]->display();
    tc[1]->display();
    //Don't forget to free memory when done
    for (int i = 0; i < 2; i++) delete tc[i];
    delete[] tc;

    //Pointers to Members
    //the ->* and .* operators can be used to call through a pointer to a member
    //There is an example class and function in the classes.h and classes.cpp files

}

void operator_overloading(){//There are additional classes defined to demonstrate operator overloading
    //Stuff about operator overloading
    cin.get();
    cout << "\nOperator overloading\n";

    //we've already seen one example of this in setting up copy assignment

    //Operator overloading is used to redefine what certain operators do to
    //handle different cases that normally wouldn't work

    //Some examples
    op_ov one;
    op_ov two;
    one.num();
    ++one;//Here we show the ++ operator overloaded
    one.num();
    one.num2();
    one+=two;//Here the += operator is overloaded
    one.num2();
    cout << "\nAlso we overloaded the [] operator so we could index the vector so one[2] = " << one[2] << endl;

    //Explicit and Implicit Conversion
    cin.get();
    cout << "\nExplicit vs Implicit Conversion\n";
    cout << "First Implicit examples\n";
    exim test = 2.5;//Implicit conversion
    test.show();
    test.fshow(5.5);//Implicit conversion
    cout << "Second Explicit the previous won't work\n";
    exim2 test2 = exim2(2.5);//Explicit conversion
    test2.show();
    test2.fshow(exim2(5.5));//Explicit conversion

    //Efficiency

}

void templates(){//The templates are located in templates.h
    //Stuff about templates
    cin.get();
    cout << "\nTemplates\n";

    //Templates allow a type to be a parameter in a class or function definition
    //this lets you define something only once but use it multiple times
    double a = 5.7;
    anything<double> any = a;
    any.show();
    char b = 'b';
    anything<char> any2 = b;
    any2.show();
    string c = "hello";//We have string here from the <string> library
    anything<string> any3 = c;
    any3.show();

    //Templates can have several parameters including those the type of previous
    //template parameters
    cin.get();
    cout << "Example with multiple different template parameters\n";
    something<double, char, 'a', 5> some;
    some.display();
    something<int, int, 7, 5> some2;
    some2.display();

    //Templates can also have specializations
    //this allows you to correct for cases that wouldn't work with the base template
    cin.get();
    cout << "\nTemplate Specialization\n";
    int in = 10;
    anything<int> any4 = in;
    any4.show();
    cout << "Here we created a specialization for when the template interacts with ints\n";

    //Templates can also be used for functions
    cin.get();
    cout << "\nFunction Templates\n";
    {//New scope
        int a = 7;
        int b = 10;
        bool c = compare<int>(a, b);
        string s = c ? "true" : "false";//use of ternary conditional operator
        cout << "With ints is a > b? " << s << endl;
        double d = 15.78;
        double e = 67.8;
        c = compare<double>(e, d);
        s = c ? "true" : "false";
        cout << "Here the same function handles doubles is e > d? " << s << endl;
        //In most some cases template functions can deduce the type of the parameter you pass them
        show(d);//can deduce the type
        //a = convert(d);//ambiguous not sure which is which
        a = convert<int,double>(d);
        cout << "Here we needed to specify the types, a = " << a << endl;
    }

    //Sometimes operator overloading can be needed depending on which type the function gets
    car porsche;
    car ferrari;
    porsche.accelerate(5);//The porsche accelerates for 5 seconds
    cin.get();
    cout << "Here we can overload the > operator so that we can compare objects of type car.\n";
    if (compare(porsche, ferrari)){
        cout << "The porsche is ahead of the ferrari\n";
    }
    else cout << "The ferrari is in the lead\n";

    //We can overload templates just like regular functions
    cin.get();
    cout << "We can overload the show template for strings\n";
    //This is technically also specialization
    string st = "A string";
    show(st);

    //Careful with conversion
    cin.get();
    cout << "Standard conversion are not provided for template parameters\n";
    a = 7.7;
    double d = 10.5;
    in = 5;
    cout << "This works because a and d are both doubles\n";
    showadd(a,d);
    cout << "In this case we need to specify so it knows which to convert\n";
    showadd<double>(a,in);
}

void class_inheritance(){//These classes are also in classes.cpp and classes.h
    //Stuff about class inheritance
    cin.get();
    cout << "\nClass Inheritance\n";

    //A New class can be derived from any existing class
    //such a derived class inherits all members of the base class
    //and can add on new members as well

    Rectangle rect;
    rect.set(5,10);//Here we set the width and length of a rectangle
    double a = rect.area();
    cin.get();
    cout << "Here we can get the are of our Rectangle object area = " << a << endl;

    Square sq;
    cin.get();
    bool am_i = sq.am_i_really();
    cout << "Here we have a default square so it should return true(1): " << am_i << endl;

    //We can assign a rectangle pointer to a square object
    Rectangle* rpt = &sq;
    cout << "With this pointer we can access the area function but not am_i_really() area = " << rpt->area() << endl;
    //We can go the other way, but need static cast.

    Square* spt = static_cast<Square*>(&rect);
    cout << "In this case we can ask if the rectangle is a square should get false(0) " << spt->am_i_really() << endl;
}