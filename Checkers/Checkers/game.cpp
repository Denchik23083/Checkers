#include <iostream>
#include <windows.h>
#include "game.h"

using namespace std;

/********************************************************/
Game::Game()
	:
	//state default is white select
	//
	Game_state(GameState::SELECT_WHITE),
	boardSize(8),

	//this is for select green kvadrat. Default he is not on board, but if we select, he is on this checker
	//
	x(-1),
	y(-1)
{
	//create a one-dimensional array
	//
	board = new Cell_State[boardSize * boardSize];

	//fill it with empty cells(by default)
	//
	for (size_t i = 0; i < boardSize * boardSize; i++)
	{
		board[i] = Empty;
	}
}

/********************************************************/
Game::~Game()
{
	delete[] board;
}

/********************************************************/
void Game::Score_White()
{
	//add 20 point if you fight	
	//
	static int WhiteScore = -20;
	WhiteScore = WhiteScore + 20;

	gotoXY(55, 10);
	setcolor(FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_RED);
	cout << "White Score: " << WhiteScore << endl;

	//end game
	//
	if (WhiteScore == 240)
	{
		White_Wins();
		Close = false;
	}
}

/********************************************************/
void Game::Score_Black()
{
	//add 20 point if you fight	
	//
	static int BlackScore = -20;
	BlackScore = BlackScore + 20;

	gotoXY(55, 11);
	setcolor(FOREGROUND_GREEN + FOREGROUND_BLUE + FOREGROUND_RED);
	cout << "Black Score: " << BlackScore << endl;

	//end game
	//
	if (BlackScore == 240)
	{
		Black_Wins();
		Close = false;
	}
}

/********************************************************/
void Game::start()
{
	int key;
	Close = true;
	system("mode con cols=80 lines=30");

	init();
	Score_White();
	Score_Black();

	do {
		if (Close == true)
		{
			show();
			key = get_key();
			state_game(key);
		}
		else
		{
			return;
		}
	} while (key != 'q'); //пока не нажали клавишу q мы будем играть
}
/********************************************************/
void Game::init()
{
	//int board 8x8 fill checkers
	//
	for (size_t y = 0; y < boardSize; y++)
	{
		for (size_t x = 0; x < boardSize; x++)
		{
			//we need that x = 1
			//
			if (y == 0 && x % 2 != 0)
			{
				board[y * boardSize + x] = Black;
			}

			//we need that x = 0
			//
			else if (y == 1 && x % 2 == 0)
			{
				board[y * boardSize + x] = Black;
			}
			else if (y == 2 && x % 2 != 0)
			{
				board[y * boardSize + x] = Black;
			}
			else if (y == 5 && x % 2 == 0)
			{
				board[y * boardSize + x] = White;
			}
			else if (y == 6 && x % 2 != 0)
			{
				board[y * boardSize + x] = White;
			}
			else if (y == 7 && x % 2 == 0)
			{
				board[y * boardSize + x] = White;
			}
			else
			{
				board[y * boardSize + x] = Empty;
			}
		}
	}
}

/********************************************************/
void Game::color(size_t i, size_t j, int c)
{
	//red kvatrat
	//
	if (xcur == j && ycur == i)
	{
		c |= BACKGROUND_RED;
	}

	//selest green
	//
	else if (x == j && y == i)
	{
		c |= BACKGROUND_GREEN;
	}

	//color of board
	//
	else if ((i + j) % 2 == 0)
	{
		c |= BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	}
	else
	{
		c |= BACKGROUND_INTENSITY;
	}

	setcolor(c);
}

/********************************************************/
int Game::convert(size_t y, size_t x, char& s1, char& s2)
{
	int convert_c;

	//draw checkers on board with his color
	//
	switch (board[x + y * boardSize])
	{
	case Cell_State::Black:

		//color black
		//
		convert_c = 0;
		s1 = '(';
		s2 = ')';
		break;
	case Cell_State::White:

		//color white
		//
		convert_c = 15;
		s1 = '(';
		s2 = ')';
		break;

		//no color
		//
	default:
		convert_c = 0;
		s1 = ' ';
		s2 = ' ';
	}

	return convert_c;
}

