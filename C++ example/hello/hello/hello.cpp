// 1-6 실습 예제 (cout, cin의 사용)
// 1-22 실습 예제 (형변환, 여기서는 주석 처리)
// 1-35 실습 예제 (Formatting 예제)

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int numberOfLanguages;

	cout << "Hello reader.\n"
		 << "Welcome to C++.\n";

	cout << "How many programming languages have you used? ";
	cin >> numberOfLanguages;

	if (numberOfLanguages < 1)
		cout << "Read the preface. You may prefer\n"
			 << "a more elementary book by the same author.\n";
	else
		cout << "Enjoy the book.\n\n";

	// Arithmetic Precision Examples

	cout << 17.54 / 3.5 << endl;

	streamsize ss = cout.precision();

	cout.precision(ss);

	cout << 17.54 / 3.5 << endl;

	int n = 2;
	// 소수점 아래 두 자리수까지 표현
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(n);

	// cout << 17 / 5 << "\n"; // integer와 integer의 연산 (정수형과 정수형의 연산)
	// cout << 17.0 / 5 << "\n"; // double과 integer의 연산 (실수형과 정수형의 연산)
							  // promotion이 이루어져서, double/double로 계산해 준다.

	cout << 17.54 / 3.5 << endl;

	int intVar1 = 1, intVar2 = 2;
	double c;

	// cout << intVar1 / intVar2 << "\n"; // int/int 연산 = int값 반환
	
	// c = (double)intVar1 / intVar2;	// Type Casting이 이루어진다.

	// c = static_cast<double> intVar1 / intVar2; // 오류! 어디까지가 double인지 모른다는 불평
	// c = static_cast<double> (intVar1 / intVar2); // 결과값 : 0
	c = static_cast<double> (intVar1) / intVar2; // 결과값 : 0.5

	cout << c << endl; // "\n" = endl

	// 초기화시 unsetf 사용
	cout.unsetf(ios::fixed);
	cout.precision(ss);

	cout << 17.54 / 3.5 << endl;


	return 0;
}