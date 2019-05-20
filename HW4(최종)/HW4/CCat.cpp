#include <iostream>
#include "CCat.h"

using namespace std;

// default ������
CCat::CCat()
	:CPet()
{
	m_nMaintenanceLevel = 0;
}

// �Ű������� strName, strBreed�� m_nMaintenanceLevel�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
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

// MakeSound�Լ��� ȭ�� ��´����� ���� �Ҹ��� ���� ���ش�.
// PlaySound��� �Լ��� ����ϸ� wave ������ ���ͳݿ��� �ٿ�޾Ƽ� ����Ѵ�.
// �Ӽ����� ��Ŀ�� �Է��� �߰����Ӽ����� Winmm.lib �� �߰������ �ϰ�
// ��� include�� �ʿ��ϴµ� google �˻��� �ؼ� ã�ƺ���. 
// -> #include <Windows.h>, #include <mmsystem.h> , #pragma comment(lib, "winmm.lib") �� �ʿ��ϴ�. �̴� "CPet.h"�� ���ǵǾ� �ִ�.
void CCat::MakeSound(char* strName)
{ 
	// MakeSound �Լ��� CCat������ ���߿ˡ� �ϰ� �Ѵ�.
	cout << "�߿�" << endl;
	if (strcmp(strName, "�����") == 0)
		PlaySound(TEXT("Cat-barking-noise1.wav"), NULL, SND_SYNC);
	else if (strcmp(strName, "�ɳ���") == 0)
		PlaySound(TEXT("Cat-barking-noise2.wav"), NULL, SND_SYNC);
	else
	{
		cout << "����! �����ڿ��� �����ϼ���!";
		return;
	}
}

// ShowHappyFace �Լ������� ȭ�� ��´����� ���� ������ opencv�� �̿��ؼ� �����ش�. 
// ������ ���� ���뿡 �°� ���ͳݿ��� �ٿ�޾Ƽ� ����ϵ�, ������ ũ��� 200k ���� �̳��� �Ѵ�. [1��]
void CCat::ShowHappyFace(char* strName)
{
	// ShowHappyFace �Լ��� CCat������ ������� �̼ҡ� �ϰ� �Ѵ�.
	cout << "����� �̼�" << endl;
	string address;
	if (strcmp(strName, "�����") == 0)
		address = "cat1.jpg";
	else if (strcmp(strName, "�ɳ���") == 0)
		address = "cat2.jpg";
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

// get�Լ��� set�Լ�
int CCat::getMaintenanceLevel(void)
{
	return m_nMaintenanceLevel;
}

void CCat::setMaintenanceLevel(int nMaintenanceLevel)
{
	m_nMaintenanceLevel = nMaintenanceLevel;
}

// �Ҹ���
CCat::~CCat()
{
}
