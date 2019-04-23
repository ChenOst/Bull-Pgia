#include <iostream>
#include <string>
#include "Guesser.hpp"
using std::string;
using namespace bullpgia;

string Guesser::guess(){
    int number = 0;
    cout << "Please enter your guess: ";
    cin >> number;
    string res = std::to_string(number);
    this->length = res.length();
    return res;
}
