// Chap10-part2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
/*
실습예제 문제
CDyna 클래스를 생성하고
멤버변수로 int m_nSize, int *m_pnSchedule; 을 만든다.

멤버함수로 ShowSchedule을 만들어서 m_pnSchedule 에 공간을 할당한다.
만약 할당되었으면 값을 출력하고 안되었으면 안됨을 알림
메인 함수에서 pointer변수로 객체를 선언하고, 클래스 객체를 new로 만들고 화면에 출력한다.
멤버함수로 SetInfo(int nSize, int*pSch) 해서 값을 넣는것 만듬.
메인함수에서 3개 크기인 schedule 넣고 화면 출력

Destruct에서 *m_pnSchedule 이 NULL이 아니면 메모리를 풀어준다.
물론 생성자에서 처음에 m_pnSchedule = NULL; 로 했었다.
Main함수 끝에서 delete pDyna해줌
Main 함수에서 위의 객체를 delete하기전에 새로운 객체를 한 개 만들고 값을 할당한다. 
CDyna anotherDyna;anotherDyna = *pDyna;
화면에 출력 // 죽죠?
Operator = overloading 한다.  10-43쪽 참조
*/

#include "pch.h"
#include "CDyna.h"

int main()
{
	CDyna *pDyna = new CDyna; // 포인터 변수로 객체를 선언 (클래스 객체를 new로 만들기)
	pDyna->ShowSchedule();    // pDyna가 포인터 변수이므로, 화살표로 멤버 함수를 부른다.

	const int nSize = 3;					// const int 변수 선언
	int pSch[nSize] = { 1000, 1200, 1400 };	// 1차원 배열 선언(main함수에서 size가 3인 schedule(시간)을 담는 int형 배열)
	pDyna->SetInfo(nSize, pSch);			// pDyna가 포인터 변수이므로, 화살표로 멤버 함수를 부른다.
	pDyna->ShowSchedule();    // pDyna가 포인터 변수이므로, 화살표로 멤버 함수를 부른다.

	// CDyna anotherDyna = *pDyna; // error! operator overloading시 오류가 난다. 18줄과 19줄로 분리해주자!
	CDyna anotherDyna;
	anotherDyna = *pDyna; // 새로운 객체를 한 개 만들고 값을 할당한다.

	delete pDyna;			  // 포인터 변수에 객체를 만들면 (클래스 객체를 new로 만들었으면) 반드시 풀어주자 (delete로)!
							  // 이를 실행하면 pDyna의 destructor가 호출된다.



	return 0; // anotherDyna를 죽여야 되는데 이미 pDyna는 죽어 있음... anotherDyna는 pDyna를 shallow copy해서 그렇다!
			  // 그래서 프로그램이 죽는다. (디버그시 예외가 발생한다.)
			  // 이는 operator overloading으로 deep copy를 적용해서 예방할 수 있다.
}