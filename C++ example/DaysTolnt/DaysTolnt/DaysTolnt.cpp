// 2-20 �ǽ�����
// 2-27 �ǽ�����
#include <iostream>
#include <string>	// string ������ �����ϱ� ���� �ʿ�
using namespace std;

int main()
{
	string strDays;	// string ���� ����
	int nDays;
	cout << "������ �Է��ϼ��� : ";
	cin >> strDays;	// ����� �Է¹޾� string ���� strDays�� ����

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
		cout << "������ �ƴմϴ�!" << endl;
		return 0;
	}

	cout << "������ " << nDays << "��° ����" << endl;

	switch (nDays)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			cout << "���߿� ������" << endl;
			break;
		case 5:
		case 6:
		case 7:
			cout << "�ָ��� ��̰�" << endl;
			break;
		default:
			cout << "�̰� ������ �ƴ��ݾƿ�" << endl;
	}

	return 0;
}