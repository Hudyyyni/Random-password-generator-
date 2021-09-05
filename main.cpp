#include <iostream>
#include "random.hpp"
#include "RandomPassGenerator.h"


int main()
{

    RandomPassGenerator pass;
   
    pass.generate(10);
    std::cout << pass;



    return 0;
}

