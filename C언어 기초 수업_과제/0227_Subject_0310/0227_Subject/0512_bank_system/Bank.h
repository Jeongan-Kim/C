#pragma once

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

void AccountCheck();


class Bank
{
	friend class Customer;
public:
	void MakeAccount(); //���� ����

	void Deposit(); //�Ա�

	void Withdraw(); //���

	void Print(); //���� ���� ���
};
