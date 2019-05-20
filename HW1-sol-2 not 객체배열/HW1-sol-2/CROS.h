#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int NMETHODMAX = 5;
const int NIMAGEMAX = 100;
const int NARRARYMAX = 500;

class CROS
{
public:
	CROS();

	// constructor overloading
	CROS(string strFileName);

	~CROS();

	// mutator
	void SetnImage(int nImage);
	void SetnMethod(int nMethod);
	void SetFileName(string strFileName);
	void SetImageFileNow(string strImageFileNow[], int nSizeofArray);
	void SetnFO(int pnFO[], int nSizeofArray);
	void SetnFR(int pnFR[], int nSizeofArray);
	void SetnFC(int pnFC[], int nSizeofArray);

	// accessor
	int GetnFO(int pnFO[], int nSizeofArray);
	int GetnFR(int pnFR[], int nSizeofArray);
	int GetnFC(int pnFC[], int nSizeofArray);
	int GetnImage();
	int GetnMethod();
	string GetstrFileName();
	string GetstrImageFileNow(string strImageFileNow[], int nSizeofArray);

	// 1번 문제
	void ReadEvalFileToArray();
	// 2번 문제
	void ComputeRecallAndPrecision();
	// 3번 문제
	void ComputeAvgOfRecallAndPrecision();

private:
	string m_strFileName;
	string m_strImageFileNow[NARRARYMAX];
	int m_nImage;
	int m_nMethod;
	int m_nFO[NARRARYMAX];
	int m_nFR[NARRARYMAX];
	int m_nFC[NARRARYMAX];
	double m_nRecall[NARRARYMAX];
	double m_nPrecision[NARRARYMAX];
	double m_nAvgRecall[NMETHODMAX];
	double m_nAvgPrecision[NMETHODMAX];
};

