#pragma once

#include <string>
#include <iostream>
using namespace std;

/*
1.	CInstagram 클래스를 구현하자.
Member variables는 사용자 m_strId(string) 와 m_strHashtag(string)
그리고 m_nPositive(int), m_nNegative(int) 가 있다.
또한 static 변수로 m_nPosTotal(int) m_nNegTotal(int) 가 있다.
각 변수는 acessor, mutator를 갖고 있다.
생성자는 default와 strId, strHashtag, nPositive, nNegative를 변수로 갖는 생성자가 존재한다.
이 클래스를 구현하시오. [1점]
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
	// accessor 함수(get 함수): 객체 내의 자료를 읽을 수 있도록 하는 함수
	// 즉, 1개의 멤버변수를 읽어오는 함수
	// accessor 함수는 const function으로 선언, 즉 함수를 호출한 객체를 바꾸지 않겠다고 선언한다.
	int GetNegative() const;
	static int GetNegTotal();
	int GetPositive() const;
	static int GetPosTotal();
	string GetHashtag() const;
	string GetId() const;

	// mutator 함수(set 함수): 자료를 바꿀 수 있도록 하는 함수
	// 즉, 1개의 멤버 변수에 값을 쓰는(집어넣는) 함수
	void SetNegative(int nNegative);
	static void SetNegTotal(int nNegTotal);
	void SetPositive(int nPositive);
	static void SetPosTotal(int nPosTotal);
	void SetHashtag(string strHashtag);
	void SetId(string strId);
};

