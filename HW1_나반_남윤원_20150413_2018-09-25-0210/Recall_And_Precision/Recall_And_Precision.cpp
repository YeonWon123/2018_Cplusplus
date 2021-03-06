// Recall_And_Precision.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 이 code는 영상의 개수가 n개일 때와 방법의 개수가 m개가 되었을 때에도 수행될 수 있습니다.

#include "pch.h"
#include <iostream>
#include <fstream>		// 텍스트 파일을 읽어들이기 위해 사용
#include <string>
#include <iomanip>		// 데이터를 출력할 때 정렬하기 위해 사용
using namespace std;

// 영상의 이름을 담는 string 배열과 수치 데이터를 담는 int 배열을 하나의 함수에서 동시에 반환할 수 없으므로
// 두 배열을 하나의 구조체 안에 담아 반환한다. (call-by-pointer 사용)
typedef struct Name_and_Data
{
	string* name;
	int* data;
} arrays;

// 마찬가지로, recall 값을 담는 double배열과 precision 값을 담는 double배열을 하나의 함수에서 동시에 반환할 수 없으므로
// 두 배열을 하나의 구조체 안에 담아 반환한다. (call-by-pointer 사용)
typedef struct recall_and_precision
{
	double* recall;
	double* precision;
} RP_double;

void input_array_and_print(int n, int m, arrays& arr, ifstream& read);			// 1. n개의 영상의 데이터를 array에 읽어들이고 화면에 출력
void recall_and_precision_print(int n, int m, arrays arr, RP_double& rp);		// 2. 방법들에 대해서 recall값과 precision 값을 출력
void average_print(int n, int m, arrays arr, RP_double rp);						// 3. recall과 precision의 평균값 출력
void input_and_malloc(int &n, int &m, arrays& arr, ifstream& read);				// 4. 영상의 개수가 n개가 되고 방법의 개수가 m개가 되었을 때도
																				//    수행할 수 있게 함(동적 메모리 이용)


// main함수, 각 문제는 모두 함수로 구성해야 한다는 조건에 따라, main함수에서는 변수 생성, 파일 오픈 명령, 함수 호출 명령만 이루어짐.
int main()
{
	int n = 0;									// int형 변수 n을 선언 후 0으로 초기화
	int m = 0;									// int형 변수 m을 선언 후 0으로 초기화
	
	RP_double rp;								// RP_double형 구조체 변수 rp를 선언
	arrays arr;									// arrays형 구조체 변수 arr를 선언
	ifstream read;								// 파일을 읽을 수 있게 해주는 ifstream형 변수 read를 선언
	read.open("Input_data_File.txt");			// n이 15개이고 n이 3개인 파일

	input_and_malloc(n, m, arr, read);			// 4번 문제
	input_array_and_print(n, m, arr, read);		// 1번 문제
	recall_and_precision_print(n, m, arr, rp);	// 2번 문제
	average_print(n, m, arr, rp);				// 3번 문제


	read.open("Input_data_File_2.txt");			// n이 17개이고 m이 3개인 파일

	input_and_malloc(n, m, arr, read);			// 4번 문제
	input_array_and_print(n, m, arr, read);		// 1번 문제
	recall_and_precision_print(n, m, arr, rp);	// 2번 문제
	average_print(n, m, arr, rp);				// 3번 문제

	return 0;
}

// 1. n개의 영상의 데이터를 array에 읽어들이고 화면에 출력
void input_array_and_print(int n, int m, arrays& arr, ifstream& read)	// n과 m은 call-by-value(입력값, 바뀔 필요 없음), arr과 read는 call-by-reference
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "              1. n개의 영상의 데이터를 array에 읽어들이고 화면에 출력" << endl;
	cout << "----------------------------------------------------------------------------------" << endl << endl;

	string line;	// 쉼표(,)와 같은 토큰을 데이터 파일에서 추출하여 버리기 위해 사용

	if (read.good())	// 파일을 잘 읽었다면 실행
	{
		cout.setf(ios::left);  // 왼쪽 정렬

		cout << setw(25) << "     영상 이름" << setw(10) << "nFO" << setw(10) << "nFR" << "nFC" << endl << endl;
		int j = -1;
		for (int i = 0; i < 3*n*m; i = i + 3)	// i가 0부터 영상갯수*방법갯수*3(nFO, nFR, nFC)까지 반복, 단 i는 i+3만큼 증가
		{
			if (i % (3 * m) == 0)	   // 한개의 영상에서 모든 방법에 대해 처리한 결과를 기록하였다면 (또는 i가 0인 경우도 포함)
			{
				j++;				   // 다음 영상으로 넘어감 (j의 초기값이 -1이므로 j는 실질적으로 0이 되어 시작)
				read >> arr.name[j];   // 다음 영상의 이름을 arr.name 배열에 저장
			}
			else
			{
				read >> line;          // 그렇지 않다면 현재 영상의 이름은 이미 arr.name 배열에 저장되어 있으므로 임시변수 line에 버림
			}
			
			// n개의 영상의 data를 arr.data 배열에 읽어들임
			read >> arr.data[i] >> line >> arr.data[i + 1] >> line >> arr.data[i + 2] >> line;

			// n개의 영상의 data를 arr.data 배열에서 읽어와 화면에 출력 (setw(n): 데이터가 출력된 화면의 폭을 n으로 지정)
			// 한 줄에는, 하나의 방법을 이용해서 처리한 영상의 이름과 nFO, nFR, nFC를 출력
			cout << setw(25) << arr.name[j] << setw(10) << arr.data[i] << setw(10) << arr.data[i + 1] << arr.data[i + 2] << endl;
		}

		cout << endl;
		read.close();	// 파일 읽기를 마침
	}
	else // 만약 파일을 읽지 못한 경우 
	{
		cout << "파일을 불러오지 못하였습니다!" << endl;
	}
}

// 2. 방법들에 대해서 recall값과 precision 값을 출력
void recall_and_precision_print(int n, int m, arrays arr, RP_double& rp)	// RP_double형 변수에 대해서만 call-by-reference 적용(입출력이 동시에 되어야 함)
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "              2. 다양한 방법들에 대해서 recall값과 precision 값을 출력" << endl;
	cout << "----------------------------------------------------------------------------------" << endl << endl;

	rp.recall = new double[n*m];		// rp.recall 배열을 동적할당
	rp.precision = new double[n*m];		// rp.precision 배열을 동적할당

	// recall값과 precision 값을 계산 후 보관을 위해 배열에 입력
	int j = 0;
	for (int i = 0; j < n*m; i=i+3)
	{
		rp.recall[j] = (double)arr.data[i + 2] / arr.data[i];			// nFO, nFR, nFC 순으로 모두 하나의 배열 안에 묶여 있으므로, recall = nFC/nFO 식은 왼편과 같이 표현됨
		rp.precision[j] = (double)arr.data[i + 2] / arr.data[i + 1];	// 마찬가지로 precision = nFC/nFR은 왼편과 같이 표현됨
		j++;															// 다음 줄 데이터로 이동함
	}

	cout.setf(ios::left);	// 왼쪽 정렬

	// 이중 for문을 사용하여, 각 방법에 대해서 recall값과 precision값을 출력
	for (j = 0; j < m; j++)	// 방법의 개수만큼 반복
	{
		cout << "------------<  " << j+1 << "번째 방법의 recall 값과 precision 값  >---------------" << endl << endl;
		cout << setw(30) << "     영상이름" << setw(20) << " Recall" << "Precision" << endl << endl;

		for (int i = 0+j; i < m*n; i = i + m)	// 영상의 개수만큼 반복, 단, 모든 수치 데이터가 하나의 배열 안에 있음에 유의하여 
		{										// i의 값을 0+j로 설정하고 방법에 맞는 데이터만 추출하게끔 i의 증가를 i = i + m으로 설정함.
			cout << setw(30) << arr.name[i / m] << setw(20) << rp.recall[i] << rp.precision[i] << endl;
		}

		cout << endl;
	}
}

// 3. recall과 precision의 평균값 출력
void average_print(int n, int m, arrays arr, RP_double rp)	// 네 변수 모두 call-by-value 사용(입력만 받아도 충분하다는 의도)
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "                    3. recall과 precision의 평균값을 출력함" << endl;
	cout << "----------------------------------------------------------------------------------" << endl << endl;

	double recall_avg = 0.0;
	double precision_avg = 0.0;

	// 이중 for문을 사용하여 각 방법에 대해서 recall의 총 합과 precision의 총 합을 더한 뒤, 평균을 구한다.
	for (int j = 0; j < m; j++)
	{
		// 제출한 과제에서 이 부분을 빼먹음, 감점 -0.5점, -0.5점...ㅠ
		recall_avg = 0.0;
		precision_avg = 0.0;

		for (int i = 0+j; i < m*n; i = i + m)
		{
			recall_avg = (double)recall_avg + rp.recall[i];
			precision_avg = (double)precision_avg + rp.precision[i];
			cout << "평균구하기" << i << "번째!!" << endl;
		}

		cout << "합: " << recall_avg << endl;
		cout << "2합: " << precision_avg << endl; // 2합에 문제가 있음

		recall_avg = recall_avg / n;
		precision_avg = precision_avg / n;
		cout << j+1 << " 번째 방법의 recall 평균: " << recall_avg << endl;
		cout << j+1 << " 번째 방법의 precision 평균: " << precision_avg << endl;
		cout << endl;
	}
}

// 4. 영상의 개수가 n개가 되고 방법의 개수가 m개가 되었을 때도 수행할 수 있게 함(동적 메모리 이용)
void input_and_malloc(int &n, int &m, arrays& arr, ifstream& read)	// 네 변수 모두 call-by-reference 사용(입출력을 동시에 하겠다는 의도)
{
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "  4. 영상의 개수가 n개가 되고 방법의 개수가 m개가 되었을 때도 수행할 수 있게 함" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;

	if (read.good())
	{
		read >> n >> m;
		cout << " ● 영상의 개수: " << n << "개, 방법의 개수: " << m << "개" << endl << endl;
	}
	else
	{
		cout << "파일을 불러오지 못하였습니다!" << endl;
	}

 	arr.data = new int[3*n*m];	// 동적 할당
	arr.name = new string[3*n];	// 동적 할당
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
