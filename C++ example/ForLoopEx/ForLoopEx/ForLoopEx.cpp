// 2-43 실습예제 - My Solution
#include <iostream>
using namespace std;

int main()
{
	int pWaiting[7] = { 22,21,24,20,18,25,23 };
	int nMax = pWaiting[0];
	int nPosMax = 0;

	cout << "첫번쨰 값을 최대로 놓겠습니다." << endl;
	cout << "현재 최댓값 : " << nMax << endl;
	cout << "현재 최댓값의 위치 : " << nPosMax << endl;

	for (int i = 0; pWaiting[i] != 21 && i < 7; i++)
	{
		if (nMax < pWaiting[i])
		{
			if (pWaiting[i] % 2 == 0)
			{
				cout << "짝수 중에서 최댓값 발견!" << endl;
				nMax = pWaiting[i];
				nPosMax = i;
				cout << "현재 최댓값 : " << nMax << endl;
				cout << "현재 최댓값의 위치 : " << nPosMax << endl;
			}
			else
			{
				continue;
			}
		}
	}
	
	cout << "최종 최댓값 nMax : " << nMax << endl;
	cout << "최종 nPosMax : " << nPosMax << endl;

	return 0;
}
