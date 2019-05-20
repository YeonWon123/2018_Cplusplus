#include "pch.h"
#include "CDyna.h"

CDyna::CDyna() : m_nSize(0), m_pnSchedule(NULL) // 생성자 기본값 지정
{
}


CDyna::~CDyna()	// destructor(소멸자)
{
	// destructor에서 *m_pnSchedule이 NULL이 아니면 메모리를 풀어준다.
	// 공간이 있으면 풀어주자! (delete로 풀어준다)
	// main함수에서, delete pDyna; 를 할 시에 이 destructor가 호출된다.
	if (m_pnSchedule != NULL)
		delete[] m_pnSchedule;
	m_pnSchedule = NULL;

}

// 멤버함수로 ShowSchedule을 만들어서, m_pnSchedule에 공간이 할당되었을 경우 값을 출력
void CDyna::ShowSchedule()
{
	// m_pnSchedule에 공간이 할당되지 않았으면, 출력할 것이 없다고 알림
	if (m_pnSchedule == NULL)
	{
		cout << "출력할 게 없습니다!" << endl;
	}
	else // m_pnSchedule에 공간이 할당되었으면, 하나씩 출력
	{
		for (int i = 0; i < m_nSize; i++)
		{
			cout << m_pnSchedule[i] << endl;
		}
	}
}


// 멤버함수로 SetInfo(int nSize, int *pSch)해서 값을 넣는 것을 만든다.
void CDyna::SetInfo(int nSize, int *pnSchedule)
{
	m_nSize = nSize;
	
	// 만약 기존에 공간을 잡혀 있다면, delete로 풀어준다.
	if (m_pnSchedule != NULL)
		delete[] m_pnSchedule;

	// new로 새롭게 공간을 잡아 준다. (동적 할당)
	m_pnSchedule = new int[m_nSize];

	// for문으로 하나씩 복사한다.
	for (int i = 0; i < m_nSize; i++)
		m_pnSchedule[i] = pnSchedule[i]; // Deep Copies(깊은 복사)
}

// operator overloading
// 특정 class를 주고 이를 Deep Copy하는 방법 -> operator overloading을 통해 해결할 수 있음
CDyna& CDyna::operator=(const CDyna& rtSide)
{
	// 1. if문 작성
	if (this == &rtSide) {// if right side same as left side
		return *this;
	}
	else {
		// 2. 크기 등 일반 변수 복사
		m_nSize = rtSide.m_nSize;

		// 3. (공간이 있을 시) 공간을 풀고(delete 공간)
		if (m_pnSchedule != NULL) {
			delete[] m_pnSchedule;
		}
		// 새 공간을 잡는다. (new 사용)
		m_pnSchedule = new int[m_nSize];

		// 4. 하나씩 복사한다. (for문 사용)
		for (int nIndex = 0; nIndex < m_nSize; nIndex++) {
			m_pnSchedule[nIndex] = rtSide.m_pnSchedule[nIndex];
		}
	}
	// 최종 반환!
	return *this;
}
