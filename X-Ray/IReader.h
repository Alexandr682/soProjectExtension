/*
*	S.T.A.L.K.E.R.- IReader class
*	Disassembly by:
*		009 (�������� �������)
*/

class __declspec(dllimport) IReader
{
public:
	IReader();
	~IReader();

	IReader* open_chunk(unsigned int);
	void close(void);
};