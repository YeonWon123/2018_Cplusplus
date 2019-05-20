#pragma once
#include "CFigure.h"
class CRetangles :
	public CFigure
{
public:
	CRetangles();
	~CRetangles();

private:
	int m_width;
	int m_Height;
public:
	int Draw();
//	int Center();
};

