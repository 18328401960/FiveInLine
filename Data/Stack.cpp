// Stack.cpp: implementation of the CStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "Stack.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStack::CStack()
{
	top = -1;
}

CStack::~CStack()
{

}

//	����ջ��Ԫ��
CPoint CStack::pop()
{
	return Sta[top--];
}

//	����ջ�Ƿ�Ϊ��
bool CStack::isEmpty()
{
	if(top <= -1)
		return true;
	else
		return false;
}

//	��Ԫ����ջ
void CStack::push(CPoint newPoint)
{
	Sta[++top] = newPoint;
}

//	���ջ�ĳ���
int CStack::getLength()
{
	return top+1;
}

//	���ջ
void CStack::clear()
{
	top=-1;
}
