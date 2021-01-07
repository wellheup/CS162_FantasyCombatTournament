/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Character class which serves as the base
**		for all character classes
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "die.hpp"
#include "enums.hpp"
class Die; 

class Character{
private:

protected:
	int armor,
		startingStrength,
		strength,
		numDefDie,
		numAtkDie;
	std::string describeChar,
		describeRegAbilities,
		describeSpecialAbilities, 
		nameStr,
		typeCharStr;
	Die *atkDie, *defDie;
	typeChar thisChar;
public:
	
	
	Character();
	virtual ~Character();
	virtual int attack()=0;
	virtual std::string defend(int attack)=0;
	int getArmor();
	void setArmor(int armor);
	int getStrength();
	void setStrength(int strength);
	int getNumAtkDie();
	void setNumAtkDie(int numAtkDie);
	int getNumDefDie();
	void setNumDefDie(int numDefDie);
	int	getTypeChar();
	std::string getTypeCharStr();
	void setTypeChar();
	std::string getDescribeChar();
	void setNameStr(std::string nameIn);
	std::string getNameStr();
	void heal();
};
#endif