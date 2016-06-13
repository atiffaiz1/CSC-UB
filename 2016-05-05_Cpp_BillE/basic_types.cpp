//
// Created by Bill on 4/28/2016.
//

#include <iostream>
#include <bitset>
#include "basic_types.h"

using namespace std;

int a = 7; //This variable has global scope

void add(int a, int b){
    cout << "From inside a void function " << a+b << endl;
}
int add2 (int a, int b){
    return a+b;
}
void switch_func(char x){

    switch(x){
        case 'A':
        case 'a':
            cout << "Here both uppercase and lowercase 'A' give the same result\n";
            break;
        case 'B':
        case 'b':
            cout << "Same as before but with the letter 'B'\n";
        case 'C':
        case 'c':
            cout << "Here we forgot the break statement\n";
            break;
        default:
            cout << "This is the default response\n";
    }
}


int basic_types(){
    cout << "Hello, World2!" << endl;

    //Start with integer types: short int, int, long int, long long int
    cout << '\n' << "Integer Types\n";
    int a; //Declaration of a to be of type int
    a = 7; //Assignment of value 7 to a
    //a is the lvalue, and 7 is the rvalue
    //lvalue associated with writing; rvalue associated with reading
    int b = 10; //Initialization of be to value 10
    cout << "This is a: " << a << endl;
    //Size of integer types
    cout << "number of bytes in a short = " << sizeof(short) << '\n';
    cout << "number of bytes in an int = " << sizeof(int) << '\n';
    cout << "number of bytes in a long = " << sizeof(long) << '\n';
    cout << "number of bytes in a long long = " << sizeof(long long) << '\n';
    short sa = 123456;
    int ia = 1234567899;
    long la = 1234567899;
    long long ll = 1234567891011121314;
    cout << "short integer overflow for sa=123456 " << sa << endl;

    //Next we have character types: char
    cin.get();
    cout << '\n' << "Char Type\n";
    char c = 'A';
    cout << "This is the character c: " << c << endl;
    //This is a char array probably instead use string library unless you really need C style strings
    char cc[6] = "hello"; //Notice 6 because trailing \n char
    cout << "This is the character string cc: " << cc << endl;

    //Next are floating point types: float, double, long double
    cin.get();
    cout << '\n' << "Floating Point Types\n";
    float f = 1.4;
    double d = 4.6;
    cout << "number of bytes in a float = " << sizeof(float) << '\n';
    cout << "number of bytes in an double = " << sizeof(double) << '\n';
    cout << "number of bytes in a long double = " << sizeof(long double) << '\n';
    //Some stuff about implicit and explicit type conversion
    int i = f + d;  //implicit conversion of f and d to int
    int j = (int)f + a; // explicit conversion from f to int
    double k = f + a;   //implicit conversion from a to double
    cout << "i = " << i << " j = " << j << " k = " << k << endl;

    //Next is the boolean type true or false
    cin.get();
    cout << '\n' << "Boolean Type\n";
    bool test = true;
    //true has the int value 1 and false 0
    bool test1 = 7;
    int test2 = false;
    int test3 = test1 + test2; //This should be 1 since test1=1 and test2=0
    cout << test3 << endl;

    //Next is the void type
    cin.get();
    cout << '\n' << "Void Type\n";
    //Not actually a type as such as it has no type
    int aa = 7;
    int bb = 9;
    add(aa,bb);
    int dd = add2(aa,bb);
    cout << "The returned value " << dd << endl;


    return 0;
}

int scope(){
    //Here will be a demonstration of scope

    int a = 6; //This variable is in the outer scope of this function it hides a form global scope
    cout << "From global scope " << ::a << " From this scope " << a << endl;
    {//Brackets define a new scope
        int a = 1; //This variable a hides a from outer scope
        cout << "This scope " << a << " From global scope " << ::a << endl;//You can always resolve out to global scope
        int b = 3;
    }
    //cout << b; This will fail as m is not in this scope
    {
        int m = 3;
        {
            int n = 2;
            int m = 4;//Again m hides m from outer scope
        }
    }
    extexample = 5.0;//This works because example is declared as extern
    cout << "Extern variable " << extexample << endl;


    return 0;
}

