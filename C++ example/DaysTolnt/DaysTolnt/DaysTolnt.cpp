// 2-20 실습예제
// 2-27 실습예제
#include <iostream>
#include <string>	// string 변수를 선언하기 위해 필요
using namespace std;

int main()
{
	string strDays;	// string 변수 선언
	int nDays;
	cout << "요일을 입력하세요 : ";
	cin >> strDays;	// 사용자 입력받아 string 변수 strDays에 넣음

	if (strDays == "Monday")
	{
		nDays = 1;
	}
	else if (strDays == "Tuesday")
	{
		nDays = 2;
	}
	else if (strDays == "Wednesday")
	{
		nDays = 3;
	}
	else if (strDays == "Thursday")
	{
		nDays = 4;
	}
	else if (strDays == "Friday")
	{
		nDays = 5;
	}
	else if (strDays == "Saturday")
	{
		nDays = 6;
	}
	else if (strDays == "Sunday")
	{
		nDays = 7;
	}
	else
	{
		cout << "요일이 아닙니다!" << endl;
		return 0;
	}

	cout << "오늘은 " << nDays << "번째 요일" << endl;

	switch (nDays)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			cout << "주중엔 열심히" << endl;
			break;
		case 5:
		case 6:
		case 7:
			cout << "주말은 즐겁게" << endl;
			break;
		default:
			cout << "이건 요일이 아니잖아요" << endl;
	}

	return 0;
}