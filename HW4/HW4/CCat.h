#ifndef CCat_H
#define CCat_H

#include <iostream>
#include "CPet.h"

using namespace std;

class CCat: public CPet
{
public:
	CCat();
	CCat(const char *na, const char *br);
	CCat(const CCat& ob);
	char *getBreed(void) const;
	void setBreed(const char *br);	void printInfo(void);
	void barking();
	const CCat& operator=(const CCat& rightSide);
	~CCat();

private:
		char *m_strBreed;
};

#endif