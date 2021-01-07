/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements BlueMen class derived from Character
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "character.hpp"
#include "blueMen.hpp"
#include "die.hpp"

BlueMen::BlueMen(){
	thisChar = BLUE_MEN;
	armor = 3;
	startingStrength = 12,
	strength = startingStrength;
	numAtkDie = 2;
	numDefDie = 3;
	atkDie = new Die(10);
	defDie = new Die(6);
	describeChar = "Blue Men: They are small, 6 inch tall, but fast and tough. \n" 
		" They are hard to hit so they can take some damage.\n"
		" They can also do a LOT of damage when they crawl inside enemies' armor or clothing.";
	describeRegAbilities = "Attack 2d10, Defense 3d6, Armor 3, Strength 12";
	describeSpecialAbilities = "Mob: Blue Men are actually a swarm of small individuals.\n"
		"For every 4 points of damage, they lose one defense die.\n"
		"For example, if they have a strength of 8, they would have 2d6 for defense.";
	typeCharStr = "Blue Men";
}

BlueMen::~BlueMen(){

}

/*********************************************************************
** Description: attack() rolls and returns the character's attack dice
*********************************************************************/
int BlueMen::attack(){
	int roll = 0;
	for (int i = 0; i < numAtkDie; i++) {
		roll += atkDie->roll();
	}
	return roll;
}

/*********************************************************************
** Description: defend() takes an integer attack value and applies
** it to the defensive capabilities of the character
** also adjusts the Blue Man's defense based on their special abilities
*********************************************************************/
std::string BlueMen::defend(int attack){
	int defendRoll = 0; 
	for (int i = 0; i < strength; i++) { //for every 4 points of strength remaining, get 1 defense die
		if (i % 4 == 0) {
			numDefDie = 1 + (i / 4);
		}
	}
	for (int i = 0; i < numDefDie; i++) {
		defendRoll += defDie->roll();
	}
	
	int totalDefense = defendRoll + this->getArmor();
	int damage = attack - totalDefense;
	if (damage < 0) {
		damage = 0;
	}
	std::string result = this->nameStr + ", the " + this->typeCharStr + " have an armor of " + std::to_string(this->getArmor())
		+ ".\n They had "+ std::to_string(this->numDefDie) + " defense dice remaining and "
		+ std::to_string(this->getStrength()) + " strength remaining." + "\nThey defended with a total roll of "
		+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage.";

	this->setStrength(this->getStrength() - damage);
	

	return result;
}