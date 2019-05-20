#ifndef CDog_H
#define CDog_H

#include <iostream>
#include "CPet.h"

using namespace std;

class CDog: public CPet
{
public:
	CDog();
	CDog(const char *na, const char *br);
	CDog(const CDog &ob);
	~CDog();
	char *getBreed(void) const;
	void setBreed(const char *br);
	void barking(void);
	void printInfo(void);
	const CDog& operator =(const CDog &rightSide);

private:
	char *m_strBreed;
};

#endif