// 2-43 �ǽ����� - �����ð� solution
#include <iostream>
using namespace std;

int main()
{
	int pWaiting[7] = { 22, 21, 24, 20, 18, 25, 23 };
	int nMax = pWaiting[0];	// ù��° ���� �ִ�� ���´�.
	int nPosMax = 0;		// ù��° ���� �ִ�ϱ� �ִ��� ��ġ�� 0(�迭�� 1�� �ƴ� 0���� ����)

	for (int i = 1; i < 7; i++)	// for ���� �̿��ؼ� �ִ밪�� ��ġ�� ã�´�.
	{
		if (pWaiting[i] == 21)	// 21�� ������ ���������� ¦�� �ִ밪�� ã�´�.
		{
			break;	// 21�� ������ for���� ����������.
		}
		if (pWaiting[i] % 2 == 1)	// ¦�� �߿����� �ִ밪�� ã�´�.
		{
			continue;	// Ȧ���� continue�� �ǳʶ�
		}
		if (pWaiting[i] > nMax)	// ���� ���� �ִ밪���� �� ū ���̶��
		{
			nMax = pWaiting[i];	// �� ���� �ִ밪�� �����Ѵ�.
			nPosMax = i;		// �ִ��� ��ġ(i)�� �ٲ۴�.
		}
	}

	cout << "nMax : " << nMax << endl;	// �ִ밪 ���
	cout << "nPosMax : " << nPosMax << endl;	// �ִ밪�� ��ġ ���
	cout << endl;

	return 0;
}