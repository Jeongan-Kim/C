#include <iostream>
#include <map>
#include <Windows.h>
#include <string>

/*
	���� �Է��� �ܾ� ������ ����غ� �� m, n �����
	�ܾ� ���� m�� �°� �ܾ �Է�.
	���� ������ n�� ���� ������ ���� ��.
	�ܾ �Է��ϸ� ���ڰ� ���
	���ڸ� �Է��ϸ� �ܾ ���
	//stoi => string to int (���ڿ��� ������ �ٲ� �� ���)

	//m = 3
	//n = 2
	1. apple
	2. grapes
	3. peach

	1 -> apple
	peach -> 3
*/

using namespace std;

void Start(); //���� ȭ��
void Reset(); //���� ȭ��
bool Update();//�� �������� üũ
bool Isdigit(string& string) //���ڿ��� ���ĺ��� �ִ��� Ȯ���ϴ� �Լ�
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
	system("title �ܾ� �ܿ�� ����");
	system("mode con cols=60 lines=30"); //�ܼ�â�� ũ�� ����

	{
		//Ŀ�� �������� �����ִ� �ڵ�
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = 0;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
	}

	cout << "######## �ܾ� �ܿ�� ���� ########" << endl;

	cout << "1. �Է��� �ܾ��� ���� ���� Ǯ Ƚ���� ���ϼ���." << endl;
	cout << "2. �Է��� ����ŭ �ܾ �Է��ϼ���." << endl;
	cout << "3. ���� Ǯ Ƚ����ŭ �ܾ� �Ǵ� ��ȣ�� �Է��Ͽ� Ȯ���ϼ���." << endl;

	system("pause"); //Ű�� �Էµɶ����� �Ͻ� �����Ǵ� �ڵ�.
	system("cls");
}

void Reset()
{
	system("cls");

	cout << "1. �Է��� �ܾ��� ���� ���� Ǯ Ƚ���� ���ϼ���." << endl;

	cout << "�Է��� �ܾ��� �� : ";
	cin >> num_words;

	cout << endl << "���� Ǯ Ƚ�� : ";
	cin >> num_questions;
	cout << endl;

	cout << "2. �ܾ �Է��ϼ���." << endl;
	for (int i = 0; i < num_words; i++)
	{
		string temp1;
		cout << i + 1 << "��° �ܾ �Է��ϼ���." << endl;
		cin >> temp1;
		//multimap[i] = {temp};
		Words.insert(make_pair(i + 1, temp1));
	}
	
	system("cls");

	cout << "3. Ȯ���� �ܾ� �Ǵ� ��ȣ�� �Է��ϼ���." << endl;

	for (int i = 0; i < num_questions; i++)
	{
		string temp2;
		cout << i + 1 << ") " << endl << "-> ";
		cin >> temp2;

		if (Isdigit(temp2)) //���ڰ� �Էµ� ���, ���ڿ��� ����ȭ �ϴ� stoi �Լ��� �� �� �����Ƿ� �´� key�� �˻�
		{
			int temp3 = stoi(temp2);
			if (temp3 <= num_words)
				cout << Words.find(temp3)->second << endl;
			else
				cout << "�Էµ� ��ȣ�� �������� �ʽ��ϴ�." << endl;
		}
		else //���ڰ� �ϳ��� �Էµ� ���, ���� ���� �ִ��� map�� ��ȸ�Ͽ� Ȯ��.
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
				cout << "�Էµ� �ܾ �������� �ʽ��ϴ�." << endl;
		}

		cout << endl;
	}
	
	
}

bool Update()
{
	cout << endl << "�� �����Ͻðڽ��ϱ�? [1. ��   2. �ƴϿ�] => ";
	int answer;
	cin >> answer;
	switch (answer)
	{
	case 1:
		return true;
	default:
		return false; //2�� �ƴ� �ٸ� ���� �Է��ص� ����ǰԲ�.
	}
}
