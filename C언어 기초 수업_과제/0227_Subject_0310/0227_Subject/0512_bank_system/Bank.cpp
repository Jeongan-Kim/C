#include "stdafx.h"
#include "Bank.h"

void Bank::MakeAccount()
{
	string name; //�̸�
	int age; //����
	double money; //����
	int account[4]; //���¹�ȣ

	cout << "���¸� �����Ͻ� ���� ������ �Է��� �ּ���." << endl;
	cin >> name;

	cout << endl;

	cout << name << "���� ���̸� �Է��� �ּ���." << endl;
	cin >> age;

	cout << endl;

	cout << "���� ���� �� �����ϰ����� �ݾ��� �Է��� �ּ���.(������ 0������ �Է��� �ּ���.)" << endl;
	cin >> money;

	cout << endl;

	cout << name << "���� ���� ��ȣ�� ";
	for (int i = 0; i < 4; i++)
	{
		account[i] = Math::Random(0, 9);
		cout << account[i];
	}
	cout << " �Դϴ�." << endl;
	Customer temp(name, age, money, account); //�� �ӽ� ��ü

	customers.push_back(temp); //list�� �� �ӽ� ��ü ����
}

void Bank::Deposit()
{
	cout << "�Ա��Ͻ� ���� ��ȣ�� ���ʴ�� �Է��� �ּ���." << endl;
	int check1 = 0;
	int temp_account[4];

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "��° ���ڸ� �Է��ϼ���. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			cout << ele.name << "���� ���¿� �Ա��Ͻ� �ݾ��� �Է��� �ּ���." << endl;
			cout << "���� �ܾ� : " << ele.money << endl;
			int temp;
			cin >> temp;
			ele.money += temp;
			cout << ele.name << "���� ���¿� ���� ���� �ܾ��� " << ele.money << "�Դϴ�." << endl << endl;

			check1 = 0;
			return;
		}
		else
			check1 = 1;
	}

	if (check1 == 1)
		AccountCheck();
}

void Bank::Withdraw()
{
	cout << "����Ͻ� ���� ��ȣ�� �Է��� �ּ���." << endl;

	int check1 = 0;
	int temp_account[4];

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "��° ���ڸ� �Է��ϼ���. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			while (1)
			{
				cout << ele.name << "���� ���¿� ����Ͻ� �ݾ��� �Է��� �ּ���." << endl;
				cout << "���� �ܾ� : " << ele.money << endl;
				int temp;
				cin >> temp;
				if (temp > ele.money)
				{
					cout << "�ܾ׺��� ū �ݾ��� ����Ͻ� �� �����ϴ�." << endl;
					break;
				}

				ele.money -= temp;
				cout << ele.name << "���� ���¿� ���� ���� �ܾ��� " << ele.money << "�Դϴ�." << endl;

				check1 = 0;
				return;
			}
		}
		else
			check1 = 1;
	}

	if (check1 == 1)
		AccountCheck();
}

void Bank::Print()
{
	int check1 = 0;
	int temp_account[4];

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "��° ���ڸ� �Է��ϼ���. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			cout << "�̸� : " << ele.name << endl;
			cout << "���� : " << ele.age << endl;
			cout << "���� ��ȣ : " << ele.account[0] << ele.account[1] << ele.account[2] << ele.account[3] << endl;
			cout << "���� �ݾ� : " << ele.money << endl;

			check1 = 0;
			return;
		}
		else
			check1 = 1;
	}

	if (check1 == 1)
		AccountCheck();
}

void AccountCheck()
{
	cout << "��ġ�ϴ� ���°� �����ϴ�. �ٽ� �Է��Ͻðڽ��ϱ�?\n1. �ٽ� �Է��ϱ�\n2. ó������ ���ư���\n3. �׸��ϱ�" << endl;
	int ans;
	cin >> ans;
	switch (ans)
	{
	case 1:
		Bank().Deposit();
		break;
	case 2:
		return;
	case 3:
		exit(0);
	}
}
