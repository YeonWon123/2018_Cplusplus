// 2-43 실습예제 - 수업시간 solution
#include <iostream>
using namespace std;

int main()
{
	int pWaiting[7] = { 22, 21, 24, 20, 18, 25, 23 };
	int nMax = pWaiting[0];	// 첫번째 값을 최대로 놓는다.
	int nPosMax = 0;		// 첫번째 값이 최대니깐 최댓값의 위치는 0(배열은 1이 아닌 0부터 시작)

	for (int i = 1; i < 7; i++)	// for 문을 이용해서 최대값과 위치를 찾는다.
	{
		if (pWaiting[i] == 21)	// 21이 나오기 전까지에서 짝수 최대값을 찾는다.
		{
			break;	// 21이 나오면 for문을 빠져나간다.
		}
		if (pWaiting[i] % 2 == 1)	// 짝수 중에서만 최대값을 찾는다.
		{
			continue;	// 홀수면 continue로 건너뜀
		}
		if (pWaiting[i] > nMax)	// 만약 현재 최대값보다 더 큰 값이라면
		{
			nMax = pWaiting[i];	// 그 값을 최대값에 복사한다.
			nPosMax = i;		// 최댓값의 위치(i)를 바꾼다.
		}
	}

	cout << "nMax : " << nMax << endl;	// 최대값 출력
	cout << "nPosMax : " << nPosMax << endl;	// 최대값의 위치 출력
	cout << endl;

	return 0;
}