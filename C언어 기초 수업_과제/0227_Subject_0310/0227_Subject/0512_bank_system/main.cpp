#include "stdafx.h"

class Customer
{
	string name; //�̸�
	int age; //����
	double money; //����
	int account[4]; //���¹�ȣ

	friend class Bank;

public:
	Customer() : name(""), age(0), money(0)
	{
		for (int i = 0; i < 4; i++)
			account[i] = 0;
	}

	Customer(const Customer& customer) //���� ������
		: name(customer.name), age(customer.age), money(customer.money)
	{
		for (int i = 0; i < 4; i++)
			account[i] = customer.account[i];
	}

	Customer& operator = (const Customer& data) //���� ���� ������
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
		cout << "���¸� �����Ͻ� ���� ������ �Է��� �ּ���." << endl;
		cin >> customer->name;

		cout << endl;

		cout << customer->name << "���� ���̸� �Է��� �ּ���." << endl;
		cin >> customer->age;

		cout << endl;

		cout << "���� ���� �� �����ϰ����� �ݾ��� �Է��� �ּ���.(������ 0������ �Է��� �ּ���.)" << endl;
		cin >> customer->money;

		cout << endl;
	}
	void MakeAccount(class Customer* customer)
	{
		cout << customer->name << "���� ���� ��ȣ�� ";
		for (int i = 0; i < 4; i++)
		{
			customer->account[i] = Math::Random(0, 9);
			cout << customer->account[i];
		}
		cout << " �Դϴ�." << endl;
	}

	void Deposit(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "���¸� ���� ������ �ּ���." << endl;
			return;
		}

		cout << customer->name << "���� ���¿� �Ա��Ͻ� �ݾ��� �Է��� �ּ���." << endl;
		cout << "���� �ܾ� : " << customer->money << endl;
		int temp;
		cin >> temp;
		customer->money += temp;
		cout << customer->name << "���� ���¿� ���� ���� �ܾ��� " << customer->money << "�Դϴ�." << endl << endl;
	}

	void Withdraw(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "���¸� ���� ������ �ּ���." << endl;
			return;
		}

		while (1)
		{
			cout << customer->name << "���� ���¿� ����Ͻ� �ݾ��� �Է��� �ּ���." << endl;
			cout << "���� �ܾ� : " << customer->money << endl;
			int temp;
			cin >> temp;
			if (temp > customer->money)
			{
				cout << "�ܾ׺��� ū �ݾ��� ����Ͻ� �� �����ϴ�." << endl;
				break;
			}

			customer->money -= temp;
			cout << customer->name << "���� ���¿� ���� ���� �ܾ��� " << customer->money << "�Դϴ�." << endl;
		}
	}

	void Print(class Customer* customer)
	{
		if (customer->name == "")
		{
			cout << "���¸� ���� ������ �ּ���." << endl;
			return;
		}

		cout << "�̸� : " << customer->name << endl;
		cout << "���� : " << customer->age << endl;
		cout << "���� ��ȣ : " << customer->account << endl;
		cout << "���� �ݾ� : " << customer->money << endl;
	}

};



void Start();
void ReSet(Customer* one, Bank* one_info);
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

	cout << "######### ���� ���࿡ ���� �� ȯ���մϴ�. ##########" << endl << endl;

	system("pause");
}

void ReSet(Customer* one, Bank* one_info)
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

		one_info->SetInfo(one);
		one_info->MakeAccount(one);
		break;
	}
	case 2:
	{
		cout << "<< �Ա� >>" << endl;
		one_info->Deposit(one);
		break;
	}
	case 3:
	{
		cout << "<< ��� >>" << endl;
		one_info->Withdraw(one);
		break;
	}
	case 4:
	{
		cout << "<< ���� ���� ��ü ��� >>" << endl;
		one_info->Print(one);
		break;
	}
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}


}