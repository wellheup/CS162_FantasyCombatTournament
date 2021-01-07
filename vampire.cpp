/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/29/19
** Description: Implements Vampire class derived from Character
*********************************************************************/
#include <iostream>
#include <string>
#include "enums.hpp"
#include "menuShell.hpp" 
#include "character.hpp"
#include "vampire.hpp"
#include "die.hpp"

Vampire::Vampire() {
	thisChar = VAMPIRE;
	armor = 0;
	startingStrength = 18;
	strength = startingStrength;
	numAtkDie = 1;
	numDefDie = 1;
	atkDie = new Die(12);
	defDie = new Die(6);
	describeChar = "Vampire: Suave, debonair, but vicious and surprisingly resilient.";
	describeRegAbilities = "Attack 1d12, Defense 1d6, Armor 1, Strength 18";
	describeSpecialAbilities = "Charm: Vampires can charm an opponent into not attacking.\n--"
		"For a given attack there is a 50% chance that their opponent does not actually attack them.";
	typeCharStr = "Vampire";
}

Vampire::~Vampire() {

}

/*********************************************************************
** Description: attack() rolls and returns the character's attack dice
*********************************************************************/
int Vampire::attack() {
	int roll = 0;
	for (int i = 0; i < numAtkDie; i++) {
		roll += atkDie->roll();
	}
	return roll;
}

/*********************************************************************
** Description: defend() takes an integer attack value and applies
** it to the defensive capabilities of the character
** also adjusts the Vampires defense response based on the Vampire's 
** special abilites
*********************************************************************/
std::string Vampire::defend(int attack) {
	int defendRoll = 0;
	for (int i = 0; i < numDefDie; i++) {
		defendRoll += defDie->roll();
	}
	std::string result;//even numbers don't in charm
	if (defendRoll % 2 == 0) {
		int totalDefense = defendRoll + this->getArmor();
		int damage = attack - totalDefense;
		if (damage < 0) {
			damage = 0;
		}
		result = this->nameStr + ", the " + this->typeCharStr + " has an armor of " + std::to_string(this->getArmor()) + " and "
			+ std::to_string(this->getStrength()) + " strength remaining." + "\nThey defended with a total roll of "
			+ std::to_string(defendRoll) + " and took " + std::to_string(damage) + " damage.";

		this->setStrength(this->getStrength() - damage);
	}
	else if (defendRoll % 2 != 0) {//odd numbers result in charm
		result = this->nameStr + ", the " + this->typeCharStr + " has an armor of " + std::to_string(this->getArmor()) + " and had "
			+ std::to_string(this->getStrength()) + " remaining. \n**They took no damage because they charmed the enemy!";
	}
	return result;
}