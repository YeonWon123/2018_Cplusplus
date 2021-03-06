// CH12_02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream> // ifstream, ofstream 사용가능
#include <iomanip> // setw(), setprecision() 사용가능
using namespace std;

void outputStuff(ofstream & outStream);

int main()
{
	ofstream outStream;				// 객체 만들기
	outStream.open("Stuff.txt");	// 파일 열기
	outputStuff(outStream);			// 작업하기
	outStream.close();				// 파일 닫기
	return 0;
}

// Saving Flag Settings Example
void outputStuff(ofstream & outStream)
{
	// 현재 상태를 보관 + 새 상태를 설정
	int precisionSetting = outStream.precision(2);
	long flagSettings = outStream.setf(ios::fixed | ios::showpoint | ios::right);
	// cout << "precisionSetting은 " << precisionSetting << endl; // default 상태로 나온다 (default : 6)
	// cout << "flagSetting은 " << flagSettings << endl;		   // default 상태로 나온다 (flag : 513)
	
	// 사용하기 // setw() manipulator
	outStream << "Start" << setw(7) << "$" << 10.3 << setw(7) << "$" << 20.2 << endl;
	/*
	precisionSetting = outStream.precision(precisionSetting);
	flagSettings = outStream.flags(flagSettings);
	cout << "precisionSetting은 " << precisionSetting << endl; // 변경된 상태로 나온다
	cout << "flagSetting은 " << flagSettings << endl;		   // 변경된 상태로 나온다
	*/
	
	// 복원하기
	outStream.precision(precisionSetting);
	outStream.flags(flagSettings);
}