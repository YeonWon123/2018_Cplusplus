// HW1-sol.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int NMETHODMAX = 5;
const int NIMAGEMAX = 100;
const int NARRARYMAX = 500;

void ReadEvalFiletoArray(string strFilename, int &nImage, int &nMethod,
	string pStringFile[], int pnFO[], int pnFR[], int pnFC[]);	// 1번 문제
void ComputeRecallAndPrecision(int nImage, int nMethod,
	string pStringFile[], int pnFO[], int pnFR[], int pnFC[],
	double pRecall[], double pPrecision[]);	// 2번 문제
void ComputeAvgOfRecallAndPrecision(int nImage, int nMethod,
	double pRecall[], double pPrecision[],
	double pAvgRecall[], double pAvgPrecision[]); // 3번 문제

int main()
{
	string strFilename;
	strFilename = "HW1_1.txt";

	int nImage, nMethod;
	string pStringFile[NARRARYMAX];
	int pnFO[NARRARYMAX], pnFR[NARRARYMAX], pnFC[NARRARYMAX];
	double pRecall[NARRARYMAX], pPrecision[NARRARYMAX];
	double pAvgRecall[NMETHODMAX], pAvgPrecision[NMETHODMAX];

	ReadEvalFiletoArray(strFilename, nImage, nMethod, pStringFile, pnFO, pnFR, pnFC);	// 1번 문제
	ComputeRecallAndPrecision(nImage, nMethod, pStringFile, pnFO, pnFR, pnFC, pRecall, pPrecision);	// 2번 문제
	ComputeAvgOfRecallAndPrecision(nImage, nMethod,	pRecall, pPrecision,  pAvgRecall, pAvgPrecision); // 3번 문제

	return 0;
}

void ReadEvalFiletoArray(string strFilename, int &nImage, int &nMethod,
	string pStringFile[], int pnFO[], int pnFR[], int pnFC[])
{
	ifstream myReadFile;
	myReadFile.open(strFilename);
	int nltem = 0;

	myReadFile >> nImage >> nMethod;
	cout << nImage << " " << nMethod << endl;

	for (int nCntlmg = 0; nCntlmg < nImage; nCntlmg++)
	{
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
		{
			myReadFile >> pStringFile[nltem] >> pnFO[nltem] >> pnFR[nltem] >> pnFC[nltem];
			cout << pStringFile[nltem] << " " << pnFO[nltem] 
				 << " " << pnFR[nltem] << " " << pnFC[nltem] << endl;
			nltem++;
		}
	}

	myReadFile.close();
}

void ComputeRecallAndPrecision(int nImage, int nMethod,
	string pStringFile[], int pnFO[], int pnFR[], int pnFC[],
	double pRecall[], double pPrecision[])	// 2번 문제
{
	int nltem = 0;
	for (int nCntlmg = 0; nCntlmg < nImage; nCntlmg++)
	{
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
		{
			pRecall[nltem] = (double)pnFC[nltem] / pnFO[nltem];
			pPrecision[nltem] = (double)pnFC[nltem] / pnFR[nltem];

			cout << pStringFile[nltem] << " " << pRecall[nltem] << " " << pPrecision[nltem] << endl;
			nltem++;
		}
	}
}

void ComputeAvgOfRecallAndPrecision(int nImage, int nMethod, 
	double pRecall[], double pPrecision[],
	double pAvgRecall[], double pAvgPrecision[]) // 3번 문제
{
	int nltem = 0;
	// 초기화
	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
	{
		pAvgRecall[nCntMethod] = 0;
		pAvgPrecision[nCntMethod] = 0;
	}

	for (int nCntlmg = 0; nCntlmg < nImage; nCntlmg++)
	{
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
		{
			pAvgRecall[nCntMethod] = (double)pAvgRecall[nCntMethod] + pRecall[nltem];
			pAvgPrecision[nCntMethod] = (double)pAvgPrecision[nCntMethod] + pPrecision[nltem];
			
			nltem++;
		}
	}

	cout << "합: " << pAvgRecall[1] << endl;
	cout << "2합: " << pAvgPrecision[1] << endl;

	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
	{
		pAvgRecall[nCntMethod] /= nImage;
		pAvgPrecision[nCntMethod] /= nImage;
	}

	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++)
	{
		cout << pAvgRecall[nCntMethod] << " " << pAvgPrecision[nCntMethod] << endl;
	}

}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
