#include <iostream>
#include <string>
#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include <vector>
using std::string;

//http://www.cplusplus.com/forum/beginner/148637/
string bullpgia::SmartGuesser::guess() {
	int j=0;
	for(int i=0; i<length; i++){
		nums[i]=j;
		if(){
			j=0;
		}
		else{
			if(j>=9){
				j=0;
			}
		}
	}
	return mguess;
}

void bullpgia::SmartGuesser::startNewGame(uint length) {
	this->length = length;
	nums.erase (nums.begin(),nums.end()+0);
	key.erase (key.begin(),key.end()+0);
	track=0;
}
void bullpgia::SmartGuesser::init_nums(vector<char>& nums){

}
void bullpgia::SmartGuesser::get_key(vector<char>& key){
	for (short int i{ 0 }; i < length; i++) {
		char c;

	}

}

void bullpgia::SmartGuesser::learn(string reply) {
	std::size_t found = reply.find(",");
	int numberBull = stoi(reply.substr(0, found));
	int numberPgia = stoi(reply.substr(found + 1, reply.length()));
	    
    if (numberBull == length) {
        break;
    }
	get_key(key);
}
