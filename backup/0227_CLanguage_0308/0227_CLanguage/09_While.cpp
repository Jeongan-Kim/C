#include <stdio.h>
#include <conio.h> //�ܼ� ����� �Լ�

/*
	while(���ǽ�)
	{
		��ɹ�; //������ ���� ��� ��ɹ��� Ư�� ������ �����Ҷ����� ������ �ݺ���.
	}
*/

int main()
{
	//while
	bool study = true;

	while (study) //study �� ���̹Ƿ� ������ ����Ǵ� �Լ��� ���� �� -> ���� ������ ���� �ʰ� ���� ������ ����� ��� ��
	{
		printf("Hello world\n");

		printf("���� ���ΰ���? [�� : 1, �ƴϿ� : 0] -> ");
		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == 0)
		{
			study = false;
			//break; �� ����
		}
	}

	char key;

	while (true) //���� �ݺ���
	{
		printf("�̵�Ű �Է� : ");
		key = _getch(); //scanf�� ������ �̵�Ű�� �ٷιٷ� �Է��� �ȵǰ� �����̰� ����⿡ �ٷιٷ� ��µǴ� �Լ�(_getchar())

		if (key == 'q')
			break;

		switch (key)
		{
		case 'w': printf("��\n"); break;
		case 's': printf("��\n"); break;
		case 'a': printf("��\n"); break;
		case 'd': printf("��\n"); break;
		default: printf("�߸�����\n"); break;
		}
	}

	//do while
	/*
		do
		{
			��ɹ�;
		}while(���ǽ�) // �ݵ�� �� ���� ���� �ǰ�, ������ ���̸� �� ���ĵ� �ݺ���
	*/

	const int secretCode = 123123; //constant : ���ȭ ���Ѽ� ������ �ʴ� ������ ���� ����.

	int password = 0;
	int tryCount = 0;

	do
	{
		if (tryCount >= 3)
		{
			printf("3ȸ ���� ���� ���!\n");
			break;
		}
		printf("��й�ȣ �Է� (3ȸ ���� �� ���, ���� ���� Ƚ�� : %d) => ", tryCount);
		scanf_s("%d", &password);

		tryCount++; //tryCount += 1;

	} while (password != secretCode);


	return 0;
}

