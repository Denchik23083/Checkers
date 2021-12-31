#include <fstream>
#include <iostream>

using namespace std;

/**********************************************************************************************/
int gFail = 0;
int gDone = 0;

/**********************************************************************************************/
// Singlenton.
//
// static create log file once, future it lives until end of program.
// So, log file is not closed-opened each time.
//
ofstream& getTestLog()
{
	static ofstream log("log_tests.txt", ios_base::app);

	return log;
}

/**********************************************************************************************/
// C:\fffffff\dddddd\ssssssss\ererrrrr\file.cpp0
// 									   ^
static const char* extractFileName(const char* filePath)
{
	const char* p = filePath + strlen(filePath) - 1;

	while (*p != '\\' && p > filePath)
		--p;

	return ++p;
}

/**********************************************************************************************/
void LogTest(const char* filePath, int line, bool valid, const char* exprStr)
{
	ofstream& logTests = getTestLog();

	if (valid)
	{
		logTests << "DONE: ";
		gDone++;
	}
	else
	{
		logTests << "FAIL: ";
		gFail++;
	}

	logTests
		<< extractFileName(filePath) << ':'
		<< line << ':'
		<< exprStr
		<< endl;
}

/**********************************************************************************************/

void printTestResults()
{
	ofstream& logTests = getTestLog();
	cout << endl;

	logTests
		<< endl
		<< "******************************************" << endl
		<< "TOTAL: " << gDone + gFail << endl
		<< "DONE : " << gDone << endl
		<< "FAIL : " << gFail << endl
		<< "******************************************" << endl << endl;
}