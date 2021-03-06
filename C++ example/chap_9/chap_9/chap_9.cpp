// chap_9.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// C-string
/*

	char charString[10] = {'c', 'h', 'a', 'r}; // character array
	char String[10] = "char"; // character string

	char str[10];
	strcpy(str, "char"); // character string, 이 함수는 <cstring>이 필요함!

*/

#include "pch.h"
#include <cstring>	// character string (시험문제에는 안나옴)
#include <string>	// class string (시험문제에 이게 나옴!)
#include <iostream>
using namespace std;

int main()
{
	// 시험문제에는 나오지 않는 부분
	/*
	char chString1[30] = "Hello", chString2[30];
	strcpy_s(chString2, "Nam");
	strcmp(chString1, chString2);
	cout << chString1 << " " << chString2 << endl;
	
	cout << "chString2를 입력하세요: ";
	cin >> chString2;
	cout << chString2 << endl;

	strcat_s(chString1, chString2);
	cin.ignore(30, 'a');		// 30자만큼 무시하는데 그 중에 a가 나오면 거기까지만 무시한다.
	cin.getline(chString1, 10);	// 10자만큼 입력을 받는데 맨 마지막에는 '/n'이 추가되기 때문에, 실상은 9자만큼만 입력을 추가로 받을 수 있다.
	cout << chString1;
	*/
	
	// char 배열 변수 선언
	char chString1[30];

	// string 변수 선언
	string strEx;
	strEx = "How are you? ";
	cout << strEx << endl;

	// string class에서 getline 쓰는 방법
	string line;
	string c2;
	cout << "Enter a line of input: ";
	getline(cin, line);				// getline(cin, string변수);
	getline(cin, line) >> c2;		// 가능!
	getline(cin, line, '?' );		// ?가 나올때까지만 입력을 받음
	cout << line << "END OF OUTPUT" << endl;

	// find를 사용해서 strEx에서 "are"을 찾고, 그 위치를 반환해 보자
	int pos;
	pos = strEx.find("are");
	cout << "are의 위치: " << pos << endl;

	// strEx를 chString1에 strcpy_s를 이용해서 복사해 보자
	// 단, strEx.c_str()을 사용한다.
	strcpy_s(chString1, strEx.c_str());
	cout << chString1 << endl;
	
	return 0;
}


/*
int main(int argc, char *argv[]) // echo back the input arguments
{
	for (int i = 0; i < argc; i++)
	{
		cout << "Argument " << i << " " << argv[i] << endl;
	}
	return 0;
}
*/
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
