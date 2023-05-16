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
	string name; //�̸�
	int age; //����
	double money; //����
	int account[4]; //���¹�ȣ

	friend class Bank;

public:
	Customer(string name, int age, double money, int account[4]) : name(name), age(age), money(money)
	{
		for (int i = 0; i < 4; i++)
			this->account[i] = account[i];
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
	void MakeAccount() //���� ����
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
			account[i] = Math::Random(0, 9); //���� ���� ����
			cout << account[i];
		}
		cout << " �Դϴ�." << endl;
		Customer temp(name, age, money, account); //�� �ӽ� ��ü

		customers.push_back(temp); //list�� �� �ӽ� ��ü ����
	}

	void Deposit() //�Ա�
	{
		cout << "�Ա��Ͻ� ���� ��ȣ�� ���ʴ�� �Է��� �ּ���." << endl;
		int check1 = 0;
		int temp_account[4]; //����ڿ� ���� �Էµ� ���� ��ȣ �ӽ� ���� ����

		for (int i = 0; i < 4; i++)
		{
			cout << i + 1 << "��° ���ڸ� �Է��ϼ���. => ";
			cin >> temp_account[i];
			cout << endl;
		}

		for (auto& ele : customers) //customers list�� ���Ҹ� Ȯ��
		{
			if (CheckAccount(ele.account, temp_account)) //�Էµ� ���� ��ȣ�� ������ üũ�ϴ� �Լ�
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

	void Withdraw() //���
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

	void Print() //���� ���� ���
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