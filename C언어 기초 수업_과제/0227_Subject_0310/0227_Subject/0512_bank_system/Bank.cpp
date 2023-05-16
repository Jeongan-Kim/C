#include "stdafx.h"
#include "Bank.h"

void Bank::MakeAccount()
{
	string name; //이름
	int age; //나이
	double money; //예금
	int account[4]; //계좌번호

	cout << "계좌를 개설하실 분의 성함을 입력해 주세요." << endl;
	cin >> name;

	cout << endl;

	cout << name << "님의 나이를 입력해 주세요." << endl;
	cin >> age;

	cout << endl;

	cout << "계좌 개설 시 예금하고자할 금액을 입력해 주세요.(없으면 0원으로 입력해 주세요.)" << endl;
	cin >> money;

	cout << endl;

	cout << name << "님의 계좌 번호는 ";
	for (int i = 0; i < 4; i++)
	{
		account[i] = Math::Random(0, 9);
		cout << account[i];
	}
	cout << " 입니다." << endl;
	Customer temp(name, age, money, account); //고객 임시 객체

	customers.push_back(temp); //list에 고객 임시 객체 저장
}

void Bank::Deposit()
{
	cout << "입금하실 계좌 번호를 차례대로 입력해 주세요." << endl;
	int check1 = 0;
	int temp_account[4];

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "번째 숫자를 입력하세요. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			cout << ele.name << "님의 계좌에 입금하실 금액을 입력해 주세요." << endl;
			cout << "현재 잔액 : " << ele.money << endl;
			int temp;
			cin >> temp;
			ele.money += temp;
			cout << ele.name << "님의 계좌에 현재 예금 잔액은 " << ele.money << "입니다." << endl << endl;

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
	cout << "출금하실 계좌 번호를 입력해 주세요." << endl;

	int check1 = 0;
	int temp_account[4];

	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "번째 숫자를 입력하세요. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			while (1)
			{
				cout << ele.name << "님의 계좌에 출금하실 금액을 입력해 주세요." << endl;
				cout << "현재 잔액 : " << ele.money << endl;
				int temp;
				cin >> temp;
				if (temp > ele.money)
				{
					cout << "잔액보다 큰 금액을 출금하실 수 없습니다." << endl;
					break;
				}

				ele.money -= temp;
				cout << ele.name << "님의 계좌에 현재 예금 잔액은 " << ele.money << "입니다." << endl;

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
		cout << i + 1 << "번째 숫자를 입력하세요. => ";
		cin >> temp_account[i];
		cout << endl;
	}

	for (auto& ele : customers)
	{
		if (CheckAccount(ele.account, temp_account))
		{
			cout << "이름 : " << ele.name << endl;
			cout << "나이 : " << ele.age << endl;
			cout << "계좌 번호 : " << ele.account[0] << ele.account[1] << ele.account[2] << ele.account[3] << endl;
			cout << "예금 금액 : " << ele.money << endl;

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
	cout << "일치하는 계좌가 없습니다. 다시 입력하시겠습니까?\n1. 다시 입력하기\n2. 처음으로 돌아가기\n3. 그만하기" << endl;
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
