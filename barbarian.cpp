/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Barbarian class derived from Character
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "character.hpp"
#include "barbarian.hpp"
#include "die.hpp"

Barbarian::Barbarian(){
	thisChar = BARBARIAN;
	armor = 0;
	startingStrength = 12;
	strength = startingStrength;
	numAtkDie = 2;
	numDefDie = 2;
	atkDie = new Die(6);
	defDie = new Die(6);
	describeChar = "Barbarian: Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
	describeRegAbilities = "Attack 2d6, Defense 2d6, Armor 0, Strength 18";
	typeCharStr = "Barbarian";
}

Barbarian::~Barbarian(){
	
}

/*********************************************************************
** Description: attack() rolls and returns the character's attack dice
*********************************************************************/
int Barbarian::attack(){
	int roll = 0;
	for (int i = 0; i < numAtkDie; i++) {
		roll += atkDie->roll();
	}
	return roll; 
}

/*********************************************************************
** Description: defend() takes an integer attack value and applies
** it to the defensive capabilities of the character
*********************************************************************/
std::string Barbarian::defend(int attack){
	int defendRoll = 0;
	for (int i = 0; i < numDefDie; i++) {
		defendRoll += defDie->roll();
	}
	int totalDefense = defendRoll + this->getArmor();
	int damage = attack - totalDefense;
	if (damage < 0) {
		damage = 0;
	}
	std::string result = this->nameStr + ", the " + this->typeCharStr + " has an armor of " + std::to_string(this->getArmor()) + " and had "
		+ std::to_string(this->getStrength()) + " strength remaining." + "\nThey defended with a total roll of "
		+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage.";

	this->setStrength(this->getStrength() - damage);

	return result;
}




