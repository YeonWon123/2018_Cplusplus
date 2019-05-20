#ifndef CDog_H
#define CDog_H

#include <iostream>
#include "CPet.h"

using namespace std;

// CPet Ŭ������ CDog, CCat Ŭ������ ������� �Ѵ�. [1��]
// CDog class�� �ڽ� Ŭ�����̴�.
class CDog: public CPet
{
// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
public:
	// constructor(������)
	// �����ڴ� Default�� ���Ҿ 
	// �Ű������� strName, strBreed�� m_nActive / m_nMaintenanceLevel�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
	CDog();
	CDog(const char *strName, const char *strBreed, int nActive);
	CDog(const CDog &ob);

	// destructor(�Ҹ���)
	~CDog();

	// MakeSound �Լ��� CDog������ ���۸ۡ� �ϰ� �Ѵ�.
	void MakeSound(char* strName);
	// ShowHappyFace �Լ��� CDog������ �������� �����ϡ� �ϰ� �Ѵ�.
	void ShowHappyFace(char* strName);
	void print(void);
	const CDog& operator =(const CDog &rightSide);
	int getActive(void);
	void setActive(int nActive);

// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
// CDog�� �ڽ� Ŭ������ �����Ƿ�, private���� �����Ͽ� �� ���ȼ��� ���δ�.
private:
	// CDog���� m_nActive ��� ������ �ִµ� ����� ��Ÿ����.
	int m_nActive;
};

#endif