#include <iostream>
#include "CPet.h"
#include "CDog.h"
#include "CCat.h"

using namespace std;

// main �Լ� ���� [1��]
int main(void)
{
	// Main �Լ����� ������ 3 ������ ����� 2������ �����ϴµ� 
	// ����� for ������ �ϰ� �; array�� 5���� ���� �ְ� �ʹ�.
	// �̶� slicing problem�� �����ϱ� ���� 2�� �����͸� ����Ͽ���.
	// �� 2�� �����ʹ� 2���� �迭ó�� ����� ���̴�. (���� �Ҵ� ���)

	CPet **pPet = new CPet*[5];
	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
		case 0: case 1: case 2:
			pPet[i] = new CDog;
			break;
		case 3: case 4:
			pPet[i] = new CCat;
		}
	}
	CDog *pDog_0, *pDog_1, *pDog_2;
	CCat *pCat_0, *pCat_1;

	pDog_0 = new CDog("�ȶ���", "3000��¥�� ���", 15);
	pDog_1 = new CDog("������", "5000��¥�� ���", 100);
	pDog_2 = new CDog("ĥĥ��", "4000��¥�� ���", 56);
	pCat_0 = new CCat("�����", "10000��¥�� ���", 59);
	pCat_1 = new CCat("�ɳ���", "20000��¥�� ���", 120);

	pPet[0] = pDog_0;
	pPet[1] = pDog_1;
	pPet[2] = pDog_2;
	pPet[3] = pCat_0;
	pPet[4] = pCat_1;
	
	// ShowHappyness�� ����� ����.
	pPet[0]->ShowHappiness(pPet[0]->getName());
	pPet[1]->ShowHappiness(pPet[1]->getName());
	pPet[2]->ShowHappiness(pPet[2]->getName());
	pPet[3]->ShowHappiness(pPet[3]->getName());
	pPet[4]->ShowHappiness(pPet[4]->getName());

	return 0;
}