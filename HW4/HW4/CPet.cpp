#include <iostream>
#include <cstring>
#include "CPet.h"
using namespace std;

CPet::CPet()
	:m_strName(NULL)
{ 
}

CPet::CPet( const char *na)
{
	int length = strlen(na) +1;
    m_strName = new char[length];
	strcpy(m_strName,na);
}

CPet::CPet(const CPet &ob)
{
	int length = strlen(ob.m_strName) +1;
    m_strName = new char[length];
	strcpy(m_strName,ob.m_strName);
}

char *CPet::getName(void) const
{
	return m_strName;
}


void CPet::setName(const char *na)
{
	int length = strlen(na) + 1;
	
	if(m_strName != NULL){
		delete m_strName;
	}
    	
	m_strName = new char[length];
	strcpy(m_strName,na);

}


const CPet& CPet::operator =(const CPet& rightSide)
{

	if(this == &rightSide)
		return *this;

	int length = strlen(rightSide.m_strName) + 1;
	
	if(m_strName != NULL){
		delete m_strName;
	}
    	
	m_strName = new char[length];
	strcpy(m_strName,rightSide.m_strName);

	return *this;
}

/*
void CPet::printInfo(void)
{
	cout << endl << "CPet Information" << endl;
}
*/

void CPet::barking(void)
{
	cout << "반려동물 짖기";
}

CPet::~CPet()
{
   if(m_strName != NULL)
	  delete m_strName;
}