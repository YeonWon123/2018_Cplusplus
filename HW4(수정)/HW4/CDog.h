#ifndef CDog_H
#define CDog_H

#include <iostream>
#include "CPet.h"

using namespace std;

// CPet 클래스와 CDog, CCat 클래스를 만들고자 한다. [1점]
// CDog class는 자식 클래스이다.
class CDog: public CPet
{
// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
public:
	// constructor(생성자)
	// 생성자는 Default와 더불어서 
	// 매개변수로 strName, strBreed과 m_nActive / m_nMaintenanceLevel를 갖는 생성자를 각 클래스에 구현한다.[1점]
	CDog();
	CDog(const char *strName, const char *strBreed, int nActive);
	CDog(const CDog &ob);

	// destructor(소멸자)
	~CDog();

	// MakeSound 함수는 CDog에서는 “멍멍” 하게 한다.
	void MakeSound(char* strName);
	// ShowHappyFace 함수는 CDog에서는 “강아지 스마일” 하게 한다.
	void ShowHappyFace(char* strName);
	void print(void);
	const CDog& operator =(const CDog &rightSide);
	int getActive(void);
	void setActive(int nActive);

// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
// CDog의 자식 클래스가 없으므로, private으로 선언하여 그 보안성을 높인다.
private:
	// CDog에는 m_nActive 라는 변수가 있는데 운동량을 나타낸다.
	int m_nActive;
};

#endif