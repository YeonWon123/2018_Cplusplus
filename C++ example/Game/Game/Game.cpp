// Game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 3-19, 3-35 실습예제

#include "pch.h"
#include <cmath>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

int AmlWin(string strRPCInput, int strRPCCom);

int main()
{
	string input;

	cout << "가위, 바위, 보 중 하나를 입력하세요 : ";
	cin >> input;

	srand(time(0));				// 랜덤 시드 발생!
	int random = rand() % 3;	// rand()를 3으로 나눈 나머지는 0,1,2 이므로 0,1,2 사이에서 난수 발생!

	int nWin;
	nWin = AmlWin(input, random);

	switch (nWin)
	{
	case 1:
		cout << "축하!" << endl;
		break;
	case -1:
		cout << "분발!" << endl;
		break;
	case 0:
		cout << "비김!" << endl;
		break;
	case -8:
		cout << "바보!" << endl;
		break;
	}


	// 컴퓨터가 무슨 값을 냈는지 보여주는 debug 코드
	/*	cout << "컴퓨터의 값은 : ";
switch (random)
{
case 0:
	cout << "가위" << endl;
	break;
case 1:
	cout << "바위" << endl;
	break;
case 2:
	cout << "보" << endl;
	break;
}
*/
	/*
	if (input == "가위") // 사용자입력과 비교해서(문자열)
	{
		switch (random)	// switch문으로 비교하여 승부에 따라 출력!
		{
		case 0:		// 컴퓨터가 가위를 낸 상황
			cout << "비겼습니다!" << endl;
			break;
		case 1:		// 컴퓨터가 바위를 낸 상황
			cout << "분발!" << endl;
			break;
		case 2:		// 컴퓨터가 보를 낸 상황
			cout << "축하!" << endl;
			break;
		}
	}
	else if (input == "바위")
	{
		switch (random)
		{
		case 0:
			cout << "축하!" << endl;
			break;
		case 1:
			cout << "비겼습니다!" << endl;
			break;
		case 2:
			cout << "분발!" << endl;
			break;
		}
	}
	else
	{
		switch (random)
		{
		case 0:
			cout << "분발!" << endl;
			break;
		case 1:
			cout << "축하!" << endl;
			break;
		case 2:
			cout << "비겼습니다!" << endl;
			break;
		}
	}
	*/
	return 0;
}

int AmlWin(string strRPCInput, int strRPCCom)
{
	int nWin;
	if (strRPCInput == "가위") // 사용자입력과 비교해서(문자열)
	{
		switch (strRPCCom)	// switch문으로 비교하여 승부에 따라 출력!
		{
		case 0:		// 컴퓨터가 가위를 낸 상황
			nWin = 0;
			break;
		case 1:		// 컴퓨터가 바위를 낸 상황
			nWin = -1;
			break;
		case 2:		// 컴퓨터가 보를 낸 상황
			nWin = 1;
			break;
		}
	}
	else if (strRPCInput == "바위")
	{
		switch (strRPCCom)
		{
		case 0:
			nWin = 1;
			break;
		case 1:
			nWin = 0;
			break;
		case 2:
			nWin = -1;
			break;
		}
	}
	else if (strRPCInput == "보")
	{
		switch (strRPCCom)
		{
		case 0:
			nWin = -1;
			break;
		case 1:
			nWin = 1;
			break;
		case 2:
			nWin = 0;
			break;
		}
	}
	else
		nWin = -8; // 사용자가 가위, 바위, 보 어느것도 출력하지 않은 "바보" 상태

	return nWin;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
