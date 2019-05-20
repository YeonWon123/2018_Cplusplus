// CH14.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "employee.h"
#include "salariedemployee.h"
#include "hourlyemployee.h"
using namespace SavitchEmployees;

int main()
{
	HourlyEmployee HourEmployee;
	SalariedEmployee SalaryEmployee;

	HourEmployee.printCheck();
	SalaryEmployee.printCheck();

	HourEmployee.Employee::printCheck(); // 자식 클래스에서 부모 클래스 함수를 부를 수 있다.

	return 0;
}

