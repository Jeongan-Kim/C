#include <iostream>

using namespace std;

class Animal
{
	string name;

public:
	Animal(string name) : name(name) {}

	virtual void Speak() const { cout << "??" << endl; } //울음 소리 저장

};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {} //부모클래스 생성자 통해서 이름 받아오기

	void Speak() const override { cout << "야옹" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}

	void Speak() const override { cout << "멍멍" << endl; }
};

int main()
{
	//각각 클래스들의 배열 만들기
	Cat cats[]{ Cat("cat1"), Cat("cat2"), Cat("cat3"), Cat("cat4"), Cat("cat5") };
	Dog dogs[]{ Dog("dog1"), Dog("dog2"), Dog("dog3"), Dog("dog4"), Dog("dog5") };

	for (const auto& cat : cats)
		cat.Speak();

	for (const auto& dog : dogs)
		dog.Speak();

	//부모 클래스로 upcasting 해주기
	Animal* animals[]
	{
		&cats[0],
		&cats[1],
		&cats[2],
		&cats[3],
		&cats[4],
		&dogs[0],
		&dogs[1],
		&dogs[2],
		&dogs[3],
		&dogs[4]
	};
	for (const auto& animal : animals) //??가 출력됨. (upcasting 되면서 생기는 문제->virtual, override 키워드를 써서 바꾸면 문제 해결)
		animal->Speak();


	return 0;
}