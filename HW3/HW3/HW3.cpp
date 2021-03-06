// HW3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Employee.h"
#include "HourlyEmployee.h"
#include <iostream>
using namespace std;

int main()
{
	// 부모 클래스 테스트
	const int nSize1 = 5;
	int pnInfo1[nSize1] = { 10000, 20000, 30000, 40000, 50000 };
	Employee A(nSize1, pnInfo1);

	Employee B;

	B = A;
	cout << "\n\n---------Employee 객체 A를 찍어봅시다!----------\n";
	A.printCheck();

	cout << "\n\n---------Employee 객체 B를 찍어봅시다!----------\n";
	B.printCheck();

	// 자식 클래스 테스트
	const int nSize2 = 3;
	int pnInfo2[nSize2] = { 1000, 2000 ,3000 };
	HourlyEmployee C(3, pnInfo2);

	HourlyEmployee D;

	D = C;

	cout << "\n\n---------HourlyEmployee 객체 C를 찍어봅시다!----------\n";
	C.printCheck();
	cout << "\n\n---------HourlyEmployee 객체 D를 찍어봅시다!----------\n";
	D.printCheck();

	return 0;
}
