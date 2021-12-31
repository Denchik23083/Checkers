#include <iostream>
#include "game.h"
#include "Tests.h"

/********************************************************/
int main()
{
	TestGame my_test;
	my_test.tests();

	Game_Window window;
	bool res = window.nachalo();
	
	if (res)
	{
		Game game;
		game.start();
	}
	else
	{
		return false;
	}

	return 0;
}
