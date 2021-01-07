/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Die and LoadedDie classes, both of which
** generate a random simulated dice roll and return that value.
** LoadedDice will return weighted results.
*********************************************************************/
#include <iostream>
#include <string>
#include <chrono> //used for alternate random generator
#include <random> 
#include "menuShell.hpp" //for requesting weight
#include "die.hpp" 

//setter/getter for the sides attribute
void Die::setSides(int sides) {
	this->sides = sides; 
}
int Die::getSides() {
	return this->sides;
}

/*********************************************************************
** Description: Die::roll() method generates a random number for the 
** dice roll which will not be the same if called during the same 
** time frame. 
** Reference: http://www.cplusplus.com/reference/random/uniform_int_distribution/operator()/
*********************************************************************/
int Die::roll() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(1, sides);
	int roll = distribution(generator);
	return roll;
}

/*********************************************************************
** Description: LoadedDie::setWeight() requests the user to choose just
** how much to multiply the chances fo rolling their maximum value by. 
** Then creates an array to represent the chances of rolling each side
** with the weighted maximum value.
*********************************************************************/
void LoadedDie::setWeight() {
	std::string howLoaded = "Please choose a weight for your maximum roll by entering an integer to multiply it by from 2 to 100.";
	this->weight = chooseIntInRange(howLoaded, 2, 100);

	chance = sides + weight-1;

	chanceDistro = new int[sides + 1]{0};//make an array the size of the number of sides

	for (int i = 1; i<sides+1; i++) {//fill in the array with odds of rolling each side
		if (i == sides) {
			chanceDistro[i] = this->chance;
		}
		else {
			chanceDistro[i] = (this->chance - weight) / (sides - 1)*i;
		}
	}
}

/*********************************************************************
** Description: LoadedDie::setWeight(int) Overloaded method to allow 
** setting weight upon construction. 
*********************************************************************/
void LoadedDie::setWeight(int weight) {
	this->weight = weight;

	chance = sides + weight - 1;

	chanceDistro = new int[sides + 1]{ 0 };//make an array the size of the number of sides

	for (int i = 1; i < sides + 1; i++) {//fill in the array with odds of rolling each side
		if (i == sides) {
			chanceDistro[i] = this->chance;
		}
		else {
			chanceDistro[i] = (this->chance - weight) / (sides - 1)*i;
		}
	}
}

/*********************************************************************
** Description: LoadedDie::roll() method  replaces the basic method. 
** First it rolls a die based on a modified number of die sides to 
** simulate weight on the part of the highest side. Then this roll is 
** compared to ranges set by the LoadedDie::setWeight() method to
** determine the actual result. Generates a random number for the
** dice roll which will not be the same if called during the same
** time frame. 
** Note: It may seem to be over complicated, but it is 
** designed this way so that if desired it could be more easily 
** modifed to distribute the weighting throughout multiple sides of 
** the die. 
** Reference: http://www.cplusplus.com/reference/random/uniform_int_distribution/operator()/
*********************************************************************/
int LoadedDie::roll()  {
	int modifiedRoll = 0, currentSide = 1;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();//generate random number
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(1, this->chance);
	int roll = distribution(generator);
	
	while(currentSide<=sides) {//compare actual roll to modified ranges
		if (roll <= chanceDistro[currentSide] && roll > chanceDistro[currentSide - 1]) { 
			modifiedRoll = currentSide;
		}
		else if (roll <= 0) {
			std::cout << "roll<=0, why?" << std::endl;
		}
		currentSide++;
	}
	return modifiedRoll;
}