/********************************************************/
void Game::show()
{
	//board on console
	gotoXY(0, 1);

	int show_c;
	char s1, s2;

	for (size_t i = 0; i < boardSize; i++)
	{
		for (size_t j = 0; j < boardSize; j++)
		{
			//referring to the board
			//
			show_c = convert(i, j, s1, s2);

			color(i, j, show_c);

			//draw a litte cells
			//
			cout << ' ' << ' ' << ' ';
			cout << ' ' << ' ' << ' ';
		}
		cout << "\n";
		for (size_t j = 0; j < boardSize; j++)
		{
			show_c = convert(i, j, s1, s2);
			color(i, j, show_c);

			cout << ' ' << ' ' << s1;
			cout << s2 << ' ' << ' ';
		}
		cout << "\n";
		for (size_t j = 0; j < boardSize; j++)
		{
			show_c = convert(i, j, s1, s2);
			color(i, j, show_c);
			cout << ' ' << ' ' << ' ';
			cout << ' ' << ' ' << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}

/********************************************************/
int Game::get_key()
{
	//Returns the key that was pressed
	//
	int k;
	k = _getch();

	if (k == 224)
	{
		k = _getch();
	}
	return k;
}

/********************************************************/
void Game::Clear_After_Move(Cell_State g)
{
	// Check what checker move
	//	
	board[ycur * boardSize + xcur] = g;

	//clear after move
	//
	board[y * boardSize + x] = Empty;
}

/********************************************************/
bool Game::IsCorrectPos(size_t y, size_t x)
{
	return boardSize > x && boardSize > y && x >= 0 && y >= 0;
}

/********************************************************/
bool Game::IsMoveDouble(Cell_State g)
{
	return
		// if after fight stay enemy checker
		//
		(IsCorrectPos(ycur - 1, xcur - 1) && board[(ycur - 1) * boardSize + xcur - 1] == g

			// and after enemy is empty cell. You can fight again
			//
			&& IsCorrectPos(ycur - 2, xcur - 2) && board[(ycur - 2) * boardSize + xcur - 2] == Empty)

		|| (IsCorrectPos(ycur + 1, xcur + 1) && board[(ycur + 1) * boardSize + xcur + 1] == g
			&& IsCorrectPos(ycur + 2, xcur + 2) && board[(ycur + 2) * boardSize + xcur + 2] == Empty)

		|| (IsCorrectPos(ycur - 1, xcur + 1) && board[(ycur - 1) * boardSize + xcur + 1] == g
			&& IsCorrectPos(ycur - 2, xcur + 2) && board[(ycur - 2) * boardSize + xcur + 2] == Empty)

		|| (IsCorrectPos(ycur + 1, xcur - 1) && board[(ycur + 1) * boardSize + xcur - 1] == g
			&& IsCorrectPos(ycur + 2, xcur - 2) && board[(ycur + 2) * boardSize + xcur - 2] == Empty);
}

/********************************************************/
void Game::state_game(int k)
{
	//move red kvadrat. Use enum Key
	//
	switch (k)
	{
		// move right
		//
	case Key::KRight:
		if (xcur < boardSize - 1)
			xcur++;
		break;
		//move left
		//
	case Key::KLeft:
		if (xcur >= 1)
			xcur--;
		break;
		//move up
		//
	case Key::KUp:
		if (ycur >= 1)
			ycur--;
		break;
		//move down
		//
	case Key::KDown:
		if (ycur < boardSize - 1)
			ycur++;
		break;

		/*******************************************************************************/
		// select checkers and moves
	case Key::KEnter:
		switch (Game_state)
		{
			/*******************************************************************************/
		case SELECT_WHITE:

			//если мы нашли тут шашку то присваиваем ей координаты
			if (board[ycur * boardSize + xcur] == White)
			{
				x = xcur;
				y = ycur;

				//сдесь мы меняем состояние на ход белых
				Game_state = MOVE_WHITE;

			}
			break;

			/*******************************************************************************/
		case SELECT_BLACK:

			if (board[ycur * boardSize + xcur] == Black)
			{
				x = xcur;
				y = ycur;

				Game_state = MOVE_BLACK;
			}
			break;

			/*******************************************************************************/
		case MOVE_WHITE:

			//координату y(вверх вниз) мы уменьшаем или увеличиваем на 1.
			//Но шашка может двигаться как в лево так и вправо. поэтому мы берем по модулю и оно должно равняться 1
			if (ycur == y - 1 && abs(xcur - x) == 1)
			{

				//пока эта ячейка на которой стоит шашка не стала пустой, то мы вибираем
				if (board[ycur * boardSize + xcur] != Empty)
				{
					Game_state = SELECT_WHITE;
				}

				//или же мы выбрали куда ходить, тогда обращаемся к функции класса Clear_After_Move(которая очищает клетку)
				else
				{
					Clear_After_Move(White);
					Game_state = SELECT_BLACK;
				}
				//это сброс хода(если нужно)
				x = y = -1;
			}

			/*******************************************************************************/
			//White fight
			//

			//мы координату y и x уменьшаем на 2. Только в отличии от y, это работает как вниз так и вверх.
			//Но оно может быть отрицательным и поэтому мы берем по модулю(abs) 
			else if (ycur == y - 2 && abs(xcur - x) == 2)
			{
				//смотрим есть ли перед нами шашка противника и есть ли после нее пустая клетка.
				//так как мы указали что мы будем ходить на 2 клеточки, то мы должны сделать проверку (/2). Так мы узнаем есть ли там шашка противника
				if (board[ycur * boardSize + xcur] == Empty && board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] == Black)
				{
					//очищает клетку
					Clear_After_Move(White);
					//если успешный бой то шашка противника стираеться
					board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] = Empty;
					Score_White();

					//так-же мы смотрим, можно ли побить 2 раза 
					if (IsMoveDouble(Black))
					{
						//если можем то возвращаем бой белым
						Game_state = MOVE_WHITE;
						x = xcur;
						y = ycur;
					}
					else
					{
						//если нет то выбирает притивник
						Game_state = SELECT_BLACK;
						x = y = -1;
					}
				}
				else
				{
					//просто выбор, как походить(может он и не хочет бить)
					Game_state = SELECT_WHITE;
					x = y = -1;
				}
			}

			/*******************************************************************************/
			//White fight back

			//тоже самое только в бое вперед мы делали (y-2) а сдесь (y+2)
			else if (ycur == y + 2 && abs(xcur - x) == 2)
			{
				if (board[ycur * boardSize + xcur] == Empty && board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] == Black)
				{
					Clear_After_Move(White);
					board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] = Empty;
					Score_White();

					if (IsMoveDouble(Black))
					{
						Game_state = MOVE_WHITE;
						x = xcur;
						y = ycur;
					}
					else
					{
						Game_state = SELECT_BLACK;
						x = y = -1;
					}
				}
				else
				{
					Game_state = SELECT_WHITE;
					x = y = -1;
				}
			}
			break;

			/*******************************************************************************/
		case MOVE_BLACK:
			if (ycur == y + 1 && abs(xcur - x) == 1)
			{
				if (board[ycur * boardSize + xcur] != Empty)
				{
					Game_state = SELECT_BLACK;
				}
				else
				{
					Clear_After_Move(Black);
					Game_state = SELECT_WHITE;
				}
				x = y = -1;
			}

			/*******************************************************************************/
			//Black fight
			else if (ycur == y + 2 && abs(xcur - x) == 2)
			{
				if (board[ycur * boardSize + xcur] == Empty && board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] == White)
				{
					Clear_After_Move(Black);
					board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] = Empty;
					Score_Black();

					if (IsMoveDouble(White))
					{
						Game_state = MOVE_BLACK;
						x = xcur;
						y = ycur;
					}
					else
					{
						Game_state = SELECT_WHITE;
						x = y = -1;
					}
				}
				else
				{
					Game_state = SELECT_BLACK;
					x = y = -1;
				}
			}

			/*******************************************************************************/
			//Black fight back
			else if (ycur == y - 2 && abs(xcur - x) == 2)
			{
				if (board[ycur * boardSize + xcur] == Empty && board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] == White)
				{
					Clear_After_Move(Black);
					board[(ycur * boardSize + y * boardSize) / 2 + (xcur + x) / 2] = Empty;
					Score_Black();

					if (IsMoveDouble(White))
					{
						Game_state = MOVE_BLACK;
						x = xcur;
						y = ycur;
					}
					else
					{
						Game_state = SELECT_WHITE;
						x = y = -1;
					}
				}
				else
				{
					Game_state = SELECT_BLACK;
					x = y = -1;
				}
			}
			break;

		default:
			break;
		}
	default:
		break;
	}
}