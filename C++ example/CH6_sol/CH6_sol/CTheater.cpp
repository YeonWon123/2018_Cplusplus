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

// destroyer(�Ҹ���)
CTheater::~CTheater()
{
}

// static ����
int CTheater::m_NUmberOfTheater = 0;

void CTheater::PrintNumberOfTheater()
{
	cout << m_NUmberOfTheater << " ";
}

// mutator �Լ�(set �Լ�): �ڷḦ �ٲ� �� �ֵ��� �ϴ� �Լ�
// ��, 1���� ��� ������ ���� ����(����ִ�) �Լ�
void CTheater::SetTripTime(int nTripTime)
{
	m_nTripTime = nTripTime;
}

// accessor �Լ�(get �Լ�): ��ü ���� �ڷḦ ���� �� �ֵ��� �ϴ� �Լ�
// ��, 1���� ��������� �о���� �Լ�
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

// �Է��ϴ� ����Լ�
int CTheater::InputTheaterInfo(string strName, int nTripTime, int pnShowTime[], int nSizeofArray)
{
	SetName(strName);
	SetTripTime(nTripTime);
	SetShowTime(pnShowTime, nSizeofArray);
	return 0;
}

// ����ϴ� ����Լ�
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