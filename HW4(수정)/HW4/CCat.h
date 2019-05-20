#ifndef CCat_H
#define CCat_H

#include <iostream>
#include "CPet.h"

using namespace std;

// CPet 클래스와 CDog, CCat 클래스를 만들고자 한다. [1점]
// CCat class는 자식 클래스입니다.
class CCat: public CPet
{
public:
	// constructor(생성자)
	// 생성자는 Default와 더불어서 
	// 매개변수로 strName, strBreed과 m_nActive / m_nMaintenanceLevel를 갖는 생성자를 각 클래스에 구현한다.[1점]
	CCat();
	CCat(const char *strName, const char *strBreed, int nMaintenanceLevel);
	CCat(const CCat& ob);
	~CCat();

	// MakeSound 함수는 CCat에서는 “야옹” 하게 한다.
	void MakeSound(char* strName);
	// ShowHappyFace 함수는 CCat에서는 “고양이 미소” 하게 한다.
	void ShowHappyFace(char* strName);
	void print(void);
	const CCat& operator =(const CCat& rightSide);
	int getMaintenanceLevel(void);
	void setMaintenanceLevel(int nMaintenanceLevel);

// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
// CCat의 자식 클래스가 없으므로, private으로 선언하여 그 보안성을 높인다.
private:
	// CCat에서는 m_nMaintenanceLevel 라는 변수가 있는데 얼마나 손이 가는지를 나타낸다.
	int m_nMaintenanceLevel;
};

#endif