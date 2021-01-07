/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies Barbarian class derived from Character
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character {
private:
	
protected:
	
public:
	Medusa();
	~Medusa();
	int attack();
	std::string defend(int attack);

};
#endif