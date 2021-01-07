/*********************************************************************
** Author: Phillip Wellheuser							CS 162-400
** Date: 5/26/19
** Description: Specifies HarryPotter class derived from Character
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character {
private:
	
protected:
	bool hasHogwartsed;
public:
	HarryPotter();
	~HarryPotter();
	int attack();
	std::string defend(int attack);
	void hogwarts();
};
#endif