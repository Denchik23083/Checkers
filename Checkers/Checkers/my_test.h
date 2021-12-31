#pragma once
#if _DEBUG

#define DO_TEST(expr)	LogTest( __FILE__, __LINE__, expr, #expr )

#else // release

#define DO_TEST(expr)

#endif // _DEBUG

/***************************************************************/
void LogTest(const char* filePath, int line, bool valid, const char* exprStr);

void printTestResults();