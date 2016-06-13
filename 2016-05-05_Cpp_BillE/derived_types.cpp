//
// Created by Bill on 4/29/2016.
//

#include <iostream>
#include "derived_types.h"

using namespace std;

inline int half(int i){//An inline function
    return i/2;
}
//#define half(i) ((i)/2)//The equivalent C style macro

int forw(double);//Forward declaration of function forward. Also a prototype

void enumerations(){
    //Here is info about enumerations
    cout << "\nEnumerations\n";
    //Here is an enum for colors
    enum color {red, orange, yellow, green, blue, indigo, violet};
    color x, y;
    x = orange; //Here x = 1
    y = blue; //Here y = 4
    //This could then be used for some comparison or something
    if (x < y) cout << "Some useful information\n";

}

void arrays(){
    //Here is info about arrays
    cout << "\nArrays\n";
    //here is a 1d array
    double array[10];//an array of 10 doubles all initialized to 0
    array[3] = 3;
    cout << array[3] << endl;
    for (int i = 0; i < 10; ++i) array[i] = i*2;
    for (int i = 0; i < 10; ++i) {
        cout << "Here is the value of array[" << i << "] " << array[i] << endl;
    }

    //here is a 2d array
    double array2d[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << "Here is the center value: " << array2d[1][1] << endl;
    cout << "Here is the entire array:\n";
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << array2d[i][j] << " ";
        }
        cout << '\n';
    }
}

void structs(){
    //Here is something about structures
    //also unions and bit fields
    cout << "\nStructures\n";
    //Structs can continue any number of different fields with different types
    struct car {//This defines a new type object "car"
        string type;
        string color;
        int topspeed;
        int numdoors;
    };//Don't forget this semicolon
    //Structs can be initialized as
    car a = {"porsche", "black", 200, 2};
    //From here we can access its properties
    cout << a.color << endl;//use of the . (dot) operator to access its members
    car b = a;//We can copy one struct to another
    b.type = "toyota";//We can change the values
    b.numdoors = 4;
    b.topspeed = 150;
    cout << "The type of a is " << a.type << " The type of b is " << b.type << endl;

    //Unions are like structs where only one member can exist at a time
    //this can be useful to save memory
    cout << "\nUnions\n";
    union example{//This union will take of sizeof(double) space in memory
        int i;
        double d;
        char c;
    };//Again with the semicolon

    example ex;
    //something based on user input maybe
    ex.i = 4;
    cout << "The size of this union is: " << sizeof(ex) << " It holds the value: " << ex.i << endl;

    //Bit fields
    //you can specify the members of structs and unions to only take up a certain number of bits
    cout << "\nBit fields\n";
    struct flags {//This should take up four bytes the size of one unsigned int
        unsigned int flag1 : 1;//Each of the flags can be either 0 or 1
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
        unsigned int flag5 : 1;
        unsigned int flag6 : 1;
        unsigned int flag7 : 1;
        unsigned int flag8 : 1;
    };

    flags test;
    test.flag1 = 0;
    test.flag2 = 1;
    test.flag3 = 1;
    test.flag4 = 0;
    test.flag5 = 1;
    test.flag6 = 0;
    test.flag7 = 1;
    test.flag8 = 0;

    cout << "The size of a flags struct is: " << sizeof(test) << " bytes. Here is flag3: " << test.flag3 << endl;

}

