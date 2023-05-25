#include <iostream>

using namespace std;

class Book
{
	string name;
	int ISBN;
	int price;

public:
	Book(string name, int ISBN, int price)
		: name(name), ISBN(ISBN), price(price)
	{}

	virtual ~Book() {}
};

class E_book : public Book
{
	string site;
public:
	E_book(string site, string name, int ISBN, int price)
		:site(site), Book(name, ISBN, price)
	{
		cout << "E_book�� �����߽��ϴ�." << endl
			<<"å �̸� : " << name << endl
			<< "å ISBN : " << ISBN << endl
			<< "å ���� : " << price << endl
			<< "å ���� ����Ʈ : " << site << endl
			<< "--------------------------" << endl;
	}
};

class P_book : public Book
{
	static int count;
public:
	P_book(string name, int ISBN, int price)
		:Book(name, ISBN, price)
	{
		cout << "P_book�� �����߽��ϴ�." << endl
			<< "å �̸� : " << name << endl
			<< "å ISBN : " << ISBN << endl
			<< "å ���� : " << price << endl
			<< "--------------------------" << endl;

		count++;
		if (count >= 5)
		{
			cout << "å���� �� á���ϴ�." << endl 
				<< "--------------------------" << endl << endl;
		}


	}

	~P_book()
	{
		count--;
	}
};

int P_book::count = 0;

int main()
{
	E_book e1("siteA", "ebook1", 1234, 5000);
	E_book e2("siteB", "ebook2", 1235, 6000);

	P_book p1("pbook1", 4321, 7000);
	P_book p2("pbook2", 4322, 8000);
	P_book p3("pbook3", 4323, 9000);
	P_book p4("pbook4", 4324, 10000);
	P_book p5("pbook5", 4325, 11000);
	P_book p6("pbook6", 4326, 12000);


	return 0;
}