#pragma once
#include <iostream>
#include "Guesser.hpp"
#include <string>
using std::string, std::istream, std::iostream;

namespace bullpgia{
    class SmartGuesser : public bullpgia::Guesser{

        string MySmart;
        public:
        SmartGuesser()
        {
            this->MySmart="";
        }
            string guess() override;
            void startNewGame(uint length) override;
            void learn(string reply) override;
    };
};