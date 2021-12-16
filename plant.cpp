#include "plant.h"
#include<iostream>
#include"Console.h"
#include"value.h"
#include"bullet.h"
#include <iomanip>

void plant::plantset(int ix, int iy, std::string iname, plant* inext, int ihealth,int iCD)
{
	x = ix;
	y = iy;
	name = iname;
	next = inext;
	health = ihealth;
	use = true;
	CD = iCD;
	round = iCD;
}
plant::plant()
{
	next = NULL;
}
void plant::eat(int zombiesAttack)
{
	health -= zombiesAttack;
	if (health <= 0)
		use = false;
}
void plant::draw()
{
	setCursor(x * Dx + 1, y * Dy + 2);
	setColor(PlantColor, PlantBackColor);
	std::cout << name;
	setCursor(x * Dx + 1, y * Dy + 3);
	std::cout<<"HP:"<< std::setw(7)<<std::left <<health;
}
int plant::addSunshine()
{
	if (name[0] == 'S')
	{
		round--;
		if (round <= 0)
		{
			round = CD;
			return 25;
		}
	}
	return 0;
}
bool plant::addBulletYes()
{
	round--;
	if (round <= 0)
	{
		round = CD;
		return true;
	}
	return false;
}