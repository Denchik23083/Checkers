#pragma once
#include <Windows.h>
#include <conio.h>
#include "graphics.h"

/********************************************************/
class Game_Window : public Graphics
{
	public://////////////////////////////////////

		Game_Window();
		~Game_Window();

	public://////////////////////////////////////
	
		bool nachalo();

	protected://////////////////////////////////////
		
		// size of console
		//
		void ToPutWindow(short X, short Y);

		//Screen
		//
		void Settings();
		void About_Game();

		//End Game
		//
		void White_Wins();
		void Black_Wins();

	protected://////////////////////////////////////
		int swich;
		int w;
		int b;
};