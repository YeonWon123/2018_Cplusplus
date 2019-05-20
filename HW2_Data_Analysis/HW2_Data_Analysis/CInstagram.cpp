#include "pch.h"
#include "CInstagram.h"

/*
1.	CInstagram 클래스를 구현하자.
Member variables는 사용자 m_strId(string) 와 m_strHashtag(string)
그리고 m_nPositive(int), m_nNegative(int) 가 있다.
또한 static 변수로 m_nPosTotal(int) m_nNegTotal(int) 가 있다.
각 변수는 acessor, mutator를 갖고 있다.
생성자는 default와 strId, strHashtag, nPositive, nNegative를 변수로 갖는 생성자가 존재한다.
이 클래스를 구현하시오. [1점]
*/

// default 생성자
CInstagram::CInstagram()
{
	// m_nPositive와 m_nNegative를 0으로 초기화
	m_nPositive = 0;
	m_nNegative = 0;
}

// strId, strHashtag, nPositive, nNegative를 변수로 갖는 생성자
CInstagram::CInstagram(string strId, string strHashtag, int nPositive, int nNegative)
{
	m_strId = strId;
	m_strHashtag = strHashtag;
	m_nPositive = nPositive;
	m_nNegative = nNegative;
}
// 소멸자
CInstagram::~CInstagram()
{
}

// static 변수 m_nPosTotal(int) m_nNegTotal(int)의 초기화
int CInstagram::m_nPosTotal = 0;
int CInstagram::m_nNegTotal = 0;

/*
Member variables는 사용자 m_strId(string) 와 m_strHashtag(string)
그리고 m_nPositive(int), m_nNegative(int) 가 있다.
또한 static 변수로 m_nPosTotal(int) m_nNegTotal(int) 가 있다.
각 변수는 acessor, mutator를 갖고 있다.
*/
// accessor 함수(get 함수): 객체 내의 자료를 읽을 수 있도록 하는 함수
// 즉, 1개의 멤버변수를 읽어오는 함수
int CInstagram::GetNegative() const
{
	return m_nNegative;
}

int CInstagram::GetNegTotal()
{
	return m_nNegTotal;
}

int CInstagram::GetPositive() const
{
	return m_nPositive;
}

int CInstagram::GetPosTotal()
{
	return m_nPosTotal;
}

string CInstagram::GetHashtag() const
{
	return m_strHashtag;
}

string CInstagram::GetId() const
{
	return m_strId;
}

// mutator 함수(set 함수): 자료를 바꿀 수 있도록 하는 함수
// 즉, 1개의 멤버 변수에 값을 쓰는(집어넣는) 함수
void CInstagram::SetNegative(int nNegative)
{
	m_nNegative = nNegative;
}

void CInstagram::SetNegTotal(int nNegTotal)
{
	m_nNegTotal = nNegTotal;
}

void CInstagram::SetPositive(int nPositive)
{
	m_nPositive = nPositive;
}

void CInstagram::SetPosTotal(int nPosTotal)
{
	m_nPosTotal = nPosTotal;
}

void CInstagram::SetHashtag(string strHashtag)
{
	m_strHashtag = strHashtag;
}

void CInstagram::SetId(string strId)
{
	m_strId = strId;
}
