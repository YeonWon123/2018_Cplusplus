// HW1-sol-2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 고급프로그래밍 (나)반 20150413 남윤원 - HW1-sol을 객체 배열을 사용하여 class로 재구성해보는 과제

#include "stdafx.h"
#include "CROS.h"
#include <fstream>

void ReadEvalFileToArray(string strFilename, int &nImage, int &nMethod, CROS Image_Authentification[]);
void ComputeRecallAndPrecision(int nImage, int nMethod, CROS Image_Authentification[]);
void ComputeAvgOfRecallAndPrecision(int nImage, int nMethod, CROS Image_Authentification[]);

const int NMETHODMAX = 5;
const int NIMAGEMAX = 100;
const int NARRARYMAX = 500;

int main()
{
	CROS Image_Authentification[NARRARYMAX];

	string strFilename;
	strFilename = "HW1_1.txt";
	int nImage, nMethod;

	ReadEvalFileToArray(strFilename, nImage, nMethod, Image_Authentification);
	ComputeRecallAndPrecision(nImage, nMethod, Image_Authentification);
	ComputeAvgOfRecallAndPrecision(nImage, nMethod, Image_Authentification);

	return 0;
}

void ReadEvalFileToArray(string strFilename, int &nImage, int &nMethod, CROS Image_Authentification[])
{
	ifstream myReadFile;
	myReadFile.open(strFilename);
	myReadFile >> nImage >> nMethod;
	cout << nImage << " " << nMethod << endl;

	string strImageFileNow;
	int nFO, nFR, nFC;
	int nItem = 0;
	for (int nCntImg = 0; nCntImg < nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
			myReadFile >> strImageFileNow >> nFO >> nFR >> nFC;

			Image_Authentification[nItem].SetImageFileNow(strImageFileNow);
			Image_Authentification[nItem].SetnFO(nFO);
			Image_Authentification[nItem].SetnFR(nFR);
			Image_Authentification[nItem].SetnFC(nFC);

			cout << Image_Authentification[nItem].GetstrImageFileNow() << " " << Image_Authentification[nItem].GetnFO() << " "
				<< Image_Authentification[nItem].GetnFR() << " " << Image_Authentification[nItem].GetnFC() << endl;

			nItem++;
		}
	}
	myReadFile.close();
}

void ComputeRecallAndPrecision(int nImage, int nMethod, CROS Image_Authentification[])
{
	int nItem = 0;
	for (int nCntImg = 0; nCntImg < nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
			Image_Authentification[nItem].ComputeRecallAndPrecision();
			nItem++;
		}
	}
}

void ComputeAvgOfRecallAndPrecision(int nImage, int nMethod, CROS Image_Authentification[])
{
	double pAvgRecall[NMETHODMAX], pAvgPrecision[NMETHODMAX];

	int nItem = 0;
	// 초기화
	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
		pAvgRecall[nCntMethod] = 0;
		pAvgPrecision[nCntMethod] = 0;
	}
	for (int nCntImg = 0; nCntImg < nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
			pAvgRecall[nCntMethod] = pAvgRecall[nCntMethod] + Image_Authentification[nItem].GetnRecall();
			pAvgPrecision[nCntMethod] = pAvgPrecision[nCntMethod] + Image_Authentification[nItem].GetnPrecision();
			nItem++;
		}
	}
	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
		pAvgRecall[nCntMethod] /= nImage;
		pAvgPrecision[nCntMethod] /= nImage;
	}
	for (int nCntMethod = 0; nCntMethod < nMethod; nCntMethod++) {
		cout << pAvgRecall[nCntMethod] << " " << pAvgPrecision[nCntMethod] << endl;
	}
}