int expressions(){
    //Here will be an overview of expressions

    //First arithmetic expressions
    cout << "\nArithmetic Expressions\n";
    int a = 1 + 4 + 6*8;//a = 53
    cout << "int a = 1 + 4 + 6*8;" << endl;
    cout << "a = " << a << "\n\n";
    a = 4 + (2+3)*6;//a = 34
    cout << "a = 4 + (2+3)*6;" << endl;
    cout << "a = " << a << "\n\n";
    //arithmetic is left to right associative
    a = 1 + 2 + 3;//These two are the same
    cout << "a = 1 + 2 + 3;" << endl;
    cout << "a = " << a << "\n\n";
    a = (1 + 2) + 3;
    cout << "a = (1 + 2) + 3;" << endl;
    cout << "a = " << a << "\n\n";
    //In general a = b + c + d is the same as a = (b + c) + d but if b, c, and d are themselves
    //expressions you are not guaranteed that for instance b will evaluate before d
    int b = 5;
    a = b++;//Increment operator used postfix happens after expression a = 5 then b = 6
    cout << "a = b++; a = " << a << endl;
    a = --b;//Decrement operator used prefix happens before expression b = 5 then a = 5
    cout << "a = --b; a = " << a << endl;
    a = (b--) + (++b);//This is not guaranteed to be the same on all machines BE CAREFUL
    cout << "a = (b--) + (++b);" << endl;
    cout << "a = " << a << "\n\n";

    //Next is relational Expresions
    cin.get();
    cout << "\nRelational Expressions\n";
    //The relational operators are >, <, >=, <=, ==, !=
    int c = 8;
    bool d = (c > 20);//d = false or 0
    cout << "bool d = (c > 20); d = " << d << endl;
    d = (c < 20);//d = true or 1
    cout << "d = (c < 20); d = " << d << endl;
    //These all do pretty much as you'd expect
    //However you do need to be careful
    d = 4 < c < 30;//returns true as you might expect
    cout << "d = 4 < c < 30; d = " << d << endl;
    d = 4 < c < 6;//also returns true
    cout << "4 < c < 6; d = " << d << endl;
    //This is because 4 < c < 6 is the same as (4 < c) < 6 and (4 < c) is true or 1 which is less than 6
    //Again careful
    double x,y;
    x = 1000000000;
    y = 0.0000000000001;
    d = (x) < (x+y);//d evaluates to false due to rounding error
    cout << "x < (x+y); d = " << d << endl;

    //Next is logical expressions
    cin.get();
    cout << "\nLogical Expresssions\n";
    //These are && (and) and || (or)
    //For && both sides of the comparison need to be true for the result to be true
    bool e = true, f = true, g = false;
    bool h = e && f;//h = true
    cout << "h = e && f; h = " << h << endl;
    //For || only one of the arguments needs to be true to return true
    h = e || g;//h = true
    cout << "h = e || g; h = " << h << endl;
    //logical expressions unlike arithmetic have left to right evaluation,
    //and they end as soon as the evaulation can be known
    int i, j = 1;
    h = (i = 0) && (j = 8);
    cout << "h = (i = 0) && (j = 8); h = " << h << " j = " << j << endl;

    //Next is Bitwise Expressions
    cin.get();
    cout << "\nBitwise Expressions\n";
    //the bitwise expressions are & (and), | (or), ^ (exclusive or), ~ (complement), << (left shift)
    //and >> (right shift)
    //They can be applied to objects of integral type ie, ints, bool, char
    //Handy Table for &, |, and ^
    // 1&1 = 1      1&0 = 0     0&1 = 0     0&0 = 0
    // 1|1 = 1      1|0 = 1     0|1 = 1     0|0 = 0
    // 1^1 = 0      1^0 = 1     0^1 = 1     0^0 = 0
    //The ~ operator flips all bits in its operand
    a = 17;
    bitset<8> bit(a);//Convert to binary with 8 bits
    cout << "The original number " << bit << endl;
    cout << "Applying complement " << ~bit << endl;// This is called the one's complement of n
    //Two's compliment is gotten by adding one to a numbers one's complement
    a = 7;
    bitset<8> positive(a);
    a = -7;
    bitset<8> negative(a);
    cout << "The number 7 in binary  " << positive << endl;
    cout << "The number -7 in binary " << negative << endl; //Negatives stored as two's complement
    //The << and >> shift the bits by some number and fill in with 0s
    cout << "The original number " << bit << endl;
    bitset<8> left = bit << 2;
    cout << "Leftshifted by 2    " << left << endl;
    bitset<8> right = bit >> 2;
    cout << "Rightshifted by 2   " << right << endl;

    //Next is comma expressions
    cin.get();
    cout << "\nComma Expressions\n";
    a = 5;
    c = a, c = c + 7, c -= 2;//c = 10       also -= and += are compound assignment operators can be more efficient
    cout << "c = a, c = c + 7, c -= 2; c = " << c << endl;
    //Comma expressions are guaranteed to evaluate from left to right
    b = (c = 4,c+2);
    cout << "b = (c = 4,c+2); b = " << b << endl;


    return 0;
}

