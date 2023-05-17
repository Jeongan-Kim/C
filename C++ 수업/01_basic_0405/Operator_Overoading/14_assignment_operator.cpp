#include <iostream>
#include <cassert>//���� ������ false�̸� ���� �� �ֵ��� �������
//���� ������, �̵� ������(�� ���� ��ü�� �޾ƿ��� ��, r-value)
using namespace std;

/*
	���ݱ��� ��� ���� �����ڴ� ���� ���� ������ ����
	deep copy vs shallow copy

	���� ���� : ��� �� ��� ���簡 ����µ�, �����͸� �����Ҷ����� ���� ���縦 �ϸ�(�״�� ����Ǳ� ������) ������ �ּҰ� �������� ������ ������ �ʰ� ���� ���� �����ڸ� �������� ��
	�����Ҵ��� �ϸ鼭 ���߿� ����� ��ü�� �����ؼ� ���� �� ������ ���� ����� ������ ���� �Ͼ�� �ʰ� �ϴ� ��.
*/

class Mystring 
{
public:
	char* data = nullptr;
	int length = 0;

public:
	Mystring(const char* const src = " ") //���� ���ڿ�(nullptr�� ������ �� ���ڿ��� �����Ѵ�)
	{
		//�̶�, �ƹ��͵� �޾ƿ��� ������ ������ ������
		assert(src);

		length = strlen(src) + 1;
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0'; //������ ���ڴ� �������� �ϱ� ���ؼ�
	}

	//���� ������(���� ����)
	Mystring(const Mystring& other) 
		//�����ͷ� �������� ������ �ּҰ� �Ѿ��(������ �ּҿ� ������
		//-> �Ҹ��ڿ� ���� �������µ� other�������־ �Ҹ�� ���� ����Ű�� ��Ȳ�� ����(���������)
		//�׷��� �����Ҵ��� �̿��ؼ� ���� ���� ���� ���� ����Ű�� �ʰԲ� ��(�������� ����)
	{
		this->length = other.length;
		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			data = nullptr;//�߸� ������ ��� �η� �ʱ�ȭ.
		}
	}

	~Mystring()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	//���� ���� ������
	Mystring& operator = (const Mystring& other) //���� ���� �����ڸ� ������ ������ �ڵ����� ���� ���� ���� �����ڰ� �������
	{
		if (this == &other) //�� �ڽ��� �Ҵ��ϴ� ��Ȳ�� �����
		{
			return *this;
		}

		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		cout << "copy assignment operator" << endl;
		this->length = other.length;

		if (other.data != nullptr)
		{
			this->data = new char[length];
			for (int i = 0; i < this->length; i++)
				this->data[i] = other.data[i];
		}
		else
		{
			this->data = nullptr;
		}

		return *this;
	}

	//�̵� ������ : ������ ���ִ� �� �ƴ϶� �̵���Ų�ٰ� ��������.
	Mystring(Mystring&& other) //r-value ���۷����ϱ� &&, l����ó�� �޾ƿ� ���� ��.
	{
		cout << "move constructor" << endl;

		this->data = std::move(other.data);
		this->length = std::move(other.length);
		//���� �� ���۷����� ���� Ÿ�� ĳ�����Ѵٰ� ��������.

		//���� other(������ ���۷���)�� �ѹ� ���� ���Ŵϱ� ���̻� �� �� ���� �������� ���ϰ� ����
		other.data = nullptr;
	}

	//�̵� ���� ������ : ������ �߶�ͼ� ���� ���� �ڸ��� �ִ� ���� ���ֹ����� ��
	Mystring& operator = (Mystring&& other)
	{
		cout << "move assignment operator" << endl;

		if (this == &other) //prevent self-assignment(�ڱ� �ڽ��� �Ҵ��ϴ� ��)/ �̷� ��Ȳ�� Ȥ�� �𸣴� �׻� �����ؾ� ��
			return *this;

		//�������� ���� ���� ����Ű�� �����Ҵ� �����Ҷ� �������� ������ �������. ���� ��츦 �����ϵ��� �� Ȯ������

		if (this->data != nullptr)
		{
			if (other.data != nullptr && this->data != other.data)
			{
				delete[] this->data;
				this->data = nullptr;

				this->data = std::move(other.data);
			}
		}
		else
			this->data = std::move(other.data);

		this->length = std::move(other.length);

		other.data = nullptr;

		return *this;
	}
};

int main()
{
	cout << "#############1###########" << endl;
	Mystring str("Hello");
	cout << (int*)str.data << endl; // �ּ� ���, &str.data�� ������ ��ü�� �ּҰ� ����, ���ڿ��� ����� ������ �ּҸ� int������ �������� �̷��� ��. 
	cout << str.data << endl << endl; //�� ���

	cout << "#############2###########" << endl;
	//copy
	{
		Mystring copy(str);
		copy = str;
		cout << (int*)copy.data << endl;
		cout << copy.data << endl << endl;
	} //������ �����鼭 ����� ��ü�� �����

	cout << "#############3###########" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl; // ������ �����ִ��� Ȯ��
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}

	cout << "#############4###########" << endl;
	//move
	{
		Mystring copy(std::move(str)); //copy�� �̵������� str�� ������
		copy = std::move(str);

		cout << (int*)copy.data << endl;
		cout << copy.data << endl;
	}
	
	cout << "#############5###########" << endl;
	if (str.data != nullptr)
	{
		cout << (int*)str.data << endl;
		cout << str.data << endl << endl;
	}
	else
	{
		cout << (int*)str.data << endl << endl;
	}


	/*
	#############1###########
	0000022B865C20F0
	Hello

	#############2###########
	copy assignment operator
	0000022B865C2280
	Hello

	#############3###########
	0000022B865C20F0
	Hello

	#############4###########
	move constructor
	move assignment operator
	0000022B865C20F0
	Hello

	#############5###########
	0000000000000000
	
	
	*/

	return 0;
}

/*
	<����>
	TestŬ������ �ϳ� ����
	�ڵ� ȣ��Ǵ� �͵�(Ư���ɹ� �Լ�, special member function)
	-�⺻, ����, �������, �̵�, �̵�����, �Ҹ�
	�Ⱥ��� ������.

*/