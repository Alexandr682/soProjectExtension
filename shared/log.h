/*
*	S.T.A.L.K.E.R. Online - logging
*	Developers:
*		009 (�������� �������)
*/

#include <stdio.h>

#define TIMESTAMP

class CLog
{
public:
	CLog(char* filename);
	~CLog(void);
	void Write(const char *string, ...);
private:
	FILE* LogFile;
	char temp[256];
};