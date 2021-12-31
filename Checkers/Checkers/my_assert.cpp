#include <fstream>

using namespace std;

/***************************************************************/
// Singlenton.
//
// static create log file once, future it lives until end of program.
// So, log file is not closed-opened each time.
//
ofstream& getAssertLog()
{
	static ofstream log("log_asserts.txt");

	return log;
}

/***************************************************************/
// C:\fffffff\dddddd\ssssssss\ererrrrr\file.cpp0
// 									   ^
//
static const char* extractFileName(const char* filePath)
{
	const char* p = filePath + strlen(filePath) - 1;

	while (*p != '/' && p > filePath)
		--p;

	return ++p;
}

/***************************************************************/
void LogAssert(const char* filePath, int line, bool valid, const char* exprStr)
{
	ofstream& logAssert = getAssertLog();

	if (!valid)
	{
		logAssert
			<< extractFileName(filePath) << ':'
			<< line << ':'
			<< exprStr
			<< endl;
	}
}