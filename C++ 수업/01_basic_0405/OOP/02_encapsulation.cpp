#include <iostream>

using namespace std;
//��ü���� Ȱ�� ��� : ������ �߽����� �ڵ带 ¥�� ��. �Լ��� ȣ���ϴ� �Ϳ� ������ �δ� ���̴�.
class Data
{
	int hp;
	int attack;
	float exp; //�ؿ� private�� ����� �ְų� ���� ���ְų� ���� ����.

	

public:
	void SetData(int hpData, int attackData, float expData)//�ɹ��� �����͸� �ʱ�ȭ �Ǵ� �����ϱ� ���ؼ��� �Լ� �ȿ��� ���ִ� �� ����
	{
		hp = hpData;
		attack = attackData;
		exp = expData;
	}

	void SetData2(Data data) //�̷��Ե� �־��� �� ����.
	{
		hp = data.hp;
		attack = data.attack;
		exp = data.exp;
	}

	//�ۿ��� private������ ������ �� ������ �����ϰ� ������ ���� �Լ�
	//��ü���� �ý����� ��Ű�鼭 ������ �����ϰ� ���� ��
	int GetHp() { return hp; }
	int GetAttack() { return attack; } //�̷��� ���� �������(ó�� �ð��� �� ���� �ɸ��ų� �޸𸮰� ���̴� ��)�� �Ͼ �� �ֱ� ��
};

class FruitSeller //��� ����� ������ ����� ��
{
	int applePrice;
	int numofApple;
	int myMoney;

public:
	void InitMembers(int price, int num, int money)
	{
		applePrice = price;
		numofApple = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / applePrice;
		numofApple -= num;
		myMoney += money;
		return num;
	}

	void ShowSaleResult()
	{
		cout << "���� ��� : " << numofApple << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numofApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numofApples = 0; //ó������ �Ȼ����� 0����
	}

	void BuyApples(FruitSeller& seller, int money) //�ּҿ� ���� ������ �ؼ� ���� ������ ��� ��
	{
		numofApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numofApples << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);

	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 2000); //seller���Լ� 2000�� ��ġ ��ڴ�.

	cout << "���� �Ǹ��� ��Ȳ" << endl;
	seller.ShowSaleResult();

	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}