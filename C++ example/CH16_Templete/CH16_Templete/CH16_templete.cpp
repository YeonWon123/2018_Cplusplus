#include "pair.h"
#include "pairchild.h"

int main()
{
	Pair<int> score(5, 7);
	Pair<char> seats('a','b');

	cout << "Pair 실행!!" << endl;

	cout << score.getFirst() << " " << score.getSecond() << endl;

	cout << seats.getFirst() << " " << seats.getSecond() << endl;

	score.setFirst(3);		score.setSecond(0);
	seats.setFirst('c');	seats.setSecond('d');

	cout << "set 함수 사용 후 변화" << endl;

	cout << score.getFirst() << " " << score.getSecond() << endl;
	cout << seats.getFirst() << " " << seats.getSecond() << endl;

	cout << "PairChild 실행!!" << endl;

	PairChild<int> scorechild(5, 6, 7.5);
	PairChild<char> seatschild('A', 'B', 5.7);

	cout << scorechild.getFirst() << " " << scorechild.getSecond() << " " << scorechild.getThird() << endl;
	cout << seatschild.getFirst() << " " << seatschild.getSecond() << " " << seatschild.getThird() << endl;

	scorechild.setFirst(300);		scorechild.setSecond(400);			scorechild.setThird(0.35);
	seatschild.setFirst('x');		seatschild.setSecond('y');			seatschild.setThird(1.34);

	cout << "set 함수 사용 후 변화" << endl;

	cout << scorechild.getFirst() << " " << scorechild.getSecond() << " " << scorechild.getThird() << endl;
	cout << seatschild.getFirst() << " " << seatschild.getSecond() << " " << seatschild.getThird() << endl;

	return 0;
}