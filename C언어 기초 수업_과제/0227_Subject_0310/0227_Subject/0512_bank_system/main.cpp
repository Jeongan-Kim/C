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

	cout << "######### ���� ���࿡ ���� �� ȯ���մϴ�. ##########" << endl << endl;

	system("pause");
}

void ReSet()
{
	system("cls");

	cout << "���� �� ���Ͻô� ���񽺸� �����ϼ���." << endl
		<< "1. ���� ����" << endl << "2. �Ա�" << endl << "3. ���" << endl << "4. ���� ���� ��ü ���" << endl << " => ";
	int mySel;
	cin >> mySel;

	system("cls");


	switch (mySel)
	{
	case 1:
	{
		cout << "<< ���� ���� >>" << endl;

		Bank().MakeAccount();
		break;
	}
	case 2:
	{
		cout << "<< �Ա� >>" << endl;
		Bank().Deposit();
		break;
	}
	case 3:
	{
		cout << "<< ��� >>" << endl;
		Bank().Withdraw();
		break;
	}
	case 4:
	{
		cout << "<< ���� ���� ��ü ��� >>" << endl;
		Bank().Print();
		break;
	}
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
}

bool Update()
{
	cout << endl << "�̾ �ٸ� ���񽺸� �̿��Ͻ÷��� 1���� ���� �ּ���.\n�����Ͻ÷��� �ƹ� Ű�� ��������." << endl;
	int mySel2;
	cin >> mySel2;
	if (mySel2 == 1)
		return true;
	else
		return false;
}

