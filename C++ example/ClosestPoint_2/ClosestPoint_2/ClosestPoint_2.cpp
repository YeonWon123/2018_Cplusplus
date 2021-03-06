// ClosestPoint.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 실습예제 4-30

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

// Default Arguments는 선언시 기본값을 적어줍니다. 정의할 때는 기본값을 적지 않습니다.
int FindClosestPoint(int *pSample, int nSizeOfArray, int target, int &nearest, bool bAbsDiff = true);
double FindClosestPoint(double pSample[], int nSizeOfArray, double target, double &nearest);

int main()
{
	int nSizeOfArray = 5;

	int pSampleInt[5] = { 3, 6, 1, 4, 8 };
	int targetInt;

	cout << "정수 target을 입력하세요: ";
	cin >> targetInt;

	int nearestInt = 999999; // nearestInt를 엄청 큰 값으로 초기화합니다.
	int diffInt;

	// bool 값을 지정하지 않으면 기본값(true)으로 선언됩니다!
	diffInt = FindClosestPoint(pSampleInt, nSizeOfArray, targetInt, nearestInt);
	cout << "유사한 값은: " << diffInt << endl << endl;

	// bool 값을 false로 지정합시다!
	diffInt = FindClosestPoint(pSampleInt, nSizeOfArray, targetInt, nearestInt, false); 
	cout << "유사한 값은: " << diffInt << endl << endl;


	double pSample[5] = { 0.3, 0.6, 0.1, 0.4, 0.8 };
	double target;
	cout << "실수 target을 입력하세요: ";
	cin >> target;

	double nearest = 999999.0;	// nearest를 엄청 큰 값으로 초기화합니다.
	double diff;
	diff = FindClosestPoint(pSample, nSizeOfArray, target, nearest);

	cout << "유사한 값은: " << diff << endl;

	return 0;
}

int FindClosestPoint(int *pSample, int nSizeOfArray, int target, int &nearest, bool bAbsDiff)
{
	if (bAbsDiff == true) // bool값 먼저 비교, 참일 경우 절대값의 차이
	{
		for (int i = 0; i < nSizeOfArray; i++)
		{
			if (abs(target - nearest) > abs(target - pSample[i])) //현재 타깃과 가장 근접한 값 vs 비교 대상
			{
				nearest = pSample[i]; //비교 대상과 타깃간 차이가 더 적으면 비교 대상을 가장 근접한 값으로 지정
			}
		}

		cout << "절대값의 차이: " << abs(target - nearest) << endl;
	}
	else // bool값이 false인 경우, 거짓일 경우 최소 차이의 큰 값
	{
		int sw = 0;		// 초기 스위치 0인 상태
		for (int i = 0; i < nSizeOfArray; i++)
		{
			if (target < pSample[i]) // 절대값이 양수이면
			{
				if (sw == 0)		// 최초로 절대값이 양수인 값이 나왔을 때
				{
					nearest = pSample[i];	// 자동 등록
					sw++;					// 스위치 올림(1)
				}
				else if (abs(nearest - pSample[i]) > abs(target - pSample[i]))// 절대값이 양수인 값이 나왔을 때 비교
				{
					nearest = pSample[i];
				}
			}
		}

		if (sw == 0)	// 스위치 0인 상태, 절대값이 양수인 값이 없으면
			nearest = -1;	// -1을 반환

		cout << "최소 차이의 큰 값(없을 시 -1): " << nearest << endl;
 	}

	return nearest;
}


double FindClosestPoint(double pSample[], int nSizeOfArray, double target, double &nearest)
{
	for (int i = 0; i < nSizeOfArray; i++)
	{
		if (abs(target - nearest) > abs(target - pSample[i]))
		{
			nearest = pSample[i];
		}
	}

	return nearest;
}