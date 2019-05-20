// 부모 클래스입니다!

#include "pch.h"
#include "Employee.h"

Employee::Employee() : m_nSize(0), m_pnInfo(NULL)
{
}

Employee::Employee(int nSize, int *pnInfo)
	: m_nSize(nSize), m_pnInfo(pnInfo)
{
	//deliberately empty
}


Employee::~Employee()
{
}

Employee& Employee::operator=(const Employee& rtSide)
{
	if (this == &rtSide) {// if right side same as left side
		return *this;
	}
	else {
		m_nSize = rtSide.m_nSize;
		if (m_pnInfo != NULL) {
			delete[] m_pnInfo;
		}
		m_pnInfo = new int[m_nSize];
		for (int nIndex = 0; nIndex < m_nSize; nIndex++) {
			m_pnInfo[nIndex] = rtSide.m_pnInfo[nIndex];
		}
	}
	return *this;
}

int Employee::getnSize() const
{
	return m_nSize;
}

int Employee::getpnInfo(int *pnInfo, int nSize) const
{
	for (int nIndex = 0; nIndex < nSize; nIndex++) {
		pnInfo[nIndex] = m_pnInfo[nIndex];
	}
	return 0;
}

void Employee::setnSize(int nSize)
{
	m_nSize = nSize;
}

void Employee::setpnInfo(int *pnInfo, int nSize)
{
	for (int nIndex = 0; nIndex < nSize; nIndex++) {
		m_pnInfo[nIndex] = pnInfo[nIndex];
	}
}

void Employee::printCheck()
{
	cout << "\n________________________________________________\n";
	cout << "This is Employee's printcheck function!\n";
	cout << "nSize is " << getnSize() << "\n";
	
	int *pnInfo = new int[getnSize()];
	getpnInfo(pnInfo, getnSize());
	for (int nIndex = 0; nIndex < getnSize(); nIndex++)
	{
		cout << "m_pnInfo[" << nIndex << "] is " << pnInfo[nIndex] << "\n";
	}
	cout << "_________________________________________________\n";

}
