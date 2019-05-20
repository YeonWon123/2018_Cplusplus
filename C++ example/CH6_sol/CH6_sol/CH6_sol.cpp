// CH6_sol.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 7-38p에 있는 예제까지 이어서 진행하였습니다!

#include "pch.h"
#include <iostream>
#include "CTheater.h"

int main()
{
	int ShowTime1[10] = { 1200, 1300, 1400, 1500 };

	CTheater Theater1("롯데시네마", 5, ShowTime1, 10); // static 변수 1 증가
	Theater1.PrintNumberOfTheater();

	CTheater Theater2("cgv", 5);	// static 변수 1 증가
	Theater2.PrintNumberOfTheater();

	CTheater Theater3("메가박스");	// static 변수 1 증가
	Theater3.PrintNumberOfTheater();

	CTheater Theater4[10];			// static 변수 1 증가 * 10번 반복
	Theater4[5].PrintNumberOfTheater();

	/*
	CTheater aTheater;
	aTheater.SetName("롯데시네마");
	aTheater.SetTripTime(10);
	aTheater.SetShowTime(ShowTime1, 10);
	aTheater.ShowTheaterInfo();
	*/

	/*
	CTheater bTheater;
	int ShowTime2[10] = { 1100, 1300, 1400, 1600, 1800 };
	bTheater.InputTheaterInfo("cgv", 5, ShowTime2, 10);
	bTheater.ShowTheaterInfo();
	*/
	return 0;
}