void pointers(){
    //Here is some info about pointers
    cout << "\nPointers\n";
    //For any type T, T* is the pointer to T
    //Pointers hold the address in memory of any object
    //This allows you to do operations on large objects that take up a lot of memory without passing around a
    //lot of copies of those objects

    //Examples
    int i = 7;//Here is an int with value of 7
    int* p;//Here p is a pointer to type int, it currently refers to nothing
    p = &i;//The & operator or address of operator allows assigning the memory address of i to p
    cout << "Here is the value of i = " << i << " While here is the value of p = " << p << endl;
    //To get the value that a pointer points to we can use *p
    cout << "Here is the value p points to *p: " << *p << endl;
    //Some examples of pointer manipulation
    i = 12;//Set value of i to 12
    int j = *p;//Here j = 12 since *p still points to i
    int *p2 = &j;//Direct assign of pointer p2 to address of j
    j = 15;
    p = &j;//reassign p to point to j
    p2 =&i;//reassign p2 to point to i
    *p2 = 20;//assign value 20 to i through its pointer p2
    //At this point we should have i = 20, j = 15, *p = 15, *p2 = 20
    cout << "Here the value of i = " << i << " and j = " << j << " and p2 = " << p2 << endl;
    //We should see that p2 = p from before since p2 is now pointing to i which is still in the same memory location

    //new operator
    //allows us to assign a sequence of objects like an array returning a pointer to the first object
    int n = 20;//unlike arrays this can be dynamic n could be calculated at runtime
    double* d = new double[n];//allocates space for n doubles with d pointing to the first of them
    //This objects can now be accessed like an array
    for(int k = 0; k < n; ++k) d[k] = k;
    double sum = 0;
    for(int k = 0; k < n; ++k) sum += d[k];
    cin.get();
    cout << "The value of sum = " << sum << endl;
    //Some more examples
    d[5] = 10;//We can change the value of individual elements
    *d = 12;//Remember d points to the first object
    *(d+2) = 15;//Here we have used pointer arithmetic to change the third object
    for(int k = 0; k < n; ++k) cout << "The " << k << " object's value = " << d[k] << endl;
    //Remember when using new you must free the memory when done with it using delete
    delete[] d;//Here delete[] is used since there is more than one object being freed

    //Multiple pointers
    n = 4;
    int** multi = new int* [n];//This is a double pointer multi is a pointer to n pointer objects
    for(int k = 0; k < n; ++k) multi[k] = new int [n];//Each of those pointers points to n int objects
    //Assign some values
    for (int row = 0; row < n; ++row){
        for (int col = 0; col < n; ++col){
            multi[row][col] = row+col;
        }
    }
    //Looks like
    cin.get();
    cout << "Here is the array\n";
    for (int row = 0; row < n; ++row){
        for (int col = 0; col < n; ++col){
            cout << multi[row][col] << ' ';
        }
        cout << endl;
    }
    //To delete
    for (int row = 0; row < n; ++row) delete[] multi[row];
    delete[] multi;

    //Pointer offsetting, this is basically just pointer arithmetic
    //This can make things look nicer sometimes, but is mostly unnecessary
    double* off = new double[10];
    off -= 10;//offset the pointer
    for (int k = 10; k < 20; ++k) off[k] = k;
    off[10] = 200;//allows first index to be referred to by the offset
    cin.get();
    cout << "Pointer offsetting\n";
    for (int k = 10; k < 20; ++k) cout << off[k] << ' ';
    off +=10;//Needs to be reset before deleting
    delete[] off;

    //Constant pointers
    cin.get();
    cout << "\nConstant pointers\n";
    i = 5;
    j = 10;
    int* const pt3 = &j;//Const pointer to j
    //pt3 = &i;//This won't work the pointer is const can't be redefined
    *pt3 = i;//We can change the value it points to though
    cout << "Here j was changed to = " << j << endl;
    j = 10;
    const int* pt4 = &j;//Here pt4 points to a const object
    //*pt4 = 7;//The object is constant can't be changed
    j = 1;//We can change the object directly though
    pt4 = &i;//And we can change what pt4 points to though
    cout << "Here j was directly changed to = " << j << endl;
    i = 5, j = 10;
    const int* const pt5 = &j;//Here we have a const pointer to a const object
    //pt5 = &i;//We can't change what we're pointing to
    //*pt5 = 7;//Nor can we change the value
    j = 8;//We can only change the object directly
    cout << "Here j was changed to = " << j << endl;

    //Pointers to structures
    cin.get();
    cout << "\nPointers to Structures\n";
    struct car {
        string type;
        string color;
        int topspeed;
        int numdoors;
    };

    car sedan = {"ford","red",150,4};
    car* structpt = &sedan;//Here is a pointer to sedan
    //To access a structs members through its pointer use the -> operator
    structpt->color="blue";
    cout << "Here we have changed the struct through the pointer the new color is " << sedan.color << endl;

    //Pointer to char
    //Here for info, but probably easier to just use <string> library instead or <cstring> if
    //you really need to manipulate c stryle strings
    cin.get();
    cout << "\nPointers to Char\n";
    char str[] = "hallo";//array of six characters
    str[1] = 'e';
    cout << str << endl;
    cout << sizeof(str);//size is 6 because of null character at end of string

    //Pointer to arrays
    cin.get();
    cout << "\nPointers to array\n";
    int array[3] = {1, 2, 3};
    int* arrayptr = &array[0];//Points at initial element
    int* arrayptr2 = array;//Another way to do same thing
    cout << *arrayptr << endl;//Prints just first element

    //References
    //To assign a reference to a type T; T& name = variable
    cin.get();
    cout << "\nReferences\n";
    int r = 9;
    int& ref = r;//ref is now a reference to r or an alias for it
    ref = 2;//Now r = 2 as well


}

