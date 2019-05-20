#pragma once
// 부모 클래스입니다!

#include <iostream>
using namespace std;

class Employee
{
public:
	Employee();
	Employee(int nSize, int *pnInfo);
	~Employee();
	Employee& operator=(const Employee& rtSide);
	int getnSize() const;
	int getpnInfo(int *pnInfo, int nSize) const;
	void setnSize(int nSize);
	void setpnInfo(int* pnInfo, int nSize);
	void printCheck();

private:
	int m_nSize;
	int *m_pnInfo;
};

