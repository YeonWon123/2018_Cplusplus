#include <iostream>
using namespace std;

int main()
{
	int speed;
	cout << "�ӵ��� �Է��ϼ���: ";
	cin >> speed;

	if (speed > 55)
		if (speed > 80)
			cout << "You're really speeding!\n";
	else
			cout << "You're speeding.\n";	// speed�� 60�� ������, you're speeding�� ��µȴ�.
											// �̴� �ٷ� ���� else�� tabŰ�� ������ space bar�� ������ �������.
											// �̰��� python�� �ٸ� ���̸�	
											// ���� speed�� 55 ������ ��쿡 you're speeding�� �߰� �ϰ� ������
											// �߰�ȣ�� ó���� �� �� �ʿ䰡 �ִ�.
										
	return 0;
}