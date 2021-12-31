#pragma once
#include "graphics.h"
#include "Game_Window.h"

//игровая доска(матрица) в которой содержатся ячейки (состояние) B, W, E

/********************************************************/
enum Key {
	KRight = 77,
	KLeft = 75,
	KUp = 72,
	KDown = 80,
	KEnter = 13,
};

/********************************************************/
enum Cell_State { White, Black, Empty };
enum GameState { SELECT_WHITE, SELECT_BLACK, MOVE_WHITE, MOVE_BLACK };

/********************************************************/
class Game : public Game_Window
{
	public://////////////////////////////////////
		Game();
		~Game();

	public://////////////////////////////////////

		void start();

	protected://////////////////////////////////////

		//do board
		void init();

		//draw board
		void show();

		//Score of game
		void Score_White();
		void Score_Black();

		//возвращает клавишу которую нажали
		int get_key();

		//red kvadrat move
		void state_game(int k);

		void Clear_After_Move(Cell_State g);

		//red kvadrat and select checker
		void color(size_t i, size_t j, int c);

		//check where is checkers and draw ()
		int convert(size_t i, size_t j, char& s1, char& s2);

		//check after fight if we can fight again
		bool IsCorrectPos(size_t y, size_t x);

		//fight double
		bool IsMoveDouble(Cell_State g);

	protected://////////////////////////////////

		Cell_State* board;
		GameState Game_state;

		//fix value board
		const int boardSize;

		//coordinata checker
		int x;
		int y;

		//coordinata which checker can move
		int xcur;
		int	ycur;

		//if game end, break console
		bool Close;
};


