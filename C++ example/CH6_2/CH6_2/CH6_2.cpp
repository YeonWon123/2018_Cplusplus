// Ch6_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

// 이전 structure 예제에 있던 내용을 class CTheater로 구현
class CTheater
{
// 각 변수의 값을 쓰는것과 읽는것의 함수를 만든다
// 이 멤버 함수들은 main함수에서 접근할 수(= 갖다 쓸 수) 있다.(public)
public:
	void PrintSchedule();	    // 출력하는 멤버함수
	void InputTheaterInfo();	// 입력하는 멤버함수

// 멤버 변수들은 모두 private으로 하자
// 이 멤버 변수들은 main함수에서 접근할 수 없다. 오직 class에서만 접근 가능하다.(private)
private:	
	string m_strName;
	int m_nTripTime;
	int m_pnShowTime[10];
};

// main함수
int main()
{
	CTheater theater;

	theater.InputTheaterInfo();
	theater.PrintSchedule();

	return 0;
}

// 멤버함수 정의
void CTheater::InputTheaterInfo()
{
	cout << "m_nTripTime을 적으세요(숫자): ";
	cin >> m_nTripTime;

	cout << "m_StrName을 적으세요(문자): ";
	cin >> m_strName;

	for (int i = 0; i < 10; i++)
	{
		cout << i+1 << "번째 m_pnShowTime을 적으세요(숫자): ";
		cin >> m_pnShowTime[i];
	}

	cout << endl;
}

void CTheater::PrintSchedule()
{
	cout << "m_nTripTime은: " << m_nTripTime << endl;
	cout << "m_strName은: " << m_strName << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "m_pnShowTime[" << i << "]은: " << m_pnShowTime[i] << endl;
	}
}