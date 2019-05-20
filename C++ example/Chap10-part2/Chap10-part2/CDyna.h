 #pragma once

/*
�ǽ����� ����

CDyna Ŭ������ �����ϰ�
��������� int m_nSize, int *m_pnSchedule; �� �����.

����Լ��� ShowSchedule�� ���� m_pnSchedule �� ������ �Ҵ��Ѵ�.
���� �Ҵ�Ǿ����� ���� ����ϰ� �ȵǾ����� �ȵ��� �˸�
���� �Լ����� pointer������ ��ü�� �����ϰ�, Ŭ���� ��ü�� new�� ����� ȭ�鿡 ����Ѵ�.
����Լ��� SetInfo(int nSize, int*pSch) �ؼ� ���� �ִ°� ����.
�����Լ����� 3�� ũ���� schedule �ְ� ȭ�� ���

Destruct���� *m_pnSchedule �� NULL�� �ƴϸ� �޸𸮸� Ǯ���ش�.
���� �����ڿ��� ó���� m_pnSchedule = NULL; �� �߾���.
Main�Լ� ������ delete pDyna����
Main �Լ����� ���� ��ü�� delete�ϱ����� ���ο� ��ü�� �� �� ����� ���� �Ҵ��Ѵ�.
CDyna anotherDyna;anotherDyna = *pDyna;
ȭ�鿡 ��� // ����?
Operator = overloading �Ѵ�.  10-43�� ����

*/

#include <iostream>
using namespace std;

// CDyna Ŭ������ ����
class CDyna
{
public:
	CDyna();
	~CDyna();

// ��������� int m_nSize; int *m_pnSchedule; �� �����.
private:
	int m_nSize;
	int *m_pnSchedule;

public:
	// ����Լ��� ShowSchedule�� ����, m_pnSchedule�� ������ �Ҵ�Ǿ��� ��� ���� ���
	void ShowSchedule();

	// ����Լ��� SetInfo(int nSize, int *pSch)�ؼ� ���� �ִ� ���� �����.
	void SetInfo(int nSize, int *pnSchedule);

	CDyna& operator = (const CDyna& rtSide); // operator overloading
};

