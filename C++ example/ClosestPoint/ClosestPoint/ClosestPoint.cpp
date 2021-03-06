// ClosestPoint.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 4-18 실습예제 : 유사한 값을 찾고 그 차이를 구하는 프로그램을 작성하자

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

// double 값을 return(반환)하는 함수를 선언(;)합니다.
// 이 함수는 double형의 배열 pSample과 int형의 nSizeOfArray, double형의 target,
// double형의 nearest를 인수로 받습니다. 
// (&은 call-by-reference로서 주소값을 넘겨줍니다.)
// 이는 함수 안에서 주소값은 변하지 않지만, 주소 안의 값은 변할 수 있음을 나타냅니다.
// (원래 함수 안에서 매개 변수의 값은 변하지 않습니다
// 여기서 매개 변수를 주소값으로 하면, 주소 안의 값은 매개 변수가 아니어서
// 바뀔 수 있습니다. 이것이 call-by-reference입니다.
// 우리는, 함수 안에서 주소 안의 값을 변하게 해서 
// nearest의 주소(&nearest)는 변하지 않게 할 겁니다.
// 하지만 nearest 자체의 값은 (함수 안에서) 변하게 할 겁니다.

double FindClosetPoint(double pSample[], int nSizeOfArray, double target, double &nearest); // nearest는 call-by-reference입니다.

// main함수를 선언합니다.
int main()
{
	double pSample[5] = { 0.3, 0.6, 0.1, 0.4, 0.8 };
	double target;
	cout << "target을 입력하세요: ";
	cin >> target;

	int nSizeOfArray = sizeof(pSample)/sizeof(pSample[0]);
	double nearest = 999999.0;	// nearest를 가장 큰 값으로 선언합니다.
								// 이는 첫번째 값이 반드시 nearest로 바뀔 수 있게 유도합니다.
	double diff;
	// 함수 호출 시 배열의 경우는, pSample[]을 적어 주는 것이 아니라,
	// 배열의 이름만 적어 줍니다.
	diff = FindClosetPoint(pSample, nSizeOfArray, target, nearest);

	cout << "유사한 값은: " << diff << endl;

	
	return 0;
}

// 이제 FindClosetPoint라는 함수를 정의해 봅시다.
double FindClosetPoint(double pSample[], int nSizeOfArray, double target, double &nearest)
{
	for (int i = 0; i < nSizeOfArray; i++)
	{
		// 절대값이 필요하므로 앞에서 #include <math.h>를 정의했습니다.
		// abs()함수를 통해서 target-nearest의 값과 target-pSample[i]의 값을
		// 양수로 만들어 버립니다.
		if (abs(target - nearest) > abs(target - pSample[i]))
		{
			// target에 더 근접한 값이 나타나면, 그 값을 nearest에 넘겨줍니다.
			nearest = pSample[i];
		}
	}

	return nearest;
}