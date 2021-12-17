#include <iostream>
#include "value.h"
#include "bullet.h"
#include "Console.h"
#include "plant.h"
#include "value.h"
#include "zombie.h"
#include "listArray.h"
#include <string>
#include <thread>
#include <conio.h>
#include <list>
#include <iomanip>
#include <string.h>
bool zombieHere[6];
plant(*plantLocation)[9] = new plant[6][9]();
int x = 0, y = 0;
int plantChoice = 0;
int sunshine=50;
plant* plantHead = new plant;
std::list<zombie> zombielist;
int plantPrice[4] = { 50,100,200,50 };
int gameover=0;
int count=0;
int zombies[][3] =
{
	{600,0,0},
	{1200,0,0},	{1201,1,0},	{1202,2,0},//12
	{1800,0,0},	{1801,1,0},	{1802,2,0},	{1803,3,0},	{1804,4,0},	{1805,5,0},
	{1900,0,0},	{1901,1,0},	{1902,2,0},	{1903,3,0},	{1904,4,0},	{1905,5,0},
	{2400,0,1}, {2401,1,1},	{2402,2,1},	{2403,3,1},	{2404,4,1},	{2405,5,1},
	{3600,0,0}, {3601,1,0},	{3602,2,0},	{3603,3,0},	{3604,4,0},	{3605,5,0},
	{3700,0,1}, {3701,1,1},	{3702,2,1},	{3703,3,1},	{3704,4,1},	{3705,5,1},
	{4200,0,2}, {4201,1,2},	{4202,2,2},	{4203,3,2},	{4204,4,2},	{4205,5,2},
	{4300,0,0}, {4301,1,0},	{4302,2,0},	{4303,3,0},	{4304,4,0},	{4305,5,0},
	{4400,0,0}, {4401,1,0},	{4402,2,0},	{4403,3,0},	{4404,4,0},	{4405,5,0},
	{4800,2,3}, {4801,4,4}
};

void initLine()
{
	setCursor(0, 0);
	setColor(0, MapColor);
	std::cout <<
		"┏━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┳━━━━━━━━━━━┓ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━╋━━━━━━━━━━━┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃           ┃ \n"
		"┗━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┻━━━━━━━━━━━┛ \n";
}
void cursorDraw()
{
	setCursor(x * Dx + 1, y * Dy + 4);
	setColor(CursorColor, MapColor);
	std::cout<<"__________";
	setColor(0xA, 0);
}


