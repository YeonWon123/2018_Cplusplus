// 2-43 �ǽ����� - My Solution
#include <iostream>
using namespace std;

int main()
{
	int pWaiting[7] = { 22,21,24,20,18,25,23 };
	int nMax = pWaiting[0];
	int nPosMax = 0;

	cout << "ù���� ���� �ִ�� ���ڽ��ϴ�." << endl;
	cout << "���� �ִ� : " << nMax << endl;
	cout << "���� �ִ��� ��ġ : " << nPosMax << endl;

	for (int i = 0; pWaiting[i] != 21 && i < 7; i++)
	{
		if (nMax < pWaiting[i])
		{
			if (pWaiting[i] % 2 == 0)
			{
				cout << "¦�� �߿��� �ִ� �߰�!" << endl;
				nMax = pWaiting[i];
				nPosMax = i;
				cout << "���� �ִ� : " << nMax << endl;
				cout << "���� �ִ��� ��ġ : " << nPosMax << endl;
			}
			else
			{
				continue;
			}
		}
	}
	
	cout << "���� �ִ� nMax : " << nMax << endl;
	cout << "���� nPosMax : " << nPosMax << endl;

	return 0;
}
