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
	cout << "CFigure�� �ִ� Draw�Դϴ�!" << endl;
	return 0;
}


int CFigure::Center()
{
	cout << "�����" << endl;
	cout << "�߽� �� ���" << endl;

	Draw();

	return 0;
}
