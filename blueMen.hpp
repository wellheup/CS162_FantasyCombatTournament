/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies blueMen class derived from Character
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character {
private:
	
protected:
	
public:
	BlueMen();
	~BlueMen();
	int attack();
	std::string defend(int attack);

};
#endif