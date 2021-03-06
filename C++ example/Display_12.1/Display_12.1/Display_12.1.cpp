// Display_12.1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
// 파일 입출력을 위해서는 fstream이 꼭 필요하다.
#include <fstream>
// namespace를 using 해준다.
using std::ifstream;
using std::ofstream;
using std::ios;
using std::endl;
using std::cout;

int main()
{
	// 1. 객체 만들기
	ifstream inStream;
	ofstream outStream;

	// 2. 객체 연동(객체와 physical file을 connect)
	inStream.open("infile.txt");
	if (inStream.fail())
	{
		cout << "File open failed.\n";
		exit(1);
	}
	outStream.open("outfile.txt", ios::app);

	// 3. 마음껏 사용하기 (예 : inStream >> number; )
	int next, sum = 0;
	int k = 5;
	while(k != 0) {
		inStream >> next;
	// while (inStream >> next) {
	// while (! inStream.eof()) { // 파일의 끝을 검사해서 알아낸다.
		// inStream >> next;
		sum = sum + next;
		cout << next << endl;
		k--;
	}
	outStream << "The sum of the first 3\n"	
		<< "numbers in infile.txt\n" 
		<< "is " << sum
		<< endl;

	// 4. 닫아주기
	inStream.close();
	outStream.close();

	return 0;
}