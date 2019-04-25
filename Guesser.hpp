#pragma once
#include <iostream>
#include <string>
#include"calculate.hpp"
using std::string;
using namespace std;

namespace bullpgia{
    class Guesser{
        public:
            uint length;
            string reply;
            Guesser(){};
            virtual string guess()=0;
            // tell the guesser that a new game starts now
            virtual void startNewGame(uint length){
                cout << "New game starts now" << endl;

            };
            // tell the guesser how many bull and pgia were in its latest guess
            virtual void learn(string reply){
                this->reply = reply;
                cout << this->reply << endl;
            };
    };
};