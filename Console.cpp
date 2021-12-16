#include "Console.h"
void HideCursor() /*隐藏光标*/
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void setColor(unsigned short ForeColor, unsigned short backGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + backGroundColor * 0x10);//设置颜色
}
void setCursor(short x, short y)
{
	static COORD cd;

	cd.X = (short)(x << 1);
	cd.Y = y;
	HANDLE g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(g_hConsoleOutput, cd);
}