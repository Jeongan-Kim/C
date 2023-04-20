#include <iostream>

using namespace std;
//객체지향 활동 방식 : 동작을 중심으로 코드를 짜는 것. 함수를 호출하는 것에 중점을 두는 것이다.
class Data
{
	int hp;
	int attack;
	float exp; //밑에 private로 명시해 주거나 위에 써주거나 취향 차이.

	

public:
	void SetData(int hpData, int attackData, float expData)//맴버의 데이터를 초기화 또는 수정하기 위해서는 함수 안에서 해주는 게 좋음
	{
		hp = hpData;
		attack = attackData;
		exp = expData;
	}

	void SetData2(Data data) //이렇게도 넣어줄 수 있음.
	{
		hp = data.hp;
		attack = data.attack;
		exp = data.exp;
	}

	//밖에서 private변수에 접근할 수 없지만 접근하고 싶을때 쓰는 함수
	//객체지향 시스템을 지키면서 접근은 가능하게 쓰는 것
	int GetHp() { return hp; }
	int GetAttack() { return attack; } //이렇게 쓰면 오버헤드(처리 시간이 더 오래 걸리거나 메모리가 쓰이는 등)가 일어날 수 있긴 함
};

class FruitSeller //사과 장수의 동작을 만드는 것
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
		cout << "남은 사과 : " << numofApple << endl;
		cout << "판매 수익 : " << myMoney << endl;
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
		numofApples = 0; //처음에는 안샀으니 0개로
	}

	void BuyApples(FruitSeller& seller, int money) //주소에 의한 참조를 해서 값을 변경해 줘야 함
	{
		numofApples += seller.SaleApples(money);
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numofApples << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);

	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller, 2000); //seller에게서 2000원 어치 사겠다.

	cout << "과일 판매자 현황" << endl;
	seller.ShowSaleResult();

	cout << "과일 구매자 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}