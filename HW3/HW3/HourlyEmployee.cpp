// 자식 클래스입니다!

#include "pch.h"
#include "HourlyEmployee.h"


HourlyEmployee::HourlyEmployee() : m_nSizeH(0), m_pnInfoH(NULL)
{
}

HourlyEmployee::HourlyEmployee(int nSizeH, int *pnInfoH)
	: m_nSizeH(nSizeH), m_pnInfoH(pnInfoH)
{

}

HourlyEmployee::~HourlyEmployee()
{
}

HourlyEmployee& HourlyEmployee::operator=(const HourlyEmployee& rtSide)
{
	Employee::operator=(rtSide);
	if (this == &rtSide) {// if right side same as left side
		return *this;
	}
	else {
		m_nSizeH = rtSide.m_nSizeH;
		if (m_pnInfoH != NULL) {
			delete[] m_pnInfoH;
		}
		m_pnInfoH = new int[m_nSizeH];
		for (int nIndex = 0; nIndex < m_nSizeH; nIndex++) {
			m_pnInfoH[nIndex] = rtSide.m_pnInfoH[nIndex];
		}
	}
	return *this;
}


int HourlyEmployee::getnSize() const
{
	return m_nSizeH;
}

int HourlyEmployee::getpnInfo(int *pnInfoH, int nSizeH) const
{
	for (int nIndex = 0; nIndex < nSizeH; nIndex++) {
		pnInfoH[nIndex] = m_pnInfoH[nIndex];
	}
	return 0;
}

void HourlyEmployee::setnSize(int nSizeH)
{
	m_nSizeH = nSizeH;
}

void HourlyEmployee::setpnInfo(int *pnInfoH, int nSizeH)
{
	for (int nIndex = 0; nIndex < nSizeH; nIndex++) {
		m_pnInfoH[nIndex] = pnInfoH[nIndex];
	}
}

void HourlyEmployee::printCheck()
{
	cout << "\n________________________________________________\n";
	cout << "This is HourlyEmployee's printcheck function!\n";
	cout << "nSizeH is " << getnSize() << "\n";

	int *pnInfo = new int[getnSize()];
	getpnInfo(pnInfo, getnSize());
	for (int nIndex = 0; nIndex < getnSize(); nIndex++)
	{
		cout << "m_pnInfo[" << nIndex << "] is " << pnInfo[nIndex] << "\n";
	}
	cout << "_________________________________________________\n";
}
