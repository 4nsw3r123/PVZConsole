#include "zombie.h"
#include "plant.h"
#include "Console.h"
#include "bullet.h"
#include"value.h"
#include<iostream>
#include <iomanip>

zombie::zombie(int x, int y, std::string name, int speed, int attack, int health):x(x),y(y),name(name),speed(speed),attack(attack),health(health)
{	
	moveRound = speed;
	attackRound = 0;
}
zombie::zombie()
{
	use = false;
}
void zombie::move()
{
	moveRound--;
	if (stop)
		moveRound = 0;
	if (moveRound <= 0 && stop == false)
	{
		x -= 1;
		if (x <= 0)
			gameOver(1);
		moveRound = speed;
	}
}
void zombie::collision(listArray &bullet,plant (*plantLocation)[9])
{
	if (bullet.used(x, y))
	{
		health-=bullet.remove(x, y);
	}
	if (bullet.used(x+1, y))
	{
		health -= bullet.remove(x+1, y);
	}
	if (health <= 0)
		use = false;
	if (plantLocation[y][x / Dx].use == true)
	{
		stop = true;
		if (attackRound == 0)
		{
			plantLocation[y][x / Dx].eat(attack);
			attackRound = 20;
		}
		attackRound--;
	}
	if (plantLocation[y][x / Dx].use == false)
		stop = false;
}
void zombie::draw()
{
	setColor(ZombieColor, ZombieBackColor);
	setCursor(x, y * Dy + 1);
	std::cout << name;
	setCursor(x, y * Dy + 2);
	std::cout << "HP-" << std::setw(5) << std::left << health;
}
void gameOver(int num)
{
	gameover = num;
}