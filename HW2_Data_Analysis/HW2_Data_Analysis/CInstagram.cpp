#include "pch.h"
#include "CInstagram.h"

/*
1.	CInstagram Ŭ������ ��������.
Member variables�� ����� m_strId(string) �� m_strHashtag(string)
�׸��� m_nPositive(int), m_nNegative(int) �� �ִ�.
���� static ������ m_nPosTotal(int) m_nNegTotal(int) �� �ִ�.
�� ������ acessor, mutator�� ���� �ִ�.
�����ڴ� default�� strId, strHashtag, nPositive, nNegative�� ������ ���� �����ڰ� �����Ѵ�.
�� Ŭ������ �����Ͻÿ�. [1��]
*/

// default ������
CInstagram::CInstagram()
{
	// m_nPositive�� m_nNegative�� 0���� �ʱ�ȭ
	m_nPositive = 0;
	m_nNegative = 0;
}

// strId, strHashtag, nPositive, nNegative�� ������ ���� ������
CInstagram::CInstagram(string strId, string strHashtag, int nPositive, int nNegative)
{
	m_strId = strId;
	m_strHashtag = strHashtag;
	m_nPositive = nPositive;
	m_nNegative = nNegative;
}
// �Ҹ���
CInstagram::~CInstagram()
{
}

// static ���� m_nPosTotal(int) m_nNegTotal(int)�� �ʱ�ȭ
int CInstagram::m_nPosTotal = 0;
int CInstagram::m_nNegTotal = 0;

/*
Member variables�� ����� m_strId(string) �� m_strHashtag(string)
�׸��� m_nPositive(int), m_nNegative(int) �� �ִ�.
���� static ������ m_nPosTotal(int) m_nNegTotal(int) �� �ִ�.
�� ������ acessor, mutator�� ���� �ִ�.
*/
// accessor �Լ�(get �Լ�): ��ü ���� �ڷḦ ���� �� �ֵ��� �ϴ� �Լ�
// ��, 1���� ��������� �о���� �Լ�
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

// mutator �Լ�(set �Լ�): �ڷḦ �ٲ� �� �ֵ��� �ϴ� �Լ�
// ��, 1���� ��� ������ ���� ����(����ִ�) �Լ�
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
