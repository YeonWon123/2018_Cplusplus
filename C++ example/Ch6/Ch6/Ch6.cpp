// Ch6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// Ch6이라는 프로젝트를 만든다.
// 구조체(structures) 실습예제

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

// structure Theater를 정의한다.
struct Theater
{
	string strName;
	int nTripTime;
	int pShowTime[10];
};

// main함수
int main()
{
	// main함수에서 aTheater 객체를 만들고, 값을 넣는다.
	Theater aTheater;
	aTheater.nTripTime = 34;
	aTheater.strName = "남윤원";

	for (int i = 0; i < 10; i++)
	{
		aTheater.pShowTime[i] = i;
	} 

	// 화면에 출력해 본다.
	cout << "nTripTime은: "<< aTheater.nTripTime << endl;
	cout << "strName은: " << aTheater.strName << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "aTheater.pShowTime[" << i << "]은: " << aTheater.pShowTime[i] << endl;
	}

	return 0;
}