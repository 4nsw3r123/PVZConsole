#pragma once
#include <string>
#include"value.h"
#include"bullet.h"
class plant
{
public:
	std::string name;
	int x, y;
	bool use=false;
	plant *next;
	plant();
	void plantset(int x, int y, std::string name, plant* next, int health,int CD);	
	void eat(int zombiesAttack);
	void draw();
	int addSunshine();
	bool addBulletYes();
private:
	int health;
	int CD;
	int round;
};
