/*
*	S.T.A.L.K.E.R.- IConsole_Command class
*	Disassembly by:
*		009 (Михайлов Алексей)
*/


class __declspec(dllimport) IConsole_Command
{
public:
	IConsole_Command(char const *);
	~IConsole_Command();

	void InvalidSyntax(void);
	/*
	virtual void Status(char (&)[256]);
	virtual void Info(char (&)[256]);
	virtual void Save(class IWriter *);
	*/
	//void Info(char(&)[256]);

	void* ftable;
	char* cmd_name;
	unsigned char flag1;
	unsigned char flag2;
	unsigned char is_custom;
	unsigned char unknown[0x10];
};
class __declspec(dllimport) CCC_Integer:public IConsole_Command
{
protected:
	int* value;
	int minm, maxi;
public:
	CCC_Integer(char const* N, int* V, int _min, int _max) :
		IConsole_Command(N),
		value(V),
		minm(_min),
		maxi(_max)
	{};
};
class __declspec(dllimport) CCC_Float:public IConsole_Command
{
public:
	float mini, maxi;
	float* valuef;
public:
	CCC_Float(const char* N, float* V, float _min, float _max) :
		IConsole_Command(N),
		valuef(V),
		mini(_min),
		maxi(_max)
	{};	
};
