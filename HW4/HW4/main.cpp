#include <iostream>
#include "CPet.h"
#include "CDog.h"
#include "CCat.h"

using namespace std;


int main(void)
{
	CDog CDog1("������", "ǳ�갳");
	CDog CDog2;
	CPet *CPet = new CDog("�鱸", "������");
	CPet->printInfo();
	delete CPet;

	CPet = new CDog(CDog1);
	CPet->printInfo();
	delete CPet;

	CDog2 = CDog1;
	CDog2.setBreed("���");
	CDog2.printInfo();

	CPet = new CCat("�����", "�丣�þ�");
	CPet->printInfo();
	delete CPet;

	return 1;
}