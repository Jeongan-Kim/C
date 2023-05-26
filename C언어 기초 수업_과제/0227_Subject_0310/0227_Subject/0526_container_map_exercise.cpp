#include <iostream>
#include <map>
#include <Windows.h>
#include <string>

/*
	내가 입력할 단어 개수와 출력해볼 수 m, n 만들기
	단어 개수 m에 맞게 단어를 입력.
	정답 개수인 n에 따라 정답을 맞힐 것.
	단어를 입력하면 숫자가 출력
	숫자를 입력하면 단어가 출력
	//stoi => string to int (문자열을 정수로 바꿀 때 사용)

	//m = 3
	//n = 2
	1. apple
	2. grapes
	3. peach

	1 -> apple
	peach -> 3
*/

using namespace std;

void Start(); //시작 화면
void Reset(); //세팅 화면
bool Update();//더 진행할지 체크
bool Isdigit(string& string) //문자열에 알파벳이 있는지 확인하는 함수
{
	for (const auto& ele : string)
	{
		if (!isdigit(ele))
			return false;
	}
	return true;
}

int num_words;
int num_questions;

multimap<int, string> Words;

int main()
{
	Start();
	Reset();
	
	while (Update())
	{
		Reset();
	}

	return 0;
}

void Start()
{
	system("title 단어 외우기 게임");
	system("mode con cols=60 lines=30"); //콘솔창의 크기 조정

	{
		//커서 깜빡임을 없애주는 코드
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "######## 단어 외우기 게임 ########" << endl;

	cout << "1. 입력할 단어의 수와 문제 풀 횟수를 정하세요." << endl;
	cout << "2. 입력한 수만큼 단어를 입력하세요." << endl;
	cout << "3. 문제 풀 횟수만큼 단어 또는 번호를 입력하여 확인하세요." << endl;

	system("pause"); //키가 입력될때까지 일시 정지되는 코드.
	system("cls");
}

void Reset()
{
	system("cls");

	cout << "1. 입력할 단어의 수와 문제 풀 횟수를 정하세요." << endl;

	cout << "입력할 단어의 수 : ";
	cin >> num_words;

	cout << endl << "문제 풀 횟수 : ";
	cin >> num_questions;
	cout << endl;

	cout << "2. 단어를 입력하세요." << endl;
	for (int i = 0; i < num_words; i++)
	{
		string temp1;
		cout << i + 1 << "번째 단어를 입력하세요." << endl;
		cin >> temp1;
		//multimap[i] = {temp};
		Words.insert(make_pair(i + 1, temp1));
	}
	
	system("cls");

	cout << "3. 확인할 단어 또는 번호를 입력하세요." << endl;

	for (int i = 0; i < num_questions; i++)
	{
		string temp2;
		cout << i + 1 << ") " << endl << "-> ";
		cin >> temp2;

		if (Isdigit(temp2)) //숫자가 입력된 경우, 문자열을 정수화 하는 stoi 함수를 쓸 수 있으므로 맞는 key값 검색
		{
			int temp3 = stoi(temp2);
			if (temp3 <= num_words)
				cout << Words.find(temp3)->second << endl;
			else
				cout << "입력된 번호가 존재하지 않습니다." << endl;
		}
		else //문자가 하나라도 입력된 경우, 같은 값이 있는지 map을 순회하여 확인.
		{
			int check = 0;
			for (const auto& ele : Words)
			{
				if (ele.second == temp2)
					cout << ele.first << endl;
				else
					check++;
			}
			if(check == num_words)
				cout << "입력된 단어가 존재하지 않습니다." << endl;
		}

		cout << endl;
	}
	
	
}

bool Update()
{
	cout << endl << "더 진행하시겠습니까? [1. 네   2. 아니오] => ";
	int answer;
	cin >> answer;
	switch (answer)
	{
	case 1:
		return true;
	default:
		return false; //2가 아닌 다른 수를 입력해도 종료되게끔.
	}
}
