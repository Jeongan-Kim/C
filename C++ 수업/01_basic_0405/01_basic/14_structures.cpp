#include <iostream>

using namespace std;

struct person
{
	void __thiscall Print(/* person* */)
	{
		cout << age << endl;
	}

	int age;
	float weight = 50.0f;
	string name = "Jeongan";
};

int main()
{
	person p1;

	p1.Print();
	//person::Print(); //�̷��Դ� �Ұ���
	return 0;
}

/*
* 
* ����
�Լ� ȣ�� �Ծ�(function calling convension) �˾ƺ���
*/