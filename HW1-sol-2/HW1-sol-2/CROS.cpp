#include "stdafx.h"
#include "CROS.h"


CROS::CROS()
{
}

CROS::~CROS()
{
}

void CROS::SetImageFileNow(string strImageFileNow)
{
	m_strImageFileNow = strImageFileNow;
}

void CROS::SetnFO(int nFO)
{
	m_nFO = nFO;
}

void CROS::SetnFR(int nFR)
{
	m_nFR = nFR;
}

void CROS::SetnFC(int nFC)
{
	m_nFC = nFC;
}

void CROS::SetnRecall(double nRecall)
{
	m_nRecall = nRecall;
}

void CROS::SetnPrecision(double nPrecision)
{
	m_nPrecision = nPrecision;
}

int CROS::GetnFO()
{
	return m_nFO;
}

int CROS::GetnFR()
{
	return m_nFR;
}

int CROS::GetnFC()
{
	return m_nFC;
}

string CROS::GetstrImageFileNow()
{
	return m_strImageFileNow;
}

double CROS::GetnRecall()
{
	return m_nRecall;
}

double CROS::GetnPrecision()
{
	return m_nPrecision;
}

// 2번 문제는 자기 객체 안에서 계산해 줄 수 있음!
void CROS::ComputeRecallAndPrecision()
{
	m_nRecall = (double)m_nFC / m_nFO;
	m_nPrecision = (double)m_nFC / m_nFR;
	cout << m_strImageFileNow << " " << m_nRecall << " " << m_nPrecision << endl;
}