int statements(){
    //Here will be an overview of more complex statements

    //First are conditional statements
    cout << "\nConditional Statements\n";
    //The first are simple if statements which have the form
    //if (condition) statement
    int a = 10;
    int b = 5;
    if (a > b) a += b;
    cout << "if (a > b) a += b; a = " << a << endl;
    if (a == b) a += b;
    cout << "if (a == b) a += b; a = " << a << "\n\n";
    //Slightly more complex are if else statements
    if (a == b) cout << "a == b\n";
    else cout << "a != b\n";
    //After that we can incorporate else if
    if (a == b) cout << "a == b\n";
    else if (a < b) cout << "a < b\n";
    else if (a > b) cout << "a > b\n";
    else cout << "something weird happened\n";
    //If statements define a new scope
    if (a == b){
        cout << "a == b\n";
        a *= b;
        cout << a << endl;
    }
    else {
        cout << "a != b\n";
        cout << "a = " << a << " b = " << b << endl;
    }
    //Also of interest is the ternary conditional operator ?
    int c = a < b ? a : b;//If the statement before the ? is true the first choice is taken otherwise the second
    cout << "int c = a < b ? a : b; Here c = " << c << endl;


    //Next are goto statements
    cin.get();
    cout << "\nGoto Statements\n";
    int d = 1, e = 10;
    label: d++;//This does happen the first time through so d increments to 2
    if (d < e) goto label;//Now if d < e the code jumps back up to label
    else goto label2;//Otherwise the code jumps down to label2
    label2: cout << "Here is label2 and d = " << d << endl;
    //In practice you almost never actually need to use goto statements
    //there is usually some better way to do whatever you're trying to do

    //Next are switch statements
    //the switch_func() function is up above
    cin.get();
    cout << "\nSwitch Statements\n";
    char x = 'A';
    char y = 'a';
    char z = 'B';
    char zz = 'h';
    cout << "For case with 'A'\n";
    switch_func(x);
    cout << "For case with 'a'\n";
    switch_func(y);
    cout << "For case with 'B'\n";
    switch_func(z);
    cout << "For case with 'h'\n";
    switch_func(zz);

    //Next are Iteration statements such as for and while loops
    cout << "\nIteration Statements\n";
    //For loops have the following syntax
    //for (initialize; condition; expression) statement
    cin.get();
    cout << "First for loop\n";
    for (int i = 0; i < 10; i++) cout << "i = " << i << endl;
    //Similarly
    cout << "Second for loop\n";
    for (int i = 0; i <= 10; ++i){//pre-increment can be useful for complex types because don't need a copy
        if (i <= 5) continue;//continue stops current iteration and jumps to the next
        cout << "i = " << i << endl;
        if (i == 9) break;//break ends the loop
    }

    //While loops have the following syntax
    //while (expression) statement
    int i = 0;//Needs to be declared still because of scope for for loops
    cin.get();
    cout << "First while loop\n";
    while (i < 10) cout << "i = " << i << endl, i++;
    i = 0;
    cout << "Second while loop\n";
    while (i <= 10){
        //if (i <= 5) continue;//careful this causes infinite loop
        cout << "i = " << i++ << endl;
        if (i == 9) break;
    }

    //Do while loops have the following syntax
    //do statement while (expression)
    i = 0;
    cin.get();
    cout << "First do while loop\n";
    do {
        cout << "i = " << i++ << endl;
    } while (i < 10);
    i = 100;
    cout << "Second do while loop\n";//You always get at least one loop iteration with do while loops
    do {
        cout << "i = " << i++ << endl;
    } while (i < 10);

    return 0;
}