void functions(){
    //The functions below are mostly defined in functions.cpp
    using namespace abcd;//This is the other way to specify namespace besides abcd::

    //Here is something about functions
    cout << "\nFunctions\n";
    //Have been using functions to separate out each different topic so far
    //In general functions take an input do some action and then return some output

    //However you can have functions that don't return anything these are declared
    //as void like this function for example

    //You can also have functions that take no input again this function would be an example

    //Every function needs to be defined somewhere only once

    //Some examples

    //Function can be defined and declared all in one
    double a = 5.4;
    a = func_one(a);
    cin.get();
    cout << "Here is the value of a: " << a << endl;

    //Functions must be either defined before use or need forward declaration
    int b = forw(a);
    cin.get();
    cout << "Here b = " << b << endl;

    //Functions can be overloaded
    b = func_one(b);//Here the int version of the function is chosen
    double c = func_one(b);//Still the int version only the argument is considered for overloading
    cin.get();
    cout << "Here are the results for b " << b << " and c " << c << endl;

    //Argument Passing
    cin.get();
    cout << "\nArgument Passing\n";
    //arguments can be passed either by value or by reference

    //passing by value is safe since the original variable is not modified a copy is made and worked with
    a = 7.2;
    c = func_one(a);//Here we assign the result to c, but a still = 7.2
    cout << "Pass by value is safe, a = " << a << " and c = " << c << endl;

    //pass by reference not necessarily safe since you modify the variable
    //however it can be efficient if function argument is a large since it doesn't need to make a copy
    a = 5.5;
    c = pass_ref(a);//Here a is also modified
    cin.get();
    cout << "Pass by reference is not necessarily safe a = " << a << " and c = " << c << endl;
    //You can also achieve this pass by reference effect by passing pointers by value
    a = 5.5;
    c = pass_point(&a);//Need to pass &a (address of a) since function expects a pointer
    cout << "Passing pointers gives same result        a = " << a << " and c = " << c << endl;
    //This can also be useful for some cases where pass by value simply doesn't work
    int one = 2, two = 1;//Here we want to swap the values
    cin.get();
    swap1(one, two);
    cout << "Here the pass by value does nothing one = " << one << " and two = " << two << endl;
    swap2(one, two);
    cout << "However pass by reference works     one = " << one << " and two = " << two << endl;
    //To get the memory efficiency of pass by ref/pointer but keep the safety of not being able to modify the variable
    //const references/pointers can be used

    //Inline Functions, Recursive Functions, and Default arguments
    cin.get();
    cout << "\nInline Functions, Recursive Functions and Default arguments\n";
    //using the "inline" keyword you can try to avoid function calling overhead by substituting the function
    //directly inline. This is just a suggestion to the compiler and not a guarantee. They are similar to c style macros
    //but safer since they are type checked
    b = 8;
    one = half(b);//Use of inline function

    //Recursive functions are functions that call themselves over again
    one = 7, two = 8;
    bool flag = true;
    a = counter(one, two, flag);//Here no recursion should take place because flag = true
    cout << "With flag = true, a = " << a << endl;
    a = counter(one, two);//Here recursion because the bool defaults to false
    cout << "With no flag,     a = " << a << endl;

    //Static local variables
    cin.get();
    cout << "\nStatic local variables\n";
    //Static overides the fact that normally variables declared within lose their value after the function
    //static variables have persistence
    one = calc();//Here one = 5
    two = calc();//Here two = 5 though no calculation needed to take place
    cout << "The value of one = " << one << " similarly two = " << two << endl;
    //Second example
    one = static_count();//Here one = 1
    one = static_count();//Here one = 2 since the value of 1 from the previous call was retained
    cout << "The value of one after two calls to static_count() is " << one << endl;



}

int forw(double x){//The definition of our forward declared function
    int a = 2*x;
    return a;
}