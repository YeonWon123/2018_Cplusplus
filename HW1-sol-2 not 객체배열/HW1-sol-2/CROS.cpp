#include "stdafx.h"
#include "CROS.h"


CROS::CROS()
{
}

CROS::CROS(string strFileName)
{
	SetFileName(strFileName);
}

CROS::~CROS()
{
}

void CROS::SetnImage(int nImage)
{
	m_nImage = nImage;
}

void CROS::SetnMethod(int nMethod)
{
	m_nMethod = nMethod;
}

void CROS::SetFileName(string strFileName)
{
	m_strFileName = strFileName;
}

void CROS::SetImageFileNow(string strImageFileNow[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		m_strImageFileNow[nIndex] = strImageFileNow[nIndex];
	}
}

void CROS::SetnFO(int pnFO[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		m_nFO[nIndex] = pnFO[nIndex];
	}
}

void CROS::SetnFR(int pnFR[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		m_nFR[nIndex] = pnFR[nIndex];
	}
}

void CROS::SetnFC(int pnFC[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		m_nFC[nIndex] = pnFC[nIndex];
	}
}

int CROS::GetnFO(int pnFO[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		pnFO[nIndex] = m_nFO[nIndex];
	}
	return 0;
}

int CROS::GetnFR(int pnFR[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		pnFR[nIndex] = m_nFR[nIndex];
	}
	return 0;
}

int CROS::GetnFC(int pnFC[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		pnFC[nIndex] = m_nFC[nIndex];
	}
	return 0;
}

int CROS::GetnImage()
{
	return m_nImage;
}

int CROS::GetnMethod()
{
	return m_nMethod;
}

string CROS::GetstrFileName()
{
	return m_strFileName;
}

string CROS::GetstrImageFileNow(string strImageFileNow[], int nSizeofArray)
{
	for (int nIndex = 0; nIndex < nSizeofArray; nIndex++) {
		strImageFileNow[nIndex] = m_strImageFileNow[nIndex];
	}
	return 0;
}

// 1번 문제
void CROS::ReadEvalFileToArray()
{
	ifstream myReadFile;
	myReadFile.open(m_strFileName);
	int nItem = 0;
	myReadFile >> m_nImage >> m_nMethod;
	cout << m_nImage << " " << m_nMethod << endl;
	for (int nCntImg = 0; nCntImg < m_nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {
			myReadFile >> m_strImageFileNow[nItem] >> m_nFO[nItem]
				>> m_nFR[nItem] >> m_nFC[nItem];
			cout << m_strImageFileNow[nItem] << " " << m_nFO[nItem]
				<< " " << m_nFR[nItem] << " " << m_nFC[nItem] << endl;
			nItem++;
		}
	}
	myReadFile.close();
}

// 2번 문제
void CROS::ComputeRecallAndPrecision()
{
	int nItem = 0;
	for (int nCntImg = 0; nCntImg < m_nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {

			m_nRecall[nItem] = (double)m_nFC[nItem] / m_nFO[nItem];
			m_nPrecision[nItem] = (double)m_nFC[nItem] / m_nFR[nItem];

			cout << m_strImageFileNow[nItem] << " " << m_nRecall[nItem] << " " << m_nPrecision[nItem] << endl;
			nItem++;
		}
	}
}

// 3번 문제
void CROS::ComputeAvgOfRecallAndPrecision()
{
	int nItem = 0;
	// 초기화
	for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {
		m_nAvgRecall[nCntMethod] = 0;
		m_nAvgPrecision[nCntMethod] = 0;
	}
	for (int nCntImg = 0; nCntImg < m_nImage; nCntImg++) {
		for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {
			m_nAvgRecall[nCntMethod] = m_nAvgRecall[nCntMethod] + m_nRecall[nItem];
			m_nAvgPrecision[nCntMethod] = m_nAvgPrecision[nCntMethod] + m_nPrecision[nItem];
			nItem++;
		}
	}
	for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {
		m_nAvgRecall[nCntMethod] /= m_nImage;
		m_nAvgPrecision[nCntMethod] /= m_nImage;
	}
	for (int nCntMethod = 0; nCntMethod < m_nMethod; nCntMethod++) {
		cout << m_nAvgRecall[nCntMethod] << " " << m_nAvgPrecision[nCntMethod] << endl;
	}
}