#pragma once

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

