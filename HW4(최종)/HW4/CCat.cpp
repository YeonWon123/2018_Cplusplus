#include <iostream>
#include "CCat.h"

using namespace std;

// default 생성자
CCat::CCat()
	:CPet()
{
	m_nMaintenanceLevel = 0;
}

// 매개변수로 strName, strBreed과 m_nMaintenanceLevel를 갖는 생성자를 각 클래스에 구현한다.[1점]
CCat::CCat(const char *strName, const char *strBreed, int nMaintenanceLevel)
	:CPet(strName, strBreed)
{
	m_nMaintenanceLevel = nMaintenanceLevel;
}

CCat::CCat(const CCat &ob)
	:CPet(ob)
{
	m_nMaintenanceLevel = ob.m_nMaintenanceLevel;
}

// MakeSound함수는 화면 출력다음에 실제 소리가 나게 해준다.
// PlaySound라는 함수를 사용하며 wave 파일은 인터넷에서 다운받아서 사용한다.
// 속성에서 링커의 입력의 추가종속성에서 Winmm.lib 를 추가해줘야 하고
// 몇개의 include가 필요하는데 google 검색을 해서 찾아본다. 
// -> #include <Windows.h>, #include <mmsystem.h> , #pragma comment(lib, "winmm.lib") 가 필요하다. 이는 "CPet.h"에 정의되어 있다.
void CCat::MakeSound(char* strName)
{ 
	// MakeSound 함수는 CCat에서는 “야옹” 하게 한다.
	cout << "야옹" << endl;
	if (strcmp(strName, "까꿍이") == 0)
		PlaySound(TEXT("Cat-barking-noise1.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "냥냥이") == 0)
		PlaySound(TEXT("Cat-barking-noise2.wav"), NULL, SND_SYNC);
	else
	{
		cout << "오류! 관리자에게 문의하세요!";
		return;
	}
}

// ShowHappyFace 함수에서는 화면 출력다음에 실제 사진을 opencv를 이용해서 보여준다. 
// 사진은 각자 내용에 맞게 인터넷에서 다운받아서 사용하되, 영상의 크기는 200k 단위 이내로 한다. [1점]
void CCat::ShowHappyFace(char* strName)
{
	// ShowHappyFace 함수는 CCat에서는 “고양이 미소” 하게 한다.
	cout << "고양이 미소" << endl;
	string address;
	if (strcmp(strName, "까꿍이") == 0)
		address = "cat1.jpg";
	else if (strcmp(strName, "냥냥이") == 0)
		address = "cat2.jpg";
	else
	{
		cout << "오류! 관리자에게 문의하세요!";
		return;
	}

	Mat image;
	image = imread(address);
	namedWindow("Pets", WINDOW_AUTOSIZE);
	imshow("Pets", image);
	waitKey(10);
}

void CCat::print(void)
{
	cout << endl;
	cout << "CCat Information" << endl;
	cout << "Name: " << m_strName << endl;
	cout << "m_strBreed: " << m_strBreed << endl;
	cout << "m_nMaintenanceLevel: " << m_nMaintenanceLevel << endl;
}

// operator overloading
const CCat& CCat::operator =(const CCat& rightSide)
{
	if(this == &rightSide)
		return *this;
	
	CPet::operator=(rightSide);
	
	m_nMaintenanceLevel = rightSide.m_nMaintenanceLevel;

	return *this;
}

// get함수와 set함수
int CCat::getMaintenanceLevel(void)
{
	return m_nMaintenanceLevel;
}

void CCat::setMaintenanceLevel(int nMaintenanceLevel)
{
	m_nMaintenanceLevel = nMaintenanceLevel;
}

// 소멸자
CCat::~CCat()
{
}
