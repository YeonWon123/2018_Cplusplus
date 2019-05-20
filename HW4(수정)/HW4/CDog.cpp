#include <iostream>
#include "CDog.h"
#include <string>
using namespace std;

// default ������
CDog::CDog()
	:CPet()
{
	m_nActive = 0;
}

// �Ű������� strName, strBreed�� m_nActive�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
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

// MakeSound�Լ��� ȭ�� ��´����� ���� �Ҹ��� ���� ���ش�.
// PlaySound��� �Լ��� ����ϸ� wave ������ ���ͳݿ��� �ٿ�޾Ƽ� ����Ѵ�.
// �Ӽ����� ��Ŀ�� �Է��� �߰����Ӽ����� Winmm.lib �� �߰������ �ϰ�
// ��� include�� �ʿ��ϴµ� google �˻��� �ؼ� ã�ƺ���. 
// -> #include <Windows.h>, #include <mmsystem.h> , #pragma comment(lib, "winmm.lib") �� �ʿ��ϴ�. �̴� "CPet.h"�� ���ǵǾ� �ִ�.
void CDog::MakeSound(char* strName)
{ 
	// MakeSound �Լ��� CDog������ ���۸ۡ� �ϰ� �Ѵ�.
	cout << "�۸�" << endl;

	// PlaySound��� �Լ��� ����ϸ� wave ������ ���ͳݿ��� �ٿ�޾Ƽ� ����Ѵ�.
	if (strcmp(strName, "�ȶ���") == 0)
		PlaySound(TEXT("Dog-barking-noise1.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "������") == 0)
		PlaySound(TEXT("Dog-barking-noise2.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "ĥĥ��") == 0)
		PlaySound(TEXT("Dog-barking-noise3.wav"), NULL, SND_SYNC);
	else
	{
		cout << "����! �����ڿ��� �����ϼ���!";
		return;
	}
}

// ShowHappyFace �Լ������� ȭ�� ��´����� ���� ������ opencv�� �̿��ؼ� �����ش�. 
// ������ ���� ���뿡 �°� ���ͳݿ��� �ٿ�޾Ƽ� ����ϵ�, ������ ũ��� 200k ���� �̳��� �Ѵ�. [1��]
void CDog::ShowHappyFace(char* strName)
{
	// ShowHappyFace �Լ��� CDog������ �������� �����ϡ� �ϰ� �Ѵ�.
	cout << "������ ������" << endl;

	string address;
	if (strcmp(strName,"�ȶ���") == 0)
		address = "dog1.jpg";
	else if (strcmp(strName, "������") == 0)
		address = "dog2.jpg";
	else if (strcmp(strName, "ĥĥ��") == 0)
		address = "dog3.jpg";
	else
	{
		cout << "����! �����ڿ��� �����ϼ���!";
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

// get�Լ��� set�Լ�
int CDog::getActive(void)
{
	return m_nActive;
}

void CDog::setActive(int nActive)
{
	m_nActive = nActive;
}

// �Ҹ���
CDog::~CDog()
{
}
