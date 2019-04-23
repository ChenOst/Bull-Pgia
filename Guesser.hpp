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
            string replay;
            Guesser(){};
            virtual string guess()=0;
            virtual void startNewGame(uint length){};
            virtual void learn(string reply){};
    };
};