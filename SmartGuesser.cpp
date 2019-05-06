#include <iostream>
#include <string>
#include "SmartGuesser.hpp"
#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using std::string;
using namespace bullpgia;

//http://www.cplusplus.com/forum/beginner/148637/
string bullpgia::SmartGuesser::guess() {
	int j=0;
	string res = "";
	for(int i=0; i<length; i++){
		nums[i]=j;
		if(i==0){
			if(bullpgia::calculateBullAndPgia(nums, key)=="1,0"){
			res = res + std::to_string(j);
			j=0;
			}
			else{
				j++;
			}
		}
		else if(i==1){
			if(bullpgia::calculateBullAndPgia(nums, key)=="2,0"){
			res = res + std::to_string(j);
			j=0;
				}
			else{
				j++;
			}
		}
		else if(i==2){
			if(bullpgia::calculateBullAndPgia(nums, key)=="3,0"){
			res = res + std::to_string(j);
			j=0;
				}
			else{
				j++;
			}
		}
		else if(i==3){
			if(bullpgia::calculateBullAndPgia(nums, key)=="4,0"){
			res = res + std::to_string(j);
			j=0;
			}
			else{
				j++;
			}
		}
		if(j>9){
			j=0;
		}
	}
	return res;
}

void bullpgia::SmartGuesser::startNewGame(uint length) {
	this->length = length;
	nums="";
	key="";
	track=0;
}

void bullpgia::SmartGuesser::learn(string reply) {
	std::size_t found = reply.find(",");
	int numberBull = stoi(reply.substr(0, found));
	int numberPgia = stoi(reply.substr(found + 1, reply.length()));

	if(numberBull==length){
		return;
	}
}
