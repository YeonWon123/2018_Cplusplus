#include <iostream>
using namespace std;

int main()
{
	float a;
	a = 3.0; // type mismatch!!! (double형이 float으로...) 
	
	a = 3.0f; // float의 경우 f를 붙인다. double의 경우 3.0이다.

	const int nSize = 3;
	int pnA[nSize];	// 만약 위의 nSize가 const가 아닌 경우 오류!

	cout << "Hello\\"; // 백슬래시를 출력해 보자. \\를 하면 \가 출력된다!

	return 0;
}