#pragma once
#include <string>
using namespace std;

class CTheater
{
public:
	CTheater();
	CTheater(string strName, int nTripTime, int *pnShowtime, int nSizeOfArray);
	CTheater(string strName, int nTripTime);
	CTheater(string strName);
	~CTheater();
private:
	// ��ȭ������ ���� �ð�
	int m_nTripTime;
	// ��ȭ�� �̸�
	string m_strName;
	// �󿵽ð�
	int m_pnShowTime[10];
public:
	int GetTripTime();
	string GetName();
	void SetTripTime(int nTripTime);
	void SetName(string strName);
	int GetShowTime(int pnshowtime[], int nSizeofArray);
	void SetShowTime(int pnShowTime[], int nSizeofArray);
	int ShowTheaterInfo();	
	int InputTheaterInfo(string strName, int nTripTime, int pnShowTime[], int nSizeofArray);
	static int m_NUmberOfTheater; // static ����
	void PrintNumberOfTheater();
};