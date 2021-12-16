#pragma once
#include"bullet.h"
#include"value.h"
#include<list>
#include"Console.h"
class listArray
{
	std::list<Bullet> array[6][Dx * 9];
	std::list<std::list<Bullet>*> headList;
public:	
	void add(int x, int y);
	void move();
	int remove(int x, int y);
	bool used(int x, int y);
	void draw();
};

