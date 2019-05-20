#pragma once

#include <string>
#include <iostream>

using namespace std;

class CROS
{
public:
	CROS();

	~CROS();

	// mutator
	void SetImageFileNow(string strImageFileNow);
	void SetnFO(int nFO);
	void SetnFR(int nFR);
	void SetnFC(int nFC);
	void SetnRecall(double nRecall);
	void SetnPrecision(double nPrecision);

	// accessor
	int GetnFO();
	int GetnFR();
	int GetnFC();
	double GetnRecall();
	double GetnPrecision();
	string GetstrImageFileNow();

	// 2¹ø ¹®Á¦
	void ComputeRecallAndPrecision();

private:
	string m_strImageFileNow;
	int m_nFO;
	int m_nFR;
	int m_nFC;
	double m_nRecall;
	double m_nPrecision;
};

