#include "listArray.h"
void listArray::add(int x, int y)
{
	Bullet bullet(x,y,1,10);
	array[y][x].push_back(bullet);
	if(array[y][x].size()==1)
		headList.push_back(&array[y][x]);
}
void listArray::move()
{
	for (auto p=headList.begin();p!=headList.end();p++)
	{
		for (auto bullet=(*p)->begin();bullet!=(*p)->end();bullet++)
		{
			bullet->round--;
			if (bullet->round <= 0)
			{
				bullet->round = 10;
				Bullet a = *bullet;
				a.x += 1;
				if (a.x <= Dx * 9-1)
				{
					array[a.y][a.x].push_back(a);
					if (array[a.y][a.x].size() == 1)
					{
						headList.push_back(&array[a.y][a.x]);
					}
				}
				bullet = (*p)->erase(bullet);
				if (bullet == (*p)->end())
				{					
					break;
				}				
			}
		}
		if ((*p)->empty())
		{
			p=headList.erase(p);
			if (p == headList.end())
				break;
		}
	}
}
int listArray::remove(int x, int y)
{
	int attack=0;
	if (used(x,y))
	{
		for (auto i : array[y][x])
		{
			attack += i.attack;
		}
		array[y][x].clear();
	}
	return attack;	
}
bool listArray::used(int x, int y)
{
	if (!array[y][x].empty())
	{
		return true;
	}
	return false;
}
void listArray::draw()
{
	for (auto p = headList.begin(); p != headList.end(); p++)
	{
		if (!(*p)->empty())
		{
			setCursor((*p)->begin()->x, (*p)->begin()->y*Dy+1);
			setColor(BulletColor, MapColor);
			std::cout <<"¡ö";
		}
	}
}