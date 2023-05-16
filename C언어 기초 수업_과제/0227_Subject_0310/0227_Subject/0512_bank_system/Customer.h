#pragma once

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

