#include <iostream>
#include "random.hpp"
#include "RandomPassGenerator.h"


int main()
{
    int leng{};
    int amount{};

   
    std::cout << "Passwords number:";
    std::cin >> amount;
    std::cout << "Length:";
    std::cin >> leng;
    std::cout << '\n';
 
        std::vector<RandomPassGenerator> arr{};
      
        for (int i{ 0 }; i < amount; ++i)
            arr.push_back(RandomPassGenerator(leng));

        for (const auto& i : arr)
            std::cout << i << '\n';
    
 


    return 0;
}
