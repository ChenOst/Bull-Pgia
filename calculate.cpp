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
        string choiceCopy = choice;
        string guessCopy = guess;
        //calculate the bull first
        for(int i=0; i<choiceCopy.length(); i++){
            for(int j=0; j<guessCopy.length(); j++){
                if(choiceCopy[i]==guessCopy[j] && i==j){
                    bull++;
                    choiceCopy[i]='X';
                    guessCopy[j]='X';
                    i++;
                }
            }
        }
        //calculate the pgia second
        for(int i=0; i<choiceCopy.length(); i++){
            for(int j=0; j<guessCopy.length(); j++){
                if(choiceCopy[i]==guessCopy[j] && i!=j && ((choiceCopy[i]!='X')&&(guessCopy[j]!='X'))){
                    pgia++;
                    choiceCopy[i]='X';
                    guessCopy[j]='X';
                }
            }
        } 
        string res = std::to_string(bull) + "," + std::to_string(pgia);
        return res;
    }
};
