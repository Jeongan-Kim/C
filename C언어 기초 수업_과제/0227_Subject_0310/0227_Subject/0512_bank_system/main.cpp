#include "stdafx.h"

class Customer
{
	string name; //이름
	int age; //나이
	double money; //예금
	int account[4]; //계좌번호

	friend class Bank;

public:
	Customer() : name(""), age(0), money(0)
	{
		for (int i = 0; i < 4; i++)
			account[i] = 0;
	}

	Customer(const Customer& customer) //복사 생성자
		: name(customer.name), age(customer.age), money(customer.money)
	{
		for (int i = 0; i < 4; i++)
			account[i] = customer.account[i];
	}

	Customer& operator = (const Customer& data) //복사 대입 연산자
	{
		name = data.name;
		age = data.age;
		money = data.money;
		for (int i = 0; i < 4; i++)
			account[i] = data.account[i];
		return *this;
	}
};

list<Customer> customers;

class Bank
{
	friend class Customer;
public:
	void SetInfo(class Customer* customer)
	{
		cout << "계좌를 개설하실 분의 성함을 입력해 주세요." << endl;
		cin >> customer->name;

		cout << endl;

		cout << customer->name << "님의 나이를 입력해 주세요." << endl;
		cin >> customer->age;

		cout << endl;

		cout << "계좌 개설 시 예금하고자할 금액을 입력해 주세요.(없으면 0원으로 입력해 주세요.)" << endl;
		cin >> customer->money;

		cout << endl;
	}
	void MakeAccount(class Customer* customer)
	{
		cout << customer->name << "님의 계좌 번호는 ";
		for (int i = 0; i < 4; i++)
		{
			customer->account[i] = Math::Random(0, 9);
			cout << customer->account[i];
		}
		cout << " 입니다." << endl;
	}

	void Deposit(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "계좌를 먼저 개설해 주세요." << endl;
			return;
		}

		cout << customer->name << "님의 계좌에 입금하실 금액을 입력해 주세요." << endl;
		cout << "현재 잔액 : " << customer->money << endl;
		int temp;
		cin >> temp;
		customer->money += temp;
		cout << customer->name << "님의 계좌에 현재 예금 잔액은 " << customer->money << "입니다." << endl << endl;
	}

	void Withdraw(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "계좌를 먼저 개설해 주세요." << endl;
			return;
		}

		while (1)
		{
			cout << customer->name << "님의 계좌에 출금하실 금액을 입력해 주세요." << endl;
			cout << "현재 잔액 : " << customer->money << endl;
			int temp;
			cin >> temp;
			if (temp > customer->money)
			{
				cout << "잔액보다 큰 금액을 출금하실 수 없습니다." << endl;
				break;
			}

			customer->money -= temp;
			cout << customer->name << "님의 계좌에 현재 예금 잔액은 " << customer->money << "입니다." << endl;
		}
	}

	void Print(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "계좌를 먼저 개설해 주세요." << endl;
			return;
		}

		cout << "이름 : " << customer->name << endl;
		cout << "나이 : " << customer->age << endl;
		cout << "계좌 번호 : " << customer->account << endl;
		cout << "예금 금액 : " << customer->money << endl;
	}

};



void Start();
void ReSet(Customer* one, Bank* one_info);
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

int main()
{
	Start();
	Customer* one = new Customer;
	Bank* one_info = new Bank;

	ReSet(one, one_info);

	while (Update())
	{
		ReSet(one, one_info);
	}
	delete one;
	delete one_info;
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

void ReSet(Customer* one, Bank* one_info)
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

		one_info->SetInfo(one);
		one_info->MakeAccount(one);
		break;
	}
	case 2:
	{
		cout << "<< 입금 >>" << endl;
		one_info->Deposit(one);
		break;
	}
	case 3:
	{
		cout << "<< 출금 >>" << endl;
		one_info->Withdraw(one);
		break;
	}
	case 4:
	{
		cout << "<< 계좌 정보 전체 출력 >>" << endl;
		one_info->Print(one);
		break;
	}
	default:
		cout << "잘못 입력하셨습니다." << endl;
	}


}