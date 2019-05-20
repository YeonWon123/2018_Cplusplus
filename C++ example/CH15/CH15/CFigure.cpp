#include "pch.h"
#include "CFigure.h"
#include <iostream>
using namespace std;

CFigure::CFigure()
{
}


CFigure::~CFigure()
{
}


int CFigure::Draw()
{
	cout << "CFigure에 있는 Draw입니다!" << endl;
	return 0;
}


int CFigure::Center()
{
	cout << "지우고" << endl;
	cout << "중심 값 잡기" << endl;

	Draw();

	return 0;
}
