#include <iostream>
#include "Tests.h"

/********************************************************/
void TestGame::tests()
{
	test_IsCorrectPos();
}

/********************************************************/
void TestGame::test_IsCorrectPos()
{
	//y and x (0-7)
	//
	bool testbool;
		
	testbool = IsCorrectPos(5, 6);
	DO_TEST(testbool == 1);
	
	testbool = IsCorrectPos(10, 4);
	DO_TEST(testbool == 0);

	testbool = IsCorrectPos(0, 0);
	DO_TEST(testbool == 1);

	testbool = IsCorrectPos(7, 7);
	DO_TEST(testbool == 1);

	testbool = IsCorrectPos(7, 8);
	DO_TEST(testbool == 0);

	testbool = IsCorrectPos(8, 8);
	DO_TEST(testbool == 0);

	testbool = IsCorrectPos(-1, -1);
	DO_TEST(testbool == 0);

	printTestResults();
}