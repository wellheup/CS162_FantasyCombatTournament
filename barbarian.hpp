/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Barbarian class derived from Character
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Character {
private:
	
protected:
	
public:
	Barbarian();
	~Barbarian();
	int attack();
	std::string defend(int attack);

};
#endif