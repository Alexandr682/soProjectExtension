/*
*	S.T.A.L.K.E.R. Online - smart_terrain fixs
*	Developers:
*		009 (�������� �������)
*/

#include <stdlib.h>

#include "../../../shared/hook.h"

bool CWrapperAbstractZone_CSE_ALifeSmartZone___can_switch_online(DWORD pClass)
{
	// � ������ ������� �� ����������
	return false;
}

bool CWrapperAbstractZone_CSE_ALifeSmartZone___can_switch_offline(DWORD pClass)
{
	// ���� � ������� �� ������� � �������
	if(*(BYTE*)(pClass + 0xA4) == 1) return true;
	else return false;
}