int loop()
{
	listArray bullet;
	int ZombiesIndex = 0;
	//count = 5000;
	while (gameover == 0)
	{
		count++;
		initLine();
		if (zombies[ZombiesIndex][0] == count)
		{
			zombie* a=NULL;
			switch (zombies[ZombiesIndex][2])
			{
			case 0:a = new zombie(Dx * 9 - 10, zombies[ZombiesIndex][1], "Zombie  ", 40, 1, 6);				
				break;
			case 1:a = new zombie(Dx * 9 - 10, zombies[ZombiesIndex][1], "Conehead", 40, 1, 15);		
				break;
			case 2:a = new zombie(Dx * 9 - 10, zombies[ZombiesIndex][1], "Football", 20, 2, 40);
				break;
			case 3:a = new zombie(Dx * 9 - 10, zombies[ZombiesIndex][1], "DemonKing Liki!", 20, 100, 120);
				break;
			case 4:a = new zombie(Dx * 9 - 10, zombies[ZombiesIndex][1], "De13ted 4k1Ra!", 20, 100, 120);
				break;
			default:break;
			}
			zombielist.push_front(*a);
			ZombiesIndex++;
		}
		if (count % 500 == 0)
			sunshine += 25;
		for (plant* p = plantHead; p->next != NULL; p = p->next)
		{
			if (p->next->use)
			{
				p->next->draw();
				sunshine+=p->next->addSunshine();
				if (zombieHere[p->next->y]&&(p->next->name[0]=='P'||p->next->name[0]=='R'))
				{
					if (p->next->addBulletYes())
					{
						if (p->next->name[0] == 'P')
						{
							bullet.add(p->next->x * Dx + 3, p->next->y);
						}
						else if (p->next->name[0] == 'R')
						{
							bullet.add(p->next->x * Dx + 4, p->next->y);
							bullet.add(p->next->x * Dx + 3, p->next->y);
						}
					}
				}
			}
			else
			{
				p->next = p->next->next;
				if (p->next == NULL)
					break;
			}
		}
		for (int i = 0; i < 6; i++)
			zombieHere[i] = false;
		bullet.move();
		bullet.draw();
		for (auto i = zombielist.begin(); i != zombielist.end(); i++)
		{
			if (i->use)
			{
				zombieHere[i->y] = true;
				i->move();
				i->collision(bullet, plantLocation);
				if(i->use)
					i->draw();
			}
			else
			{
				i = zombielist.erase(i);
				if (i== zombielist.end())
					break;
			}
		}
		cursorDraw();
		setCursor(0, 6 * Dy+1);
		setColor(SunshineColor, BackGroundColor);
		std::cout << "sunShine:" << std::setw(5) << sunshine;
		setColor(PlantChooseColor, BackGroundColor);
		std::cout<< "                   plant:";
		switch (plantChoice)
		{
		case 0:std::cout << "SunFlower                         "; break;
		case 1:std::cout << "PeaShooter                        "; break;
		case 2:std::cout << "Repeater                          "; break;
		case 3:std::cout << "Wall-nut                          "; break;
		}
		setColor(ProcessBarColor, BackGroundColor);
		std::cout<<'[';
		for (int i = 0; i < 10; i++)
		{
			if ((4800 - count) / 4800.0 * 10 > i)
				std::cout<<'=';
			else
				std::cout<<'<';
		}
		std::cout << "]                         "<< std::flush;
		if (count > 4800 && zombielist.empty())
		{
			gameOver(2);
			break;
		}
		Sleep(50);
	}
	system("cls");
	if (gameover == 1)
	{
		setColor(4, 14);
		setCursor(0,10);
		std::cout << "                    ZZZZZ  OOO  M   M BBBB  III EEEEE       EEEEE   A   TTTTT\n"
					 "                       Z  O   O MM MM B   B  I  E           E      A A    T\n"
					 "                      Z   O   O M M M BBBB   I  EEEE        EEEE  AAAAA   T\n"
					 "                     Z    O   O M   M B   B  I  E           E     A   A   T\n"
					 "                    ZZZZZ  OOO  M   M BBBB  III EEEEE       EEEEE A   A   T\n\n"

					 "                    V   V III DDDD    A   RRRR        TTTTT W   W  OOO    !\n"
					 "                    V   V  I  D   D  A A  R   R         T   W   W O   O   !\n"
					 "                    V   V  I  D   D AAAAA RRRR   ---    T   W W W O   O   !\n"
					 "                     V V   I  D   D A   A R  R          T   W W W O   O    \n"
					 "                      V   III DDDD  A   A R   R         T    W W   OOO    !\n" << std::endl;
			
	}
	else
	{
		setColor(1,14);
		setCursor(0, 12);
		std::cout <<
			"                            Y   Y  OOO  U   U       W   W III N   N  !\n"
			"                             Y Y  O   O U   U       W   W  I  NN  N  !\n"
			"                              Y   O   O U   U       W W W  I  N N N  !\n"
			"                              Y   O   O U   U       W W W  I  N  NN   \n"
			"                              Y    OOO   UUU         W W  III N   N  !\n" << std::endl;
	}
	return 0;
}
void welcome()
{
	COORD buffer;
	buffer.X = 300;
	buffer.Y = 33;
	SetConsoleScreenBufferSize(stdout, buffer);
	std::ios::sync_with_stdio(false);
	HideCursor();
	system("mode con cols=110 lines=32");
	system("color 0A");
	setCursor(0, 10);
	std::cout <<
		"                    ╔═══════════════════════════════════════════════════════════════════╗\n"
		"                    ║   Welcome to my Console PVZ!                                      ║\n"
		"                    ║   Use w,a,s,d keys to choose location, q,e keys to switch plant,  ║\n"
		"                    ║   space to plant a plant, and c to delete a plant!                ║\n"
		"                    ║   To make the game easy, you don't need to collect sunshine,      ║\n"
		"                    ║   the sunshine will be collected automatically!                   ║\n"
		"                    ║   the plant you have:SunFlower,Peashooter,Repeater,Wall-nut!      ║\n"
		"                    ║   Are you ready (please press Enter) ?                            ║\n" 
		"                    ╚═══════════════════════════════════════════════════════════════════╝\n"<< std::endl;
	if (_getch() == '\r')
		return;
}
void choiceMode()
{
	int ch;
	while ((ch = _getch())&&gameover==0)
	{
		switch (ch)
		{
		case 'w':y -= (y - 1 < 0 ? 0 : 1); break;
		case 's':y += (y + 1 > 5 ? 0 : 1); break;
		case 'a':x -= (x - 1 < 0 ? 0 : 1); break;
		case 'd':x += (x + 1 > 8 ? 0 : 1); break;
		case 'q':plantChoice = (plantChoice + 3) % 4; break;
		case 'e':plantChoice = (plantChoice + 1) % 4; break;
		case ' ':
			if (!plantLocation[y][x].use && sunshine - plantPrice[plantChoice] >= 0)
			{
				switch(plantChoice)
				{ 
				case 0:
					plantLocation[y][x].plantset(x, y, "SunFlower ", plantHead->next, 6,200);
					sunshine -= 50;
					break;
				case 1:
					plantLocation[y][x].plantset(x, y, "PeaShooter", plantHead->next,6,40);
					sunshine -= 100;
					break;
				case 2:
					plantLocation[y][x].plantset(x, y, "Repeater  ", plantHead->next,6,40);
					sunshine -= 200;
					break;
				case 3:
					plantLocation[y][x].plantset(x, y, "Wall-nut  ", plantHead->next,60,0);
					sunshine -= 50;
					break;
				}	
				plantLocation[y][x].next = plantHead->next;
				plantHead->next = &plantLocation[y][x];
			}
			break;
		case 'c':
			plantLocation[y][x].use = false;
			break;
		}
	}
}
int main()
{
	//system("chcp 65001");
	welcome();
	/*
	bullet[0][3] = 1;
	bullet[1][3] = 1;
	bullet[2][3] = 1;
	bullet[3][3] = 1;
	bullet[4][3] = 1;
	bullet[5][3] = 1;*/

	
	//zombiesLocation[4][Dx * 9 - 10] = zombies[1];
	//zombiesLocation[5][Dx * 9 - 10] = zombies[2];
	std::thread bulletThread(loop);
	//zombie* a;
	//a = new zombie(1, 0, "Zombie  ", 40, 1, 6);
	//zombielist.push_front(*a);
	choiceMode();
	bulletThread.join();
	getchar();
	return 0;
}
