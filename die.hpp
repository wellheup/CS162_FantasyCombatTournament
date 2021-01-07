/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Die and LoadedDie classes, both of which
** generate a random simulated dice roll and return that value.
** LoadedDice will return weighted results. 
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die{

public:
	int sides = 10;
	Die() {	}
	Die(int sides) {
		setSides(sides);
	}
	virtual ~Die(){ }
	
	void setSides(int sides); 
	int getSides();

	/*********************************************************************
	** Description: Die::roll() method generates a random number for the
	** dice roll which will not be the same if called during the same
	** time frame.
	** Reference: http://www.cplusplus.com/reference/random/uniform_int_distribution/operator()/
	*********************************************************************/
	virtual int roll();
};

class LoadedDie : public Die {
private:
	int weight=10, chance = sides;
	int* chanceDistro;

public:
	LoadedDie() {
		setWeight(weight);
	}
	LoadedDie(int sides, int weight) {
		this->sides = sides;
		setWeight(weight);
	}
	~LoadedDie() override {
		delete[] chanceDistro;
		chanceDistro = nullptr;
	}
	
	/*********************************************************************
	** Description: LoadedDie::setWeight() requests the user to choose just
	** how much to multiply the chances fo rolling their maximum value by.
	** Then creates an array to represent the chances of rolling each side
	** with the weighted maximum value.
	*********************************************************************/
	void setWeight(int weight);
	
	/*********************************************************************
	** Description: LoadedDie::setWeight(int) Overloaded method to allow
	** setting weight upon construction.
	*********************************************************************/
	void setWeight();

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
	int roll() override;
};

#endif