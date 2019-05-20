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

// redefine(재정의)
int CRetangles::Draw()
{
	cout << "Retangle의 draw입니다!" << endl;
	return 0;
}

/*
// redefine(재정의) - 근데 똑같이 써야 되나?
// 근데 부모클래스에서 상속받으면 부모클래스의 Draw()가 실행되니깐.... No!
// 그렇기 때문에, 부모클래스에서 Draw()함수를 virtual로 선언해서
// 자식클래스에서 Center()를 실행시켰을 때, Center() 함수 안의 Draw()함수는
// 부모클래스의 Draw() 함수가 아닌, 자식클래스의 Draw() 함수로 실행한다!!
int CRetangles::Center()
{
	cout << "지우고" << endl;
	cout << "중심 값 잡기" << endl;

	Draw();

	return 0;
}
*/