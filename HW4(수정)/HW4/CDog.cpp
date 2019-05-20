#include <iostream>
#include "CDog.h"
#include <string>
using namespace std;

// default 생성자
CDog::CDog()
	:CPet()
{
	m_nActive = 0;
}

// 매개변수로 strName, strBreed과 m_nActive를 갖는 생성자를 각 클래스에 구현한다.[1점]
CDog::CDog(const char *strName, const char *strBreed, int nActive)
	:CPet(strName, strBreed)
{
	m_nActive = nActive;
}

CDog::CDog(const CDog &ob)
	:CPet(ob)
{
	m_nActive = ob.m_nActive;
}

// MakeSound함수는 화면 출력다음에 실제 소리가 나게 해준다.
// PlaySound라는 함수를 사용하며 wave 파일은 인터넷에서 다운받아서 사용한다.
// 속성에서 링커의 입력의 추가종속성에서 Winmm.lib 를 추가해줘야 하고
// 몇개의 include가 필요하는데 google 검색을 해서 찾아본다. 
// -> #include <Windows.h>, #include <mmsystem.h> , #pragma comment(lib, "winmm.lib") 가 필요하다. 이는 "CPet.h"에 정의되어 있다.
void CDog::MakeSound(char* strName)
{ 
	// MakeSound 함수는 CDog에서는 “멍멍” 하게 한다.
	cout << "멍멍" << endl;

	// PlaySound라는 함수를 사용하며 wave 파일은 인터넷에서 다운받아서 사용한다.
	if (strcmp(strName, "똑똑이") == 0)
		PlaySound(TEXT("Dog-barking-noise1.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "팔팔이") == 0)
		PlaySound(TEXT("Dog-barking-noise2.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "칠칠이") == 0)
		PlaySound(TEXT("Dog-barking-noise3.wav"), NULL, SND_SYNC);
	else
	{
		cout << "오류! 관리자에게 문의하세요!";
		return;
	}
}

// ShowHappyFace 함수에서는 화면 출력다음에 실제 사진을 opencv를 이용해서 보여준다. 
// 사진은 각자 내용에 맞게 인터넷에서 다운받아서 사용하되, 영상의 크기는 200k 단위 이내로 한다. [1점]
void CDog::ShowHappyFace(char* strName)
{
	// ShowHappyFace 함수는 CDog에서는 “강아지 스마일” 하게 한다.
	cout << "강아지 스마일" << endl;

	string address;
	if (strcmp(strName,"똑똑이") == 0)
		address = "dog1.jpg";
	else if (strcmp(strName, "팔팔이") == 0)
		address = "dog2.jpg";
	else if (strcmp(strName, "칠칠이") == 0)
		address = "dog3.jpg";
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


void CDog::print(void)
{
	cout << endl;
	cout << "CDog Information" << endl;
	cout << "Name: " << m_strName << endl;
	cout << "m_strBreed: " << m_strBreed << endl;
	cout << "m_nActive: " << m_nActive << endl;
}

// operator overloading
const CDog& CDog::operator =(const CDog& rightSide)
{
	if(this == &rightSide)
		return *this;
	
	CPet::operator=(rightSide);
	
	m_nActive = rightSide.m_nActive;

	return *this;
}

// get함수와 set함수
int CDog::getActive(void)
{
	return m_nActive;
}

void CDog::setActive(int nActive)
{
	m_nActive = nActive;
}

// 소멸자
CDog::~CDog()
{
}
