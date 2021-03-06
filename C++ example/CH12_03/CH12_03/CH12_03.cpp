// CH12_03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Data.h"
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	fstream fileStream;
	fileStream.open("stuff", ios::out | ios::binary);	// txt파일이 아닌 binary file로 만든다.

	for (int nNum = 1; nNum <= 1000; nNum++) {
		fileStream.write((char*)&nNum, sizeof(int));
	}

	fileStream.flush();
	fileStream.close();

	fileStream.open("stuff", ios::in | ios::out | ios::binary);	// ios::in -> 입력이 된다. // ios::out -> 출력이 된다.

	for (int i = 1; i <= 10; i++) {
		int nNum = 0;
		fileStream.read((char*)&nNum, sizeof(int));
		cout << nNum << endl;
	}

	int nNum = 6;
	fileStream.seekp((5 - 1) * sizeof(int));
	fileStream.write((char*)&nNum, sizeof(int));
	fileStream.seekg((2 - 1) * sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		fileStream.read((char*)&nNum, sizeof(int));
		cout << nNum << endl;
	}

	fileStream.close();

	// int값을 쓰는게 아니라 Structure나 class일 때

	Data Datafile[11];

	for (int i = 1; i <= 10; i++)
	{
		Datafile[i].SetName("성적이예요!");
		Datafile[i].SetScore(i * 10);
	}

	fileStream.open("stuff2", ios::out | ios::binary);	// ios::in -> 입력이 된다. // ios::out -> 출력이 된다.

	for (int nNum = 1; nNum <= 10; nNum++)
	{
		//string n = Datafile[nNum].GetName();
		//int s = Datafile[nNum].GetScore();
		fileStream.write((char*)&Datafile[nNum], sizeof(Data));
		//fileStream.write((char*)&n, sizeof(string));
		//fileStream.write((char*)&s, sizeof(int));
	}

	fileStream.write((char*)&Datafile, sizeof(Data));

	fileStream.flush();
	fileStream.close();

	fileStream.open("stuff2", ios::in | ios::out | ios::binary);	// ios::in -> 입력이 된다. // ios::out -> 출력이 된다.

	fileStream.read((char*)&Datafile, sizeof(Data));

	for (int i = 1; i < 3; i++)
	{
		int nNum = 0;
		//string n = Datafile[nNum].GetName();
		//int s = Datafile[nNum].GetScore();
		fileStream.read((char*)&Datafile[nNum], sizeof(Data));
		cout << Datafile[nNum].GetName() << " " << Datafile[nNum].GetScore() << endl;
		//fileStream.write((char*)&n, sizeof(string));
		//fileStream.write((char*)&s, sizeof(int));
	}

	Data Datafile2[11];

	for (int i = 1; i <= 10; i++)
	{
		Datafile2[i].SetName("값을 바꿔 볼까요!");
		Datafile2[i].SetScore(i * 5);
	}

	int nNum = 6;
	fileStream.seekp((5 - 1) * sizeof(Data));
	fileStream.write((char*)&Datafile2[nNum], sizeof(Data));
	fileStream.seekg((2 - 1) * sizeof(Data));

	for (int i = 0; i < 4; i++)
	{
		fileStream.read((char*)&Datafile2[nNum], sizeof(Data));
		cout << nNum << endl;
	}


	cout << "이제 fileStream.close()할거예요!" << endl;

	fileStream.close();
	cout << "fileStream 끝!" << endl;

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
