#pragma once

#include <string>
#include <iostream>
using namespace std;

/*
1.	CInstagram Ŭ������ ��������.
Member variables�� ����� m_strId(string) �� m_strHashtag(string)
�׸��� m_nPositive(int), m_nNegative(int) �� �ִ�.
���� static ������ m_nPosTotal(int) m_nNegTotal(int) �� �ִ�.
�� ������ acessor, mutator�� ���� �ִ�.
�����ڴ� default�� strId, strHashtag, nPositive, nNegative�� ������ ���� �����ڰ� �����Ѵ�.
�� Ŭ������ �����Ͻÿ�. [1��]
*/

class CInstagram
{
public:
	CInstagram();
	CInstagram(string strId, string strHashtag, int nPositive, int nNegative);
	~CInstagram();


private:
	string m_strId;
	string m_strHashtag;
	int m_nPositive;
	int m_nNegative;
	static int m_nPosTotal;
	static int m_nNegTotal;

public:
	// accessor �Լ�(get �Լ�): ��ü ���� �ڷḦ ���� �� �ֵ��� �ϴ� �Լ�
	// ��, 1���� ��������� �о���� �Լ�
	// accessor �Լ��� const function���� ����, �� �Լ��� ȣ���� ��ü�� �ٲ��� �ʰڴٰ� �����Ѵ�.
	int GetNegative() const;
	static int GetNegTotal();
	int GetPositive() const;
	static int GetPosTotal();
	string GetHashtag() const;
	string GetId() const;

	// mutator �Լ�(set �Լ�): �ڷḦ �ٲ� �� �ֵ��� �ϴ� �Լ�
	// ��, 1���� ��� ������ ���� ����(����ִ�) �Լ�
	void SetNegative(int nNegative);
	static void SetNegTotal(int nNegTotal);
	void SetPositive(int nPositive);
	static void SetPosTotal(int nPosTotal);
	void SetHashtag(string strHashtag);
	void SetId(string strId);
};

