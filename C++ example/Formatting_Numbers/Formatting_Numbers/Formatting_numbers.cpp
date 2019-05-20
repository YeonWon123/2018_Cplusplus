#include <iostream>
using namespace std;

int main()
{
	// �Ҽ��� �Ʒ� �ڸ����� �ǵ帮�� ����.
	cout << "���ʼ����Դϴ�." << endl;
	cout << 17.25 / 4.1 << endl;		// ����� : 4.20732
	cout << 4.6 / 94.5 << endl;			// ����� : 0.0486772
	cout << endl;

	// default���� �ش��ϴ� �Ҽ��� �Ʒ� �ڸ����� ����
	// streamsize�� long long���� typedef(���� ������ ������)�� ��
	// streamsize�� std��� namespace�� ���ǵǾ� ����
	streamsize ss = cout.precision();
	
	// �Ҽ��� �Ʒ� ���ڸ������� ����
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "�Ҽ��� ��°�ڸ����� �����߽��ϴ�." << endl;
	cout << 17.25 / 4.1 << endl;		// ����� : 4.21
	cout << 4.6 / 94.5 << endl;			// ����� : 0.05
	cout << endl;

	// �տ��� ������ streamsize�� ���� ss�� ������ �ʱ�ȭ��Ű��
	// cout.unsetf�� ����Ͽ� �ٽ� �ʱ�ȭ��Ų��
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::showpoint);
	cout.precision(ss);

	cout << "Default���Դϴ�." << endl;
	cout << 17.25 / 4.1 << endl;		// ����� : 4.20732 (�ʱⰪ�� ����)
	cout << 4.6 / 94.5 << endl;			// ����� : 0.0486772 (�ʱⰪ�� ����)
}