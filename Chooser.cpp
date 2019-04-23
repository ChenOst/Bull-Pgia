#include <iostream>
#include "Chooser.hpp"
using namespace bullpgia;
using std::string;

string Chooser::choose(uint length){
    int number = 0;
    cout << "Please enter a number sequance: ";
    cin >> number;
    string res = std::to_string(number);
    this->length = res.length();
    return res;
}