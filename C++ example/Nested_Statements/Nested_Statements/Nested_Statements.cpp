#include <iostream>
using namespace std;

int main()
{
	int speed;
	cout << "속도를 입력하세요: ";
	cin >> speed;

	if (speed > 55)
		if (speed > 80)
			cout << "You're really speeding!\n";
	else
			cout << "You're speeding.\n";	// speed가 60을 넣으면, you're speeding이 출력된다.
											// 이는 바로 앞의 else에 tab키를 누르든 space bar를 누르든 상관없다.
											// 이것이 python과 다른 점이며	
											// 만약 speed가 55 이하인 경우에 you're speeding이 뜨게 하고 싶으면
											// 중괄호로 처리를 해 줄 필요가 있다.
										
	return 0;
}