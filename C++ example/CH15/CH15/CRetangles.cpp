#include "pch.h"
#include "CRetangles.h"
#include <iostream>
using namespace std;

CRetangles::CRetangles()
{
}


CRetangles::~CRetangles()
{
}

// redefine(������)
int CRetangles::Draw()
{
	cout << "Retangle�� draw�Դϴ�!" << endl;
	return 0;
}

/*
// redefine(������) - �ٵ� �Ȱ��� ��� �ǳ�?
// �ٵ� �θ�Ŭ�������� ��ӹ����� �θ�Ŭ������ Draw()�� ����Ǵϱ�.... No!
// �׷��� ������, �θ�Ŭ�������� Draw()�Լ��� virtual�� �����ؼ�
// �ڽ�Ŭ�������� Center()�� ��������� ��, Center() �Լ� ���� Draw()�Լ���
// �θ�Ŭ������ Draw() �Լ��� �ƴ�, �ڽ�Ŭ������ Draw() �Լ��� �����Ѵ�!!
int CRetangles::Center()
{
	cout << "�����" << endl;
	cout << "�߽� �� ���" << endl;

	Draw();

	return 0;
}
*/