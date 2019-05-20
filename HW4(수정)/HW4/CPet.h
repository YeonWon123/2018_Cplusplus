// coding by 20150413 ������
// HW4 : ���� 4�� [�� 6��]
// 2018-12-07(��) ���� : ������ ���� ��Ȯ�� ���ǿ� Feedback�� �޾Ƽ�
// ��ü���� ���α׷��� ���������Ͽ���, �ּ��� ÷���Ͽ���.
// �ּ��� ��� ������ ������ ���� ����� ���� �ٷ� ���� �ٿ� �����Ͽ���, �� �˾ƺ� �� �ְ� �����Ͽ���.

// �̹� ���������� ���α׷��� ���迡 ���� �Ƿ��� �����Ű���� �Ѵ�.
// ������ ������ ������ �������� ��� ���뿡 �����ϰ� �����ؾ� �Ѵ�.

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

// CPet Ŭ������ CDog, CCat Ŭ������ ������� �Ѵ�. [1��]
// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
// redefinition, virtual �Լ��� ���ʿ��ϰ� ���� �ʰ� ��Ȯ�ϰ� ���α׷��ؾ� �Ѵ�.[1��]

// CPet Ŭ������ �θ� Ŭ�����̴�.
class CPet
{
// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
// �����ڿ� �Լ��� ��� �ڽĿ� ����� �ܰ� ���ÿ� main�Լ������� ��� �����ؾ� �ϹǷ� public���� ���
public:
	// constructor(������)
	// �����ڴ� Default�� ���Ҿ 
	// �Ű������� strName, strBreed�� m_nActive / m_nMaintenanceLevel�� ���� �����ڸ� �� Ŭ������ �����Ѵ�.[1��]
	CPet();
	CPet(const char *strName, const char *strBreed);
	CPet(const CPet &ob);

	// get�Լ��� set�Լ�
	char *getName(void) const;
	void setName(const char *na);
	char *getBreed(void) const;
	void setBreed(const char *br);

	// operator overloading
	const CPet& operator =(const CPet &rightSide);

	// ShowHappiness �Լ��� MakeSound �Լ��� ShowHappyFace �Լ��� �θ���
	// �� �Լ��� CDog, CPet���� ���� �ڵ�� ���� �����ϹǷ�, �θ𿡼� �� ���� �����ϰ� �ڽĿ��� ��ӹ޴´�.
	void ShowHappiness(char* strName);				// �θ𿡼� �� ���� �����ϰ� �ڽĿ��� ��ӹ���
	virtual void ShowHappyFace(char* strName) = 0;  // �θ𿡼� �Ⱦ��ϱ� = 0 �� �ϰ� �ڽĿ� ���� ����
	virtual void MakeSound(char* strName) = 0;		// ������ ��ü���� �ٸ� �Ҹ��� ���� �Ѵ�.

	// �Լ� Print �� ������ ����ϴµ� �� Ŭ������ ��� �ʿ��ϴ�.
	// ��, 1) �θ� �Լ����� ����� ���� �ʰ�
	// 2) �ڽ� Ŭ�������� ���� �ٸ� ����� �ϹǷ�
	// (CDog���� �ִ� ������ �ְ� CCat���� �ִ� ������ ����)
	// virtual �Լ��� �����Ͽ���.
	virtual void print(void) = 0;		// �θ𿡼� �Ⱦ��ϱ� = 0 �� �ϰ� �ڽĿ� ���� ����, ����, �ڽĸ��� �ٸ�

	// destructor(�Ҹ���)
	~CPet();

// public, protected, private �� ������ �°� ���α׷��ؾ� �Ѵ�.[1��]
// �θ� Ŭ������ �Ű� ������ ��� ���ȼ��� �����԰� ���ÿ�, �ڽĿ� ����� �ְ� �ڽĿ��� ��밡���ؾ� �Ѵ�.
// �׷��� private���� ����� ��� �ڽ� Ŭ�������� �̸��� �̿��� ���� ������ �Ұ����ϴ�.
// ���� protected�� �����Ͽ� ���ȼ��� �����ϵ� �ڽ� Ŭ�������� ��� �����ϵ��� �Ѵ�.
// (��ó : ��ü���� ������ �����ϴ� Absolute C++, 674p)
protected: 
	// CDog, CCat �� Ŭ������ ��� ����� ������ ������, �θ� Ŭ�������� ����
	// CDog ���� m_strName, m_strBreed �� �ʿ��ϰ�, ���� CCat������ �����ϴ�.
	char *m_strName;
	char *m_strBreed;
};

#endif
 