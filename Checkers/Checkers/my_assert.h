#pragma once
/***************************************************************/
#if _DEBUG

#define MY_ASSERT(expr)	 LogAssert( __FILE__, __LINE__, expr, #expr )

#else // release

#define MY_ASSERT(expr)

#endif // _DEBUG

/***************************************************************/
// Do not call this function directly.
// It will be called via macro MY_ASSERT().
//
void LogAssert(const char* filePath, int line, bool valid, const char* exprStr);