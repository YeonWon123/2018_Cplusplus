#pragma once
// �ڽ� Ŭ�����Դϴ�!
#include "Employee.h"

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee();
	HourlyEmployee(int nSizeH, int *pnInfoH);
	~HourlyEmployee();
	HourlyEmployee& operator=(const HourlyEmployee& rtSide);
	int getnSize() const;
	int getpnInfo(int *pnInfoH, int nSizeH) const;
	void setnSize(int nSizeH);
	void setpnInfo(int* pnInfoH, int nSizeH);
	void printCheck();

public:
	int m_nSizeH;
	int *m_pnInfoH;
};

