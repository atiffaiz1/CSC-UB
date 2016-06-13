//
// Created by Bill on 4/29/2016.
//
#include <iostream>
#include "basic_types.h"

//Here are some examples of both creating and using namespaces
namespace one {
    void prnt(char);//Print function in namespace one
}

namespace two {
    void prnt(char);//Print function in namespace two
}

void one::prnt(char x){
    std::cout << "Here is the character once: " << x << std::endl;
}

void two::prnt(char x) {
    std::cout << "Here is the character twice: " << x << x << std::endl;
}
using namespace two;

int namespaces(){
    //Here will be information about namespcaes

    std::cout << "The std:: is needed because cout is in the std namespace\n";

    //Here are some other examples of using the one and two namespace
    char a = 'A';
    one::prnt(a);//Need to specify which namespace
    prnt(a);//Here we are already using namespace two


    return 0;
}