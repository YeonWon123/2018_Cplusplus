#include <iostream>
#include "CPet.h"
#include "CDog.h"
#include "CCat.h"

using namespace std;


int main(void)
{
	CDog CDog1("´©··ÀÌ", "Ç³»ê°³");
	CDog CDog2;
	CPet *CPet = new CDog("¹é±¸", "Áøµ¾°³");
	CPet->printInfo();
	delete CPet;

	CPet = new CDog(CDog1);
	CPet->printInfo();
	delete CPet;

	CDog2 = CDog1;
	CDog2.setBreed("»ð»ð°³");
	CDog2.printInfo();

	CPet = new CCat("±î±ÃÀÌ", "Æä¸£½Ã¾È");
	CPet->printInfo();
	delete CPet;

	return 1;
}