#include <iostream>
#include "calculate.hpp"
#include <string>
using std::string;
using std::stringstream;

namespace bullpgia{
    // The function calculates the Bull and Pgia
    string calculateBullAndPgia(string choice, string guess){
        int bull = 0;
        int pgia = 0;
        for(int i=0; i<choice.length(); i++){
            for(int j=0; j<guess.length(); j++){
                if(choice[i]==guess[j] && i==j){
                    bull++;
                }
                else if(choice[i]==guess[j] && i!=j){
                    pgia++;
                }
            }
        }
        
        string res = std::to_string(bull) + "," + std::to_string(pgia);
        return res;
    }
};
