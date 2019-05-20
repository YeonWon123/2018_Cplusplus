#include <iostream>
#include "CPet.h"
#include "CDog.h"
#include "CCat.h"

using namespace std;

// main 함수 구현 [1점]
int main(void)
{
	// Main 함수에서 강아지 3 마리와 고양이 2마리를 생성하는데 
	// 출력을 for 문으로 하고 싶어서 array에 5개를 전부 넣고 싶다.
	// 이때 slicing problem을 방지하기 위해 2중 포인터를 사용하였다.
	// 이 2중 포인터는 2차원 배열처럼 사용할 것이다. (동적 할당 사용)

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

	pDog_0 = new CDog("똑똑이", "3000원짜리 사료", 15);
	pDog_1 = new CDog("팔팔이", "5000원짜리 사료", 100);
	pDog_2 = new CDog("칠칠이", "4000원짜리 사료", 56);
	pCat_0 = new CCat("까꿍이", "10000원짜리 사료", 59);
	pCat_1 = new CCat("냥냥이", "20000원짜리 사료", 120);

	pPet[0] = pDog_0;
	pPet[1] = pDog_1;
	pPet[2] = pDog_2;
	pPet[3] = pCat_0;
	pPet[4] = pCat_1;
	
	// ShowHappyness를 출력해 본다.
	pPet[0]->ShowHappiness(pPet[0]->getName());
	pPet[1]->ShowHappiness(pPet[1]->getName());
	pPet[2]->ShowHappiness(pPet[2]->getName());
	pPet[3]->ShowHappiness(pPet[3]->getName());
	pPet[4]->ShowHappiness(pPet[4]->getName());

	return 0;
}