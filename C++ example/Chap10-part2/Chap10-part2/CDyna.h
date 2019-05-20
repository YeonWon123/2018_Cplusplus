 #pragma once

/*
실습예제 문제

CDyna 클래스를 생성하고
멤버변수로 int m_nSize, int *m_pnSchedule; 을 만든다.

멤버함수로 ShowSchedule을 만들어서 m_pnSchedule 에 공간을 할당한다.
만약 할당되었으면 값을 출력하고 안되었으면 안됨을 알림
메인 함수에서 pointer변수로 객체를 선언하고, 클래스 객체를 new로 만들고 화면에 출력한다.
멤버함수로 SetInfo(int nSize, int*pSch) 해서 값을 넣는것 만듬.
메인함수에서 3개 크기인 schedule 넣고 화면 출력

Destruct에서 *m_pnSchedule 이 NULL이 아니면 메모리를 풀어준다.
물론 생성자에서 처음에 m_pnSchedule = NULL; 로 했었다.
Main함수 끝에서 delete pDyna해줌
Main 함수에서 위의 객체를 delete하기전에 새로운 객체를 한 개 만들고 값을 할당한다.
CDyna anotherDyna;anotherDyna = *pDyna;
화면에 출력 // 죽죠?
Operator = overloading 한다.  10-43쪽 참조

*/

#include <iostream>
using namespace std;

// CDyna 클래스를 생성
class CDyna
{
public:
	CDyna();
	~CDyna();

// 멤버변수로 int m_nSize; int *m_pnSchedule; 을 만든다.
private:
	int m_nSize;
	int *m_pnSchedule;

public:
	// 멤버함수로 ShowSchedule을 만들어서, m_pnSchedule에 공간이 할당되었을 경우 값을 출력
	void ShowSchedule();

	// 멤버함수로 SetInfo(int nSize, int *pSch)해서 값을 넣는 것을 만든다.
	void SetInfo(int nSize, int *pnSchedule);

	CDyna& operator = (const CDyna& rtSide); // operator overloading
};

