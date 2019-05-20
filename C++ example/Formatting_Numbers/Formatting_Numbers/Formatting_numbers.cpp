#include <iostream>
using namespace std;

int main()
{
	// 소수점 아래 자릿수를 건드리지 않음.
	cout << "최초설정입니다." << endl;
	cout << 17.25 / 4.1 << endl;		// 결과값 : 4.20732
	cout << 4.6 / 94.5 << endl;			// 결과값 : 0.0486772
	cout << endl;

	// default값에 해당하는 소수점 아래 자릿수를 저장
	// streamsize는 long long형을 typedef(새로 별명을 지어줌)한 것
	// streamsize는 std라는 namespace에 정의되어 있음
	streamsize ss = cout.precision();
	
	// 소수점 아래 두자리수까지 설정
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "소수점 둘째자리까지 설정했습니다." << endl;
	cout << 17.25 / 4.1 << endl;		// 결과값 : 4.21
	cout << 4.6 / 94.5 << endl;			// 결과값 : 0.05
	cout << endl;

	// 앞에서 저장한 streamsize형 변수 ss를 가지고 초기화시키기
	// cout.unsetf를 사용하여 다시 초기화시킨다
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::showpoint);
	cout.precision(ss);

	cout << "Default값입니다." << endl;
	cout << 17.25 / 4.1 << endl;		// 결과값 : 4.20732 (초기값과 동일)
	cout << 4.6 / 94.5 << endl;			// 결과값 : 0.0486772 (초기값과 동일)
}