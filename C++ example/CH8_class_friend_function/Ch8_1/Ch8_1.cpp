// Ch8_1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 8장 operator overloading

#include "pch.h"
#include "CMoney.h"
#include <iostream>
using namespace std;

// 함수 선언
//ostream & operator << (ostream &outputstream, const CMoney &amount);
bool operator == (const CMoney& amount1, const CMoney& amount2);
const CMoney operator - (const CMoney& amount1);

// 2018-10-15(월) 수업내용
// const CMoney AddTwo(const CMoney &aMoney, const CMoney &bMoney);
// const CMoney operator + (const CMoney &aMoney, const CMoney &bMoney); 
// 근데 맨 앞의 const를 빼도 똑같은 결과가 나온다...?
// 객체를 상수(const)로 돌려야 하는 이유? (ppt p 8-11 ~ 8.14)
// return되는 type이 결과에 저장될때까지 수정되지 않게 하려고!
// (결과에 저장된 이후에는 결과값 수정 가능)

// 원칙적으로 어떤 함수가 class return할 경우 무조건 const return한다.
// <중요!> class의 friend함수는 main함수 위에 함수 선언을 할 필요가 없다.
int main()
{
	//CMoney aMoney(10,11);
	//CMoney bMoney(9, -3);
	
	//cascading
	//cout << aMoney << "           " << bMoney << endl;   // showMoney(aMoney);

	CMoney aMoney(45,35);
	CMoney bMoney(178,90);

	CMoney SumMoney;

	/*
	SumMoney = AddTwo(aMoney, bMoney); // 일반 함수 사용
	*/

	SumMoney = aMoney + bMoney;		   // 2018-10-18 -> friend 함수 사용	
									   // 2018-10-15 -> (class) operator overloading 사용

	// 출력
	cout << "$" << SumMoney.GetDollar() << "." << SumMoney.GetCent() << endl;

	//showMoney(SumMoney);
	//showMoney(SumMoney2);

	return 0;
}

/*
// 일반 함수
const CMoney AddTwo(const CMoney &aMoney, const CMoney &bMoney)
{
	int sumDollar = 0; int sumCent = 0;
	sumCent = aMoney.GetCent() + bMoney.GetCent();
	sumDollar = aMoney.GetDollar() + bMoney.GetDollar();
	if (sumCent >= 100)
	{
		sumCent -= 100;
		sumDollar++;
	}

	return CMoney(sumDollar, sumCent);
}
*/

/*
// operator overloading << 과 cascading 적용
ostream & operator << (ostream &outputstream, const CMoney &amount)
{
	if (amount.GetDollar() < 0 || amount.GetCent() < 0) {
		outputstream << "$-";
	}
	else {
		outputstream << "$";
	}
	// 절대값으로 수정
	int nDollar = abs(amount.GetDollar());
	int nCent = abs(amount.GetCent());
	outputstream << nDollar << ".";

	if (nCent >= 10) {
		outputstream << nCent;
	}
	else {
		outputstream << "0" << nCent;
	}
	// 주소값(ostream) return으로 cascading이 가능하게 한다.
	// 즉, cout << 변수 << 변수 << endl; 와 같은 꼴이 가능하게 한다.
	return outputstream;
}
*/

// friend 함수
const CMoney operator + (const CMoney &aMoney, const CMoney &bMoney)
{
	int allCents1 = aMoney.GetCent() + aMoney.GetDollar() * 100;
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

// 일반 함수
/*
const CMoney AddTwo(CMoney &aMoney, CMoney &bMoney)
{
	int sumDollar = 0; int sumCent = 0;
	sumCent = aMoney.GetCent() + bMoney.GetCent();
	sumDollar = aMoney.GetDollar() + bMoney.GetDollar();
	if (sumCent >= 100)
	{
		sumCent -= 100;
		sumDollar++;
	}
	
	return CMoney(sumDollar, sumCent);
}
*/

/*
// operator overloading
const CMoney operator + (const CMoney &aMoney, const CMoney &bMoney)
{
	int allCents1 = aMoney.GetCent() + aMoney.GetDollar()*100;
	int allCents2 = bMoney.GetCent() + bMoney.GetDollar()*100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents/100;
	int finalCents = absAllCents%100;

	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return CMoney(finalDollars, finalCents);
}
*/

bool operator == (const CMoney& amount1, const CMoney& amount2)
{
	return amount1.GetDollar() == amount2.GetDollar() && amount1.GetCent() == amount2.GetCent();
}

const CMoney operator - (const CMoney& amount1)
{
	return CMoney(-amount1.GetDollar(), -amount1.GetCent());
}