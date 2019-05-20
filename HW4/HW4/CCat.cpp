#include <iostream>
#include "CCat.h"

using namespace std;

CCat::CCat()
	:CPet()
{
	m_strBreed = NULL;
}

CCat::CCat(const char *na, const char *br)
	:CPet(na)
{
	int length = strlen(br) + 1;
	 m_strBreed = new char[length];
	 strcpy(m_strBreed, br);
}

CCat::CCat(const CCat &ob)
	:CPet(ob)
{
	int length = strlen(ob.m_strBreed) + 1;
	m_strBreed = new char[length];
	strcpy(m_strBreed, ob.m_strBreed);
}

char* CCat::getBreed(void) const
{
	return m_strBreed;
}

void CCat::setBreed(const char *br)
{
	int length = strlen(br) + 1;
	if(m_strBreed !=NULL)
	   delete [] m_strBreed;
	m_strBreed = new char[length];
	strcpy(m_strBreed, br);
}

void CCat::barking(void)
{ 
	cout << "¾ß¿Ë!" << endl;
}

void CCat::printInfo(void)
{
	cout << endl;
	cout << "CCat Information" << endl;
	cout << "Name: " << m_strName << endl;
	cout << "m_strBreed: " << m_strBreed << endl;
	cout << "Barking: "; barking();
}

const CCat& CCat::operator =(const CCat& rightSide)
{
	if(this == &rightSide)
		return *this;
	
	CPet::operator=(rightSide);
	
	int length = strlen(rightSide.m_strBreed);
	if(m_strBreed !=NULL)
		delete [] m_strBreed;
	m_strBreed = new char[length];
	strcpy(m_strBreed,rightSide.m_strBreed);

	return *this;
}

CCat::~CCat()
{
	if(m_strBreed !=NULL)
		delete [] m_strBreed;
}
