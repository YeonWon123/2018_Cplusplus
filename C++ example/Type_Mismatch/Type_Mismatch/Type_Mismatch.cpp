#include <iostream>
using namespace std;

int main()
{
	float a;
	a = 3.0; // type mismatch!!! (double���� float����...) 
	
	a = 3.0f; // float�� ��� f�� ���δ�. double�� ��� 3.0�̴�.

	const int nSize = 3;
	int pnA[nSize];	// ���� ���� nSize�� const�� �ƴ� ��� ����!

	cout << "Hello\\"; // �齽���ø� ����� ����. \\�� �ϸ� \�� ��µȴ�!

	return 0;
}