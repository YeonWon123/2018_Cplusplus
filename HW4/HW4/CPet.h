#ifndef CPet_H
#define CPet_H
#include <iostream>
using namespace std;

// 부모 클래스입니다.
class CPet
{
public:
	CPet();
	CPet(const char *na);
	CPet(const CPet &ob);
	char *getName(void) const;
	void setName(const char *na);
	const CPet& operator =(const CPet &rightSide);
	virtual void printInfo(void) = 0;
	virtual void barking();
	virtual ~CPet();

protected:
	char *m_strName;
};

#endif
  