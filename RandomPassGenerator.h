#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "random.hpp"

class RandomPassGenerator
{
public:
    enum class chars
    {
        LOWER = 0,
        UPPER,
        DIGITS,
        SPECIAL


    };
private:
    //private variables
    std::string m_password;
    int m_leng;

    //bool variable that holds information whether at least one character has been used
    bool ok{ false };

    //number of characters in our password 
    //nums[0] = lower case
    //nums[1] = upper case etc.

    std::vector<int> nums{};

    //current picked string 
    std::string now;

    
    //private methods
    


    //generate char from one of 4 strings (0,3)
    void generateChar(int y, int x );

    //when char is generated, add it to our password
    void addChartoPass();
  
public:
    //constructor
    RandomPassGenerator();

    //password output
    friend std::ostream& operator <<(std::ostream& out, const RandomPassGenerator& pass);

    //generathe the password based on the length (min 8 characters)
    void generate(int leng);
  

    //when password is generated
    //check if it has at least one character from upper,lower,digits and special characters
    //if not, generate missing character and replace with the most common one
    void checkPass();
   



};




