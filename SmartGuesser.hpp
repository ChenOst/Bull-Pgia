#pragma once
#include <iostream>
#include "Guesser.hpp"
#include <string>
#include <list>
#include <vector>
using std::string, std::istream, std::iostream;

namespace bullpgia{
    class SmartGuesser : public bullpgia::Guesser{
        string mguess;
        vector<char> nums; //vector for user's guesses
        vector<char> key; //the digit code
        int track=0; //this variable helps handling various trackings in the while loop and increases by 1 each time that the user enters a number

        public:
        SmartGuesser()
        {
            this->mguess="";
        }
        void init_nums(vector<char>& nums);
        void get_key(vector<char>& key);
        string guess() override;
        void startNewGame(uint length) override;
        void learn(string reply) override;
    };
};