#include "pch.h"
#include "CDyna.h"

CDyna::CDyna() : m_nSize(0), m_pnSchedule(NULL) // ������ �⺻�� ����
{
}


CDyna::~CDyna()	// destructor(�Ҹ���)
{
	// destructor���� *m_pnSchedule�� NULL�� �ƴϸ� �޸𸮸� Ǯ���ش�.
	// ������ ������ Ǯ������! (delete�� Ǯ���ش�)
	// main�Լ�����, delete pDyna; �� �� �ÿ� �� destructor�� ȣ��ȴ�.
	if (m_pnSchedule != NULL)
		delete[] m_pnSchedule;
	m_pnSchedule = NULL;

}

// ����Լ��� ShowSchedule�� ����, m_pnSchedule�� ������ �Ҵ�Ǿ��� ��� ���� ���
void CDyna::ShowSchedule()
{
	// m_pnSchedule�� ������ �Ҵ���� �ʾ�����, ����� ���� ���ٰ� �˸�
	if (m_pnSchedule == NULL)
	{
		cout << "����� �� �����ϴ�!" << endl;
	}
	else // m_pnSchedule�� ������ �Ҵ�Ǿ�����, �ϳ��� ���
	{
		for (int i = 0; i < m_nSize; i++)
		{
			cout << m_pnSchedule[i] << endl;
		}
	}
}


// ����Լ��� SetInfo(int nSize, int *pSch)�ؼ� ���� �ִ� ���� �����.
void CDyna::SetInfo(int nSize, int *pnSchedule)
{
	m_nSize = nSize;
	
	// ���� ������ ������ ���� �ִٸ�, delete�� Ǯ���ش�.
	if (m_pnSchedule != NULL)
		delete[] m_pnSchedule;

	// new�� ���Ӱ� ������ ��� �ش�. (���� �Ҵ�)
	m_pnSchedule = new int[m_nSize];

	// for������ �ϳ��� �����Ѵ�.
	for (int i = 0; i < m_nSize; i++)
		m_pnSchedule[i] = pnSchedule[i]; // Deep Copies(���� ����)
}

// operator overloading
// Ư�� class�� �ְ� �̸� Deep Copy�ϴ� ��� -> operator overloading�� ���� �ذ��� �� ����
CDyna& CDyna::operator=(const CDyna& rtSide)
{
	// 1. if�� �ۼ�
	if (this == &rtSide) {// if right side same as left side
		return *this;
	}
	else {
		// 2. ũ�� �� �Ϲ� ���� ����
		m_nSize = rtSide.m_nSize;

		// 3. (������ ���� ��) ������ Ǯ��(delete ����)
		if (m_pnSchedule != NULL) {
			delete[] m_pnSchedule;
		}
		// �� ������ ��´�. (new ���)
		m_pnSchedule = new int[m_nSize];

		// 4. �ϳ��� �����Ѵ�. (for�� ���)
		for (int nIndex = 0; nIndex < m_nSize; nIndex++) {
			m_pnSchedule[nIndex] = rtSide.m_pnSchedule[nIndex];
		}
	}
	// ���� ��ȯ!
	return *this;
}
