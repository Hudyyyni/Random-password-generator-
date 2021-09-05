#include "RandomPassGenerator.h"
#include "Generator.h"
#include <assert.h>
#include "random.hpp"
 
using Random = effolkronium::random_static;

void RandomPassGenerator::generateChar(int y = 0, int x = 3)
{
    // pick random number (default form 0,3) 
    // this number will be our string (0 = lower, 1 = upper, 2 = digits, 3 = special)
    // increase number of chars, if now = digits, out first character in pass will be digit so increase it


    now = Generator::arr.at(Random::get(y, x));
    if (now == Generator::digits)
        ++nums.at(static_cast<int>(chars::DIGITS));
    else  if (now == Generator::lower)
        ++nums.at(static_cast<int>(chars::LOWER));
    else  if (now == Generator::upper)
        ++nums.at(static_cast<int>(chars::UPPER));
    else
        ++nums.at(static_cast<int>(chars::SPECIAL));



}
void RandomPassGenerator::addChartoPass()
{
    //now pick random char from our string and add to out password 
    m_password += now.at(Random::get(0, static_cast<int>(now.size() - 1)));
}
RandomPassGenerator::RandomPassGenerator() {

    now = "";
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
}

//password output
std::ostream& operator <<(std::ostream& out, const RandomPassGenerator& pass)
{

    out << pass.m_password;
    return out;
}


void RandomPassGenerator::generate(int leng)
{
    assert(leng >= 8 && leng <= 100 && "length of password must be at least 5 characters");
    m_leng = leng;

    for (int i{ 0 }; i < m_leng; ++i)
    {
        generateChar();
        addChartoPass();

    }


    //check if our password contains at least 1 character of all strings
    do
    {
        checkPass();
    } while (!ok);



}
void RandomPassGenerator::checkPass()
{
    int receiver{ -1 };
    int doner{ -1 };

    for (int i{ 0 }; i < nums.size(); ++i)
    {

        if (nums.at(i) == 0)
        {
            receiver = i;
            break;
        }



    }
    if (receiver == -1)
    {
        ok = true;
        return;
    }


    for (int i{ 0 }; i < nums.size(); ++i)
    {
        if (nums.at(i) > 1)
        {
            doner = i;
            break;
        }

    }


    //which character is missing
    std::string temp{ Generator::arr.at(doner) };

    for (int i{ 0 }; i < m_password.length(); ++i)
    {
        auto found{ std::count(temp.begin(), temp.end(), m_password.at(i)) };

        if (found > 0)
        {
            generateChar(receiver, receiver);
            m_password.at(i) = now.at(Random::get(0, static_cast<int>(now.size() - 1)));
            --nums.at(doner);
            ++nums.at(receiver);
            break;
        }


    }



}

