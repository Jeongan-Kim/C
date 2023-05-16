#include "stdafx.h"

void Start();
void ReSet();
bool Update();
void AccountCheck();
bool CheckAccount(const int* arr1, const int* arr2)
{
	for (int i = 0; i < 4; i++)
	{
		if (arr2[i] != arr1[i])
		{
			return false;
		}
	}
	return true;
}


class Customer
{
	string name; //이름
	int age; //나이
	double money; //예금
	int account[4]; //계좌번호

	friend class Bank;

public:
	Customer(string name, int age, double money, int account[4]) : name(name), age(age), money(money)
	{
		for (int i = 0; i < 4; i++)
			this->account[i] = account[i];
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
	void MakeAccount() //계좌 개설
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
			account[i] = Math::Random(0, 9); //계좌 랜덤 생성
			cout << account[i];
		}
		cout << " 입니다." << endl;
		Customer temp(name, age, money, account); //고객 임시 객체

		customers.push_back(temp); //list에 고객 임시 객체 저장
	}

	void Deposit() //입금
	{
		cout << "입금하실 계좌 번호를 차례대로 입력해 주세요." << endl;
		int check1 = 0;
		int temp_account[4]; //사용자에 의해 입력된 계좌 번호 임시 저장 변수

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "번째 숫자를 입력하세요. => ";
			cin >> temp_account[i];
			cout << endl;
		}

		for (auto& ele : customers) //customers list의 원소를 확인
		{
			if (CheckAccount(ele.account, temp_account)) //입력된 계좌 번호와 같은지 체크하는 함수
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

	void Withdraw() //출금
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

	void Print() //계좌 정보 출력
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
};

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