// coding by 20150413 남윤원
// HW4 : 숙제 4번 [총 6점]
// 2018-12-07(목) 수정 : 숙제에 관한 명확한 정의와 Feedback을 받아서
// 전체적인 프로그램을 유지보수하였고, 주석을 첨가하였다.
// 주석의 경우 문제의 내용을 위에 써놓은 다음 바로 밑의 줄에 구현하여서, 잘 알아볼 수 있게 유도하였다.

// 이번 숙제에서는 프로그램의 설계에 관한 실력을 고취시키고자 한다.
// 다음에 적어진 내용을 여러분이 배운 내용에 적합하게 설계해야 한다.

#ifndef CPet_H
#define CPet_H
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#pragma comment(lib, "winmm.lib")

using namespace cv;
using namespace std;

// CPet 클래스와 CDog, CCat 클래스를 만들고자 한다. [1점]
// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
// redefinition, virtual 함수가 불필요하게 들어가지 않고 정확하게 프로그램해야 한다.[1점]

// CPet 클래스는 부모 클래스이다.
class CPet
{
// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
// 생성자와 함수의 경우 자식에 상속해 줌과 동시에 main함수에서도 사용 가능해야 하므로 public으로 사용
public:
	// constructor(생성자)
	// 생성자는 Default와 더불어서 
	// 매개변수로 strName, strBreed과 m_nActive / m_nMaintenanceLevel를 갖는 생성자를 각 클래스에 구현한다.[1점]
	CPet();
	CPet(const char *strName, const char *strBreed);
	CPet(const CPet &ob);

	// get함수와 set함수
	char *getName(void) const;
	void setName(const char *na);
	char *getBreed(void) const;
	void setBreed(const char *br);

	// operator overloading
	const CPet& operator =(const CPet &rightSide);

	// ShowHappiness 함수는 MakeSound 함수와 ShowHappyFace 함수를 부른다
	// 이 함수는 CDog, CPet에서 같은 코드로 동작 가능하므로, 부모에서 한 번만 정의하고 자식에서 상속받는다.
	void ShowHappiness(char* strName);				// 부모에서 한 번만 정의하고 자식에서 상속받음
	virtual void ShowHappyFace(char* strName) = 0;  // 부모에서 안쓰니깐 = 0 을 하고 자식에 각각 만듬
	virtual void MakeSound(char* strName) = 0;		// 각각의 객체마다 다른 소리가 나야 한다.

	// 함수 Print 는 내용을 출력하는데 두 클래스에 모두 필요하다.
	// 단, 1) 부모 함수에서 사용을 하지 않고
	// 2) 자식 클래스에서 서로 다른 출력을 하므로
	// (CDog에만 있는 변수가 있고 CCat에만 있는 변수가 있음)
	// virtual 함수로 설계하였다.
	virtual void print(void) = 0;		// 부모에서 안쓰니깐 = 0 을 하고 자식에 각각 만듬, 또한, 자식마다 다름

	// destructor(소멸자)
	~CPet();

// public, protected, private 의 종류에 맞게 프로그램해야 한다.[1점]
// 부모 클래스의 매개 변수의 경우 보안성을 유지함과 동시에, 자식에 상속해 주고 자식에서 사용가능해야 한다.
// 그러나 private으로 사용할 경우 자식 클래스에서 이름을 이용한 직접 접근이 불가능하다.
// 따라서 protected로 설정하여 보안성을 유지하되 자식 클래스에서 사용 가능하도록 한다.
// (출처 : 객체지향 원리로 이해하는 Absolute C++, 674p)
protected: 
	// CDog, CCat 두 클래스에 모두 공통된 변수가 있으면, 부모 클래스에서 생성
	// CDog 에는 m_strName, m_strBreed 가 필요하고, 역시 CCat에서도 동일하다.
	char *m_strName;
	char *m_strBreed;
};

#endif
 