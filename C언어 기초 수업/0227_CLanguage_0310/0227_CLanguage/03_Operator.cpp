#include <stdio.h>

int main()
{
	//���� ������ : =
	int a = 10;

	//��� ������ : +, -, *, /, %(������ ������)
	int b = 3;
	int result;

	result = a + b;
	printf("%d\n", result);

	result = a - b;
	printf("%d\n", result);

	result = a * b;
	printf("%d\n", result);

	result = a / b;
	printf("%d\n", result);

	result = a % b;
	printf("%d\n", result);

	//��ȣ ������ : +, - ��ȣ�� ��Ÿ��

	//���� ���� ������
	//a = a + b; �̰� a ������ �ߺ��ǹǷ� �Ʒ��� ���� ǥ����
	a += b;

	//���� ������ : ���� 1 ������Ű�ų� ���ҽ�ų�� ���. ++, --
	a = 1;
	b = 1;
	a = ++b;//a�� b�� ���������� ���� ����(���� ������)
	printf("a : %d, b : %d\n", a, b);

	a = 1;
	b = 1;
	a = b++;//a�� b�� ������ �� b�� ����(���� ������)
	printf("a : %d, b : %d\n", a, b);
	//�� �� �Ŀ� �����ϳ� �ƴϳ��� ����

/*
	�� ������ :������ true, �ٸ��� false
	== : ������ true�� ��ȯ, �ٸ��� false
	!= : ������ false�� ��ȯ, �ٸ��� true
	<, >, <=, >=
*/

/*
	�� ������
	&& (and) : �� �� ������ �� �� ���̸� true, �� �� false
	|| (or) : �� �� ������ �� �� �ϳ��� ���̸� true, �� �� false
	! (not) : true�� ��� false, false�� ��� true�� ��ȯ(���� ������ �ִ� ������)

	1. true (&&) false => false
	2. true (||) false => true
	3. true (&&, ||) true => true
	4. (!)true	=> false
	5. (!)false  => true
*/

	//scanf

/*
	int num;

	scanf_s("%d", &num); //_s������ ���ȶ����� ������, ����â���� ���� ���� num�� �ʱ�ȭ(�� ����)�� �� �� �ְ� ����
	//scanf �ȿ��� \n�� ���� �� �ϰ�, ���� �տ� &�� ��� ��
	printf("%d\n", num);
	
*/

/*
	int num1, num2, num3;

	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("%d %d %d\n", num1, num2, num3);
*/

	//���� ������ - ���� ������
	//���ǽ� ? ��ȯ��1(���� ���) : ��ȯ��2(������ ���)


#pragma region Attack // �ڵ� ������ �� �� �ִ� ���� ����
	int playerDamage = 50;
	int enemyHp = 550;

	printf("�÷��̾��� ���ݷ� : %d\n", playerDamage);
	printf("���� ���� ü�� : %d\n\n", enemyHp);

	int attackCount = 0;
	printf("�� �� �����Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &attackCount);

	enemyHp -= playerDamage * attackCount; //enemyHp = enemyHp - playerDamage * attackCount
	printf("���� ���� ü�� : %d\n\n", enemyHp);



#pragma endregion //������ ��


#pragma region Grab
	int grabRange;
	int distance = 300;
	bool catchenemy = true; //true(1)�� false(0)�� ����ϴ� �Լ� bool

	printf("������ �Ÿ� :%d\n", distance);

	printf("�׷� ��Ÿ� : ");
	scanf_s("%d", &grabRange);

	grabRange >= distance ? catchenemy = true : catchenemy = false;

	printf("���� óġ�Ͽ�����? : %d\n", catchenemy);



#pragma endregion



	return 0;
}