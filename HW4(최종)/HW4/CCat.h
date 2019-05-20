#ifndef CCat_H
#define CCat_H

#include <iostream>
#include "CPet.h"

using namespace std;

// CPet Ŭ������ CDog, CCat Ŭ������ ������� �Ѵ�. [1��]
// CCat class�� �ڽ� Ŭ�����Դϴ�.
class CCat: public CPet
{
public:
	// constructor(������)
	// �����ڴ� Default�� ���Ҿ 
	// �Ű������� strName, strBreed�� m_nActive / m_nMaintenanceLevel�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
	CCat();
	CCat(const char *strName, const char *strBreed, int nMaintenanceLevel);
	CCat(const CCat& ob);
	~CCat();

	// MakeSound �Լ��� CCat������ ���߿ˡ� �ϰ� �Ѵ�.
	void MakeSound(char* strName);
	// ShowHappyFace �Լ��� CCat������ ������� �̼ҡ� �ϰ� �Ѵ�.
	void ShowHappyFace(char* strName);
	void print(void);
	const CCat& operator =(const CCat& rightSide);
	int getMaintenanceLevel(void);
	void setMaintenanceLevel(int nMaintenanceLevel);

// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
// CCat�� �ڽ� Ŭ������ �����Ƿ�, private���� �����Ͽ� �� ���ȼ��� ���δ�.
private:
	// CCat������ m_nMaintenanceLevel ��� ������ �ִµ� �󸶳� ���� �������� ��Ÿ����.
	int m_nMaintenanceLevel;
};

#endif