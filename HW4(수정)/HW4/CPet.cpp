#include <iostream>
#include <cstring>
#include "CPet.h"
using namespace std;

// default ������
CPet::CPet()
	:m_strName(NULL), m_strBreed(NULL)
{ 
}

// �Ű������� strName, strBreed�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
CPet::CPet(const char *strName, const char *strBreed)
{
	int length1 = strlen(strName) +1;
    m_strName = new char[length1];
	strcpy(m_strName,strName);

	int length2 = strlen(strBreed) + 1;
	m_strBreed = new char[length2];
	strcpy(m_strBreed, strBreed);
}

CPet::CPet(const CPet &ob)
{
	int length = strlen(ob.m_strName) +1;
    m_strName = new char[length];
	strcpy(m_strName,ob.m_strName);

	int length2 = strlen(ob.m_strBreed) + 1;
	m_strBreed = new char[length2];
	strcpy(m_strBreed, ob.m_strBreed);
}

// get �Լ��� set �Լ�
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

char* CPet::getBreed(void) const
{
	return m_strBreed;
}

void CPet::setBreed(const char *br)
{
	int length = strlen(br) + 1;
	if (m_strBreed != NULL)
		delete[] m_strBreed;
	m_strBreed = new char[length];
	strcpy(m_strBreed, br);
}

// operator overloading
const CPet& CPet::operator =(const CPet& rightSide)
{

	if (this == &rightSide)
		return *this;

	int length = strlen(rightSide.m_strName) + 1;

	if (m_strName != NULL)
		delete m_strName;

	m_strName = new char[length];
	strcpy(m_strName, rightSide.m_strName);




	length = strlen(rightSide.m_strBreed) + 1;
	if (m_strBreed != NULL)
		delete[] m_strBreed;

	m_strBreed = new char[length];
	strcpy(m_strBreed, rightSide.m_strBreed);

	return *this;
}

void CPet::ShowHappiness(char* strName)
{
	print();
	ShowHappyFace(strName);
	MakeSound(strName);
}

// destructor(�Ҹ���)
CPet::~CPet()
{
   if(m_strName != NULL)
	  delete[] m_strName;

   if (m_strBreed != NULL)
	   delete[] m_strBreed;
}