#pragma once
#include <string>
#include "bullet.h"
#include "plant.h"
#include "listArray.h"
#define Dx 6
#define Dy 5

extern int gameover;
class zombie
{
public:	
	
	std::string name;
	int x, y;
	bool use=true;
	zombie(int x,int y,std::string name,int speed,int attack,int health);
	zombie();
	void collision(listArray &bullet, plant (*plantLocation)[9]);
	void move();
	void draw();
private:	
	int speed;
	int moveRound;
	int attack;
	int attackRound;
	int health;
	bool stop=false;
};
void gameOver(int num);
