// Chap10.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	// 포인터 변수 p1, p2 선언
	int *p1, *p2;

	// 일반 변수 v1, v3 선언
	int v1 = 3, v2 = 4;

	// 포인터 변수 p1을 0으로 초기화
	p1 = 0;
	cout << "p1의 값: " << p1 << endl; // p1의 주소값 00000000이 출력됨

	// cout << "*p1의 값: " << *p1 << endl; // error! 아직 data공간이 없으므로 프로그램이 죽는다!

	cout << "&v1의 값: " << &v1 << endl; // 일반 변수 v1이 저장되어 있는 주소가 출력됨
	
	p1 = &v1;			 // 일반 변수 v1이 저장되어 있는 주소를 포인터 변수 p1에 대입
	cout << endl << "p1 = &v1 수행!" << endl << endl;

	cout << "p1의 값: " << p1 << endl;  // p1의 주소값(=&v1, 즉 일반 변수 v1이 저장되어 있는 주소)이 출력됨
	cout << "*p1의 값: " << *p1 << endl; // p1이 가리키고 있는 주소 안의 데이터가 출력됨(*p1 = v1, v1 = 3이므로 3 출력)

	p2 = &v2;			// 일반 변수 v2가 저장되어 있는 주소를 포인터 변수 p2에 대입
	*p1 = *p2;			// 값만 복사해오고, 주소값이 다르다

	cout << endl << "p2 = &v2; 수행!" << endl;
	cout << "*p1 = *p2; 수행! : 값만 복사해오고, 주소값이 다르다." << endl << endl;

	cout << "p1의 값: " << p1 << endl;
	cout << "*p1의 값: " << *p1 << endl;

	cout << "p2의 값: " << p2 << endl;
	cout << "*p2의 값: " << *p2 << endl;

	p1 = p2;			// 주소값과 값 모두 동일하게 복사한다.
	cout << endl << "p1 = p2; 수행! : 주소값과 값이 모두 동일하게 복사됨" << endl << endl;

	cout << "p1의 값: " << p1 << endl;
	cout << "*p1의 값: " << *p1 << endl;

	cout << "p2의 값: " << p2 << endl;
	cout << "*p2의 값: " << *p2 << endl << endl;



	cout << "20181101 start!" << endl << endl;

	int *p3, *p4;
	p3 = new int; p4 = new int;
	cout << "p3의 값: " << p3 << endl;
	cout << "p4의 값: " << p4 << endl;
	cout << "*p3의 값: " << *p3 << endl;
	cout << "*p4의 값: " << *p4 << endl << endl;

	*p3 = 7; *p4 = 8;

	cout << "*p3 = 7; *p4 = 8; 을 수행함" << endl;
	cout << "p3의 값: " << p3 << endl;
	cout << "p4의 값: " << p4 << endl;
	cout << "*p3의 값: " << *p3 << endl;
	cout << "*p4의 값: " << *p4 << endl << endl;

	p3 = p4;

	cout << "p3 = p4; 을 수행함" << endl;
	cout << "p3의 값: " << p3 << endl;
	cout << "p4의 값: " << p4 << endl;
	cout << "*p3의 값: " << *p3 << endl;
	cout << "*p4의 값: " << *p4 << endl << endl;

//	p3 = NULL; p4 = NULL;
//	delete p3; delete p4; // p3 = p4를 했기 때문에, p3를 죽이면 p4도 죽게 된다.
						  // 한번 delete한 자리를 또 delete하게 되니깐, 오류가 난다!!

	int *p5, **p6; // int *p5, **p6을 선언 

	int nSize = 3;
	p5 = new int[nSize]; // p5에 nSize(3)만큼의 크기의 array를 선언 (동적할당)
	p5[0] = 3; p5[1] = 4; p5[2] = 5; // p5에 값을 넣는다. (array의 index는 0부터 시작, p5[3]을 넣을 경우 오류!)
	cout << "p5[0] = " << p5[0] << endl;
	cout << "p5[1] = " << p5[1] << endl;
	cout << "p5[2] = " << p5[2] << endl;

	int nSizeRow = 3; int nSizeCol = 4; 
	p6 = new int*[nSizeRow];				// p6에는 2차원 배열로 3*4의 크기의 배열을 선언 (동적할당)
	for (int i = 0; i < nSizeRow; i++) {
		p6[i] = new int[nSizeCol];
	}

	// 1부터 12까지 넣기
	for (int i = 0; i < nSizeRow; i++)
		for (int j = 0; j < nSizeCol; j++)
			p6[i][j] = (4 * i) + (j+1);
	
	/*
	// 1부터 12까지 넣는 다른 방법 1
	p6[0][0] = 1;
	p6[0][1] = 2;
	p6[0][2] = 3;
	p6[0][3] = 4;
	p6[1][0] = 5;
	p6[1][1] = 6;
	p6[1][2] = 7;
	p6[1][3] = 8;
	p6[2][0] = 9;
	p6[2][1] = 10;
	p6[2][2] = 11;
	p6[2][3] = 12;
	*/ 

	/*
	// 1부터 12까지 넣는 다른 방법 2
	int cnt = 1;
	for (int i = 0; i < nSizeRow; i++) {
		for (int j = 0; j < nSizeCol; j++) {
			p6[i][j] = cnt;
			cnt++;
		}
	}
	*/

	// p6 안의 값을 출력해보기
	for (int i = 0; i < nSizeRow; i++) {
		for (int j = 0; j < nSizeCol; j++) {
			cout << "p6[" << i << "][" << j << "]: " << p6[i][j] << " ";
		}
		cout << endl;
	}

	// p5의 배열의 공간 지우기
	delete [] p5;

	// p6의 배열의 공간 지우기
	for (int i = 0; i < nSizeRow; i++)
		delete[] p6[i];
	delete[] p6;


	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
