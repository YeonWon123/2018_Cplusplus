#include "pch.h"
#include "CTheater.h"
#include <iostream>
using namespace std;

// default constructor
CTheater::CTheater()
{
	m_NUmberOfTheater++;
}

// constructor overloading
CTheater::CTheater(string strName, int nTripTime, int *pnShowtime, int nSizeOfArray)
{
	m_NUmberOfTheater++;

	SetName(strName);
	SetTripTime(nTripTime);
	SetShowTime(pnShowtime, nSizeOfArray);
}

// constructor overloading
CTheater::CTheater(string strName, int nTripTime)
{
	m_NUmberOfTheater++;

	SetName(strName);
	SetTripTime(nTripTime);
}

// constructor overloading
CTheater::CTheater(string strName)
{
	m_NUmberOfTheater++;

	SetName(strName);
}

// destroyer(소멸자)
CTheater::~CTheater()
{
}

// static 변수
int CTheater::m_NUmberOfTheater = 0;

void CTheater::PrintNumberOfTheater()
{
	cout << m_NUmberOfTheater << " ";
}

// mutator 함수(set 함수): 자료를 바꿀 수 있도록 하는 함수
// 즉, 1개의 멤버 변수에 값을 쓰는(집어넣는) 함수
void CTheater::SetTripTime(int nTripTime)
{
	m_nTripTime = nTripTime;
}

// accessor 함수(get 함수): 객체 내의 자료를 읽을 수 있도록 하는 함수
// 즉, 1개의 멤버변수를 읽어오는 함수
int CTheater::GetTripTime()
{
	return m_nTripTime;
}

void CTheater::SetName(string strName)
{
	m_strName = strName;
}

string CTheater::GetName()
{
	return m_strName;
}

void CTheater::SetShowTime(int pnShowTime[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		m_pnShowTime[nIndex] = pnShowTime[nIndex];
	}
}

int CTheater::GetShowTime(int pnShowtime[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		pnShowtime[nIndex] = m_pnShowTime[nIndex];
	}
	return 0;
}

// 입력하는 멤버함수
int CTheater::InputTheaterInfo(string strName, int nTripTime, int pnShowTime[], int nSizeofArray)
{
	SetName(strName);
	SetTripTime(nTripTime);
	SetShowTime(pnShowTime, nSizeofArray);
	return 0;
}

// 출력하는 멤버함수
int CTheater::ShowTheaterInfo()
{
	cout << m_strName << " " << "Distance " << m_nTripTime << endl;
	cout << "ShowTime is " << endl;
	for (int nIndex = 0; nIndex < 10; nIndex++)
	{
		cout << m_pnShowTime[nIndex] << endl;
	}
	return 0;
}