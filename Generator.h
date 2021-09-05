#pragma once
#include <string>
#include<vector>

//Generator class
// it's static because we want to assign it only once and then generate
class Generator
{
public:
    static const std::string lower;
    static const std::string upper;
    static const std::string digits;
    static const std::string special;
    static const std::vector<std::string> arr;

};

