#include "graphics.h"

/********************************************************/
void Graphics::gotoXY(short x, short y) 
{
	HANDLE CONSOL = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(CONSOL, c);
}

/********************************************************/
void Graphics::setcolor(int attr) 
{
	HANDLE CONSOL = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(CONSOL, attr);
}