#include "pch.h"
#include "CMoney.h"
#include <cmath>

CMoney::CMoney()
{
}

CMoney::CMoney(int nDollar, int nCent)
{
	SetDollar(nDollar);
	SetCent(nCent);
}

CMoney::~CMoney()
{
}

void CMoney::SetDollar(int nDollar)
{
	m_nDollar = nDollar;
}

void CMoney::SetCent(int nCent)
{
	m_nCent = nCent;
}

int CMoney::GetDollar() const
{
	return m_nDollar;
}

int CMoney::GetCent() const
{
	return m_nCent;
}

// class에서 operator overloading하기 (멤버로서의 연산자 오버로딩)
//const CMoney CMoney::operator + (const CMoney& bMoney) const
//{
	/*
		int sumDollar = m_nDollar + bMoney.GetDollar();
		int sumCent = m_nCent + bMoney.GetCent();

		if(sumCent >=100)
		{
			sumCent = sumCent - 100;
			sumDollar = sumDollar + 1;
		}

		return CMoney(sumDollar, sumCent);
	*/
/*
	int allCents1 = m_nCent + m_nDollar * 100;
	int allCents2 = bMoney.GetCent() + bMoney.GetDollar() * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;

	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return CMoney(finalDollars, finalCents);
}
*/