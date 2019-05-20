#include <iostream>
#include "CDog.h"

using namespace std;

CDog::CDog()
	:CPet()
{
	m_strBreed = NULL;
}

CDog::CDog(const char *na, const char *br)
	:CPet(na)
{
	int length = strlen(br) + 1;
	 m_strBreed = new char[length];
	 strcpy(m_strBreed, br);
}

CDog::CDog(const CDog &ob)
	:CPet(ob)
{
	int length = strlen(ob.m_strBreed) + 1;
	m_strBreed = new char[length];
	strcpy(m_strBreed, ob.m_strBreed);
}

char* CDog::getBreed(void) const
{
	return m_strBreed;
}

void CDog::setBreed(const char *br)
{
	int length = strlen(br)+1;
	if(m_strBreed !=NULL)
	   delete [] m_strBreed;
	m_strBreed = new char[length];
	strcpy(m_strBreed, br);
}

void CDog::barking(void)
{ 
	cout << "¸Û¸Û!" << endl;
}

void CDog::printInfo(void)
{
	cout << endl;
	cout << "CDog Information" << endl;
	cout << "Name: " << m_strName << endl;
	cout << "m_strBreed: " << m_strBreed << endl;
	cout << "Barking: "; barking();
}

const CDog& CDog::operator =(const CDog& rightSide)
{
	if(this == &rightSide)
		return *this;
	
	CPet::operator=(rightSide);
	
	int length = strlen(rightSide.m_strBreed) + 1;
	if(m_strBreed !=NULL)
		delete [] m_strBreed;
	m_strBreed = new char[length];
	strcpy(m_strBreed, rightSide.m_strBreed);

	return *this;
}

CDog::~CDog()
{
	if(m_strBreed != NULL)
		delete [] m_strBreed;
}
