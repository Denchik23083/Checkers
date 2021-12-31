#include <iostream>
#include "Game_Window.h"

using namespace std;

/********************************************************/
Game_Window::Game_Window()
	:
	swich(0),
	w(1),
	b(1)
{
}

/********************************************************/
Game_Window::~Game_Window()
{
}

/********************************************************/
void Game_Window::ToPutWindow(short X, short Y)
{
	SetWindowPos(GetConsoleWindow(), 0, X, Y, 0, 0, SWP_NOSIZE);
}

/********************************************************/
bool Game_Window::nachalo()
{
	ToPutWindow(100, 100);
	system("mode con cols=130 lines=40");

	cout << endl;

	printf("      CCCCCCC    HHHHHHH   HHHHHHH    EEEEEEEEEEE        CCCCCCC    KKKK    K:K    EEEEEEEEEEE    RRRRRRRRRR        SSSSS   11\n");
	printf("   CCC::C        H:::::H   H:::::H    E:::::::::E     CCC::C        K::K   K:K     E:::::::::E    R::R   R:R       S::S     11\n");
	printf("  CC::C          H:::::H   H:::::H    EE::EE         CC::C          K::K  K::K     EE::EE         R::R  R:R         S::S    11\n");
	printf("  C::C           H:::::HHHHH:::::H    E:::::::::E    C::C           K::KK::K       E:::::::::E    R::RR::R           S::S   11\n");
	printf("  C::C           H:::::HHHHH:::::H    E:::::::::E    C::C           K::KK::K       E:::::::::E    R::RR::R           S::S   11\n");
	printf("  CC::C          H:::::H   H:::::H    EE::EE         CC::C          K::K  K::K     EE::EE         R::R  R:R         S::S      \n");
	printf("   CCC::C        H:::::H   H:::::H    E:::::::::E     CCC::C        K::K   K:K     E:::::::::E    R::R   R:R       S::S     11\n");
	printf("      CCCCCCC    HHHHHHH   HHHHHHH    EEEEEEEEEEE        CCCCCCC    KKKK    K:K    EEEEEEEEEEE    RRRR    RRR    SSSSS      11\n");

	cout << endl << endl << endl << endl;

	cout << "	                                                1   NEW GAME	    " << endl << endl;
	cout << "	                                                2   SETTINGS        " << endl << endl;
	cout << "	                                                3   ABOUT THE GAME	" << endl << endl;
	cout << "	                                                4   EXIT            " << endl << endl;
		
	cin >> swich;

	//if you don't click, nothing happens
	if (swich == 1)
	{
		return true;
	}
	else if (swich == 2)
	{
		Settings();
	}
	else if (swich == 3)
	{
		About_Game();
	}
	else if (swich == 4)
	{
		return false;
	}
	else
	{
		nachalo();
	}
}

/********************************************************/
void Game_Window::Settings()
{
	ToPutWindow(100, 100);
	system("mode con cols=130 lines=40");
	
	cout << endl;
		
	cout << " 1 BACK" << endl << endl;


	printf("                                                              HOW PLAY?\n");

	cout << endl << endl;

	printf("           Press arrow up, down, left, right to move the red square\n");
	cout << endl;
	printf("           Press ENTER to select a checker.\n");
	cout << endl;
	printf("           Press ENTER again to move or fight enemy checker.\n");
	cout << endl << endl;

	printf("                                                              RULES!\n");
	cout << endl << endl;
	
	printf("             _ _ _ _ _ _ _ _ \n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");
	printf("            |_|_|_|_|_|_|_|_|\n");

	cout << endl << endl;

	printf("            White moves first up the black squares.\n");
	printf("            Black moves down the black squares.\n");
	cout << endl;
	
	printf("            If you are close to the opponent's checker and through it(diagonally) there is no other checker,\n");
	printf("            then you can pick it up.\n");
	cout << endl;
	
	printf("            You can also pick up two or more at a time.\n");
	cout << endl << endl;
	
	
	printf("            Purpose of the game: take all the opponent's checkers or not give him a move.\n");
	cout << endl;

	cin >> swich;

	//if you don't click, nothing happens

	if (swich == 1)
	{
		nachalo();
	}
	else
	{
		Settings();
	}
}

/********************************************************/
void Game_Window::About_Game()
{
	ToPutWindow(100, 100);
	system("mode con cols=130 lines=40");

	cout << endl;

	cout << " 1 BACK" << endl << endl;

	printf("                                                              WHAT ARE CHECKERS!\n");
	cout << endl << endl;

	printf("            Checkers is a logical board game for two players.\n");
	printf("            Consists in moving checkers in a certain way on the cells of the checkerboard.\n");
	cout << endl << endl;

	printf("                                                              HISTORY!\n");
	cout << endl << endl;

	printf("            Checkers is a logical board game for two players.\n");
	cout << endl;

	printf("            Consists in moving checkers in a certain way on the cells of the checkerboard.\n");
	cout << endl;

	printf("            According to one of the historical versions, checkers were invented by the Greek warrior Palamed,\n");
	printf("            known as a participant in the siege of Troy.\n");
	cout << endl;

	printf("            The siege of the city lasted 10 years and in order to kill the boredom,\n");
	printf("            Palamed came up with this addicting game, perhaps by drawing cells on the ground.\n");
	cout << endl;

	printf("            The Egyptian pharaohs were also fond of checkers.\n");
	cout << endl << endl;

	printf("                                                              COMPUTER CHECKERS!\n");
	cout << endl << endl;
	
	printf("            In 2007 Jonathan Schaeffer proved that there is a win-win algorithm,\n");
	printf("            following which the player can count on a draw in English checkers,\n");
	printf("            no matter what color it plays.\n");
	cout << endl; 

	printf("            In 2010, a base of two-way endings for international drafts was built.\n");
	cout << endl;

	cin >> swich;
	
	if (swich == 1)
	{
		nachalo();
	}
	else
	{
		About_Game();
	}
}

/********************************************************/
void Game_Window::White_Wins()
{
	//clear checkers and print end
	//
	system("cls");
	
	while (!_kbhit())
	{
		Sleep(400);

		if (w == 7)
		{
			w = 1;
		}

		setcolor(FOREGROUND_BLUE + w + FOREGROUND_INTENSITY);

		ToPutWindow(100, 100);
		system("mode con cols=145 lines=40");

		cout << endl;

		printf("                 GGGGGG        A         M        M    EEEEEE          OOOOOOO     VV           VV   EEEEEE    RRRRRRRRR    11\n");
		printf("                G:::::G       A:A        MM      MM    E:E            OO     OO     VV         VV    E:E       R:R   R:R    11\n");
		printf("              G::G           A:::A       M:M    M:M    E:E           OO       OO     VV       VV     E:E       R:R   R:R    11\n");
		printf("              G::G          A::A::A      M::M  M::M    E::::E        OO       OO      VV     VV      E::::E    R:RRR:R      11\n");
		printf("              G::G         A:A   A:A     M:::MM:::M    E::::E        OO       OO       VV   VV       E::::E    R::RR::R     11\n");
		printf("              G::G  G:G   A::AAAAA::A    MM      MM    E:E           OO       OO        VV:VV        E:E       R:R   R:R      \n");
		printf("                G:::::G  A:A       A:A   MM      MM    E:E            OO     OO          V:V         E:E       R:R    R:R   11\n");
		printf("                 GGGGGG A:A         A:A  MM      MM    EEEEEE          OOOOOOO            V          EEEEEE    RRRR    RRR  11\n");

		cout << endl << endl << endl << endl << endl << endl << endl << endl;

		printf("  WW                    WW   HH       HH  III   TTTTTTTTTTTT   EEEEEE          WW                    WW  III    NNN       NN       SSSSS   11\n");
		printf("   WW                  WW    HH       HH            TTT        E:E              WW                  WW          NN:N      NN      S::S     11\n");
		printf("    WW                WW     HH       HH  III       TTT        E:E               WW                WW    III    NN::N     NN       S::S    11\n");
		printf("     WW              WW      HH:::::::HH  III       TTT        E::::E             WW              WW     III    NN N:N    NN        S::S   11\n");
		printf("      WW     WW     WW       HH:::::::HH  III       TTT        E::::E              WW     WW     WW      III    NN  N::N  NN        S::S   11\n");
		printf("       W::::W  W::::W        HH       HH  III       TTT        E:E                  W::::W  W::::W       III    NN   N::N NN       S::S      \n");
		printf("        W::W    W::W         HH       HH  III       TTT        E:E                   W::W    W::W        III    NN    N:::NN      S::S     11\n");
		printf("         WW      WW          HH       HH  III       TTT        EEEEEE                 WW      WW         III    NN     N::NN    SSSSS      11\n");
		
		w++;
	}
}

/********************************************************/
void Game_Window::Black_Wins()
{
	//clear checkers and print end
	//
	system("cls");
	
	while (!_kbhit())
	{
		Sleep(400);
	
		if (b == 7)
		{
			b = 1;
		}
		
		setcolor(FOREGROUND_BLUE + b + FOREGROUND_INTENSITY);
	
		ToPutWindow(100, 100);
		system("mode con cols=145 lines=40");

		cout << endl;

		printf("                 GGGGGG        A         M        M    EEEEEE          OOOOOOO     VV           VV   EEEEEE    RRRRRRRRR    11\n");
		printf("                G:::::G       A:A        MM      MM    E:E            OO     OO     VV         VV    E:E       R:R   R:R    11\n");
		printf("              G::G           A:::A       M:M    M:M    E:E           OO       OO     VV       VV     E:E       R:R   R:R    11\n");
		printf("              G::G          A::A::A      M::M  M::M    E::::E        OO       OO      VV     VV      E::::E    R:RRR:R      11\n");
		printf("              G::G         A:A   A:A     M:::MM:::M    E::::E        OO       OO       VV   VV       E::::E    R::RR::R     11\n");
		printf("              G::G  G:G   A::AAAAA::A    MM      MM    E:E           OO       OO        VV:VV        E:E       R:R   R:R      \n");
		printf("                G:::::G  A:A       A:A   MM      MM    E:E            OO     OO          V:V         E:E       R:R    R:R   11\n");
		printf("                 GGGGGG A:A         A:A  MM      MM    EEEEEE          OOOOOOO            V          EEEEEE    RRRR    RRR  11\n");

		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		
		printf("  BBBBBBB    LL               A               CCCCCCC    KKKK    K:K          WW                    WW  III    NNN       NN       SSSSS   11\n");
		printf("  BB   BBB   LL              A:A           CCC::C        K::K   K:K            WW                  WW          NN:N      NN      S::S     11\n");
		printf("  BB  BBB    LL             A:::A         CC::C          K::K  K::K             WW                WW    III    NN::N     NN       S::S    11\n");
		printf("  BB::BB     LL            A::A::A        C::C           K::KK::K                WW              WW     III    NN N:N    NN        S::S   11\n");
		printf("  BB::BB     LL           A:A   A:A       C::C           K::KK::K                 WW     WW     WW      III    NN  N::N  NN        S::S   11\n");
		printf("  BB  BBB    LL          A::AAAAA::A      CC::C          K::K  K::K                W::::W  W::::W       III    NN   N::N NN       S::S      \n");
		printf("  BB   BBB   LL         A:A       A:A      CCC::C        K::K   K:K                 W::W    W::W        III    NN    N:::NN      S::S     11\n");
		printf("  BBBBBBB    LLLLLLL   A:A         A:A        CCCCCCC    KKKK    K:K                 WW      WW         III    NN     N::NN    SSSSS      11\n");

		b++;
	}
}