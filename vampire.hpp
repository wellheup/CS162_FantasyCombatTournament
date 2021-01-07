/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Vampire class derived from Character
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Character {
private:
	
protected:
	
public:
	Vampire();
	~Vampire();
	int attack();
	std::string defend(int attack);

};
#endif