// HW1-sol-2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CROS.h"

int main()
{
	CROS Image_Authentification("HW1_1.txt");

	Image_Authentification.ReadEvalFileToArray();
	Image_Authentification.ComputeRecallAndPrecision();
	Image_Authentification.ComputeAvgOfRecallAndPrecision();

    return 0;
}