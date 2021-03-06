// CH16.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include "pch.h"
#include <iostream>
using namespace std;

//typedef char T;

// template으로 선언, 철자에 조심!(template)
template <class T> // template <typename T> 도 가능!!
void swapValues(T& var1, T& var2);

//void swapValue(int& var1, int& var2);
//void swapValues(char& var1, char& var2);

int main()
{
	int var1, var2;
	var1 = 3;
	var2 = 4;
	cout << var1 << var2 << endl;
	swapValues(var1, var2);
	cout << var1 << var2 << endl;

	char var3, var4;
	var3 = 'a';
	var4 = 'b';
	cout << var3 << var4 << endl;
	swapValues(var3, var4);
	cout << var3 << var4 << endl;
	return 0;
}

// 만약 .h와 .cpp로 나누어져 있다면, .h 파일에 templete 함수의 정의까지 같이 넣는다.
// 그렇게 함으로써 compile 과정에서 templete 함수가 생성(generate)되도록 한다.
// 또는, #include <... .cpp>를 함으로써 templete 함수가 생성되도록 한다.
template <class T> // template <typename T> 도 가능!!
void swapValues(T& var1, T& var2)
{
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

/*
// 매개변수 type만 다른 상황...!
// 이럴때 필요한 것이 templete이다.
// templete은 '틀'에 해당한다.
void swapValues(int& var1, int& var2)
{
	int temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

void swapValues(char& var1, char& var2)
{
	char temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}
*/