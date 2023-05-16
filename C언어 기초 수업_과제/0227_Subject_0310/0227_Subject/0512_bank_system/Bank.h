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
	void MakeAccount(); //계좌 개설

	void Deposit(); //입금

	void Withdraw(); //출금

	void Print(); //계좌 정보 출력
};
