// HW2_Data_Analysis.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// coding by 남윤원, 20150413

#include "pch.h"
#include "CInstagram.h"
#include <fstream>		// 텍스트 파일을 읽어들이기 위해 사용
#include <iomanip>		// 데이터를 출력할 때 정렬하기 위해 사용
#include <vector>		// 벡터를 사용하기 위해 사용

void ReadInsta(string filename, CInstagram &Instagram);

ostream & operator << (ostream &outputstream, const CInstagram &Instagram);

// 전역변수로 positive_word, negative_word에 대한 string 배열 선언
string positive_word[10] = {"응원", "위로", "멋진", "최고", "팬", "사랑", "화이팅", "행복", "골", "축하"};
string negative_word[10] = {"쓰레기", "시발", "씨발", "주작", "조롱", "욕", "병신", "똥", "꺼져", "범죄"};

int main()
{
	CInstagram Instagram1;
	string filename1 = "instagram-1.txt";
	ReadInsta(filename1, Instagram1);

	// main 함수에서 실행후 해당객체를 출력한다.
	// 물론 operator << 를 overloading해서 출력한다.
	// cascading 가능
	cout << Instagram1 << endl << endl;

	/*
	4.	main 함수에서 pInstagramObj 를 vector로 만들고
	2번 문제를 이용해서 3개의 다른 파일로 3객의 객체를 채워넣는다.
	매개변수가 있는 CInstagram 생성자에서는 
	m_nPosTotal(int), m_nNegTotal(int) 을 매개변수 값을 이용해서 갱신해야 한다.
	즉 더해줘야 한다. 동작이 잘되고 있음을 화면에 출력한다. [1점]
	*/
	   
	CInstagram Instagram2;
	string filename2 = "Instagram-2.txt";
	ReadInsta(filename2, Instagram2);

	//main 함수에서 실행후 해당객체를 출력한다.
	//물론 operator << 를 overloading해서 출력한다.
	// cascading 가능
	cout << Instagram2 << endl << endl;


	CInstagram Instagram3;
	string filename3 = "Instagram-3.txt";
	ReadInsta(filename3, Instagram3);

	//main 함수에서 실행후 해당객체를 출력한다.
	//물론 operator << 를 overloading해서 출력한다.
	// cascading 가능
	cout << Instagram3 << endl << endl;

	vector<CInstagram> pInstagramObj;
	pInstagramObj.push_back(Instagram1);
	pInstagramObj.push_back(Instagram2);
	pInstagramObj.push_back(Instagram3);

	/*
	// cascading이 가능한지 살펴보기
	cout << "지금부터는 cascading이 가능한지 살펴봅시다!" << endl;
	cout << pInstagramObj[0] << endl << pInstagramObj[1] << endl << pInstagramObj[2] << endl;
	*/
}

/*
2.	ReadInsta 라는 함수를 구현하고 main에서 실행한다.
이 함수는 파일이름과 CInstagram 객체 를 매개변수로 한다. 
구체적인 내용은 파일을 읽어서 게시자의 id 를 찾고 첫번째 hashtag을 찾고[1점],
나머지 댓글한 사람들의 내용에서 positive와 negative의 단어의 개수를 찾는다.[2점] 
이렇게 찾은 것은 당연하게 CInstagram 객체에 넣어야겠죠.
*/
void ReadInsta(string filename, CInstagram &Instagram)
{
	ifstream read;
	read.open(filename);
	string input;
	string data = "";
	if (read.good()) // 파일을 잘 읽었다면 실행
	{
		read >> input;			 // 먼저 게시자의 id를 찾자.
		Instagram.SetId(input);  // 게시자의 id를 SetId 멤버함수를 이용해서 CInstagram 객체에 삽입
		while (input.find_first_of("#", 0) != 0) // 첫번째 hashtag를 찾자
		{
			read >> input;
		}
		
		// cout << "첫번째 id: " << Instagram.GetId() << endl;
		// 만약 "#장현수#축구선수" 와 같은 부분을 읽었을 경우, 해시태그를 분리해야 한다.
		if (input.find_first_of("#", 1) <= input.size()) // 띄어쓰기없이 태그가 있을 경우
		{
			for (int i = 1; i < input.find("#", 1); i++) // 앞에 1부터 설정하여 첫 해시태그를 제외하고 입력을 받자
				data = data + input[i];	 // string의 경우 + 연산자 오버로딩이 되어 있다.
		}
		else // 만약 #COYS #X17 처럼 해시태그가 구분되어 있으면, 그냥 읽으면 된다.
		{
			for(int i = 1; i < input.size(); i++) // 앞에 1부터 설정하여 첫 해시태그를 제외하고 입력을 받자
				data = data + input[i]; 
		}

		Instagram.SetHashtag(data);

		//cout << "첫번째 HashTag: " << Instagram.GetId() << endl;

		read >> input; // 일단 임시로 # 지정


		// 댓글을 단 사람들의 내용에서 positive와 negative의 단어의 개수를 찾는다.[2점] 
		// !read.eof()로 파일 끝일 때까지 반복
		while(1) {
			read >> input;			 // 아이디 부분은 먼저 read하여 제외함
			read.ignore(1);			 // 띄어쓰기 부분이나 '\n' 부분 제외
			if (read.eof()) break;
			getline(read, input);	 // 댓글 전체를 getline함수로 read함
			// cout << input << endl;
			for (int i = 0; i < 10; i++)
			{
				if (input.find(positive_word[i]) != string::npos)
				{
					Instagram.SetPositive(Instagram.GetPositive() + 1);
					Instagram.SetPosTotal(Instagram.GetPosTotal() + 1);
				}


				if (input.find(negative_word[i]) != string::npos)
				{
					Instagram.SetNegative(Instagram.GetNegative() + 1);
					Instagram.SetNegTotal(Instagram.GetNegTotal() + 1);
				}
			}
			/*
			// 확인용 코드
			cout << "긍정어는 " << Instagram.GetPositive() << "번 등장!" << endl;
			cout << "부정어는 " << Instagram.GetNegative() << "번 등장!" << endl;
			*/
		}
		/*
		cout << "긍정어는 " << Instagram.GetPositive() << "번 등장!" << endl;
		cout << "부정어는 " << Instagram.GetNegative() << "번 등장!" << endl;

		cout << "긍정어 총 개수는 " << Instagram.GetPosTotal() << "번 등장!" << endl;
		cout << "부정어 총 개수는 " << Instagram.GetNegTotal() << "번 등장!" << endl;
		*/
	}
}

/*
3.	main 함수에서 실행후 해당객체를 출력한다. 
물론 operator << 를 overloading해서 출력한다. 
단 cascading은 가능해야 한다. [1점]
*/

ostream & operator << (ostream &outputstream, const CInstagram &Instagram)
{
	outputstream << "게시자의 아이디: " << Instagram.GetId() << endl;
	outputstream << "첫 해시태그: " << Instagram.GetHashtag() << endl;
	outputstream << "긍정어는 " << Instagram.GetPositive() << "번 등장!" << endl;
	outputstream << "부정어는 " << Instagram.GetNegative() << "번 등장!" << endl;

	outputstream << "긍정어 총 개수(누적)는 " << Instagram.GetPosTotal() << "번 등장!" << endl;
	outputstream << "부정어 총 개수(누적)는 " << Instagram.GetNegTotal() << "번 등장!" << endl;

	// 주소값(ostream) return으로 cascading이 가능하게 한다.
	// 즉, cout << 변수 << 변수 << endl; 와 같은 꼴이 가능하게 한다.
	return outputstream;
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
