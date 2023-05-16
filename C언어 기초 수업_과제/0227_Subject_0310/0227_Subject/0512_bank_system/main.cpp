#include "stdafx.h"

void Start();
void ReSet();
bool Update();

int main()
{
	Start();
	ReSet();

	while (Update())
	{
		ReSet();
	}
	return 0;
}

void Start()
{
	system("title ~Jenogan Bank~");
	system("mode con:cols=60 lines=60");

	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "######### 정안 은행에 오신 걸 환영합니다. ##########" << endl << endl;

	system("pause");
}

void ReSet()
{
	system("cls");

	cout << "다음 중 원하시는 서비스를 선택하세요." << endl
		<< "1. 계좌 개설" << endl << "2. 입금" << endl << "3. 출금" << endl << "4. 계좌 정보 전체 출력" << endl << " => ";
	int mySel;
	cin >> mySel;

	system("cls");


	switch (mySel)
	{
	case 1:
	{
		cout << "<< 계좌 개설 >>" << endl;

		Bank().MakeAccount();
		break;
	}
	case 2:
	{
		cout << "<< 입금 >>" << endl;
		Bank().Deposit();
		break;
	}
	case 3:
	{
		cout << "<< 출금 >>" << endl;
		Bank().Withdraw();
		break;
	}
	case 4:
	{
		cout << "<< 계좌 정보 전체 출력 >>" << endl;
		Bank().Print();
		break;
	}
	default:
		cout << "잘못 입력하셨습니다." << endl;
	}
}

bool Update()
{
	cout << endl << "이어서 다른 서비스를 이용하시려면 1번을 눌러 주세요.\n종료하시려면 아무 키나 누르세요." << endl;
	int mySel2;
	cin >> mySel2;
	if (mySel2 == 1)
		return true;
	else
		return false;
}

