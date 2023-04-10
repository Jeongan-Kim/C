#include <iostream>
#include <random>
#include <conio.h>
#include <Windows.h>
#include <ctime>


void mapPrint(int** map);

int main()
{
	int count = 3;
	time_t start, finish;
	double duration; //���� �ð� ( 1�ʴ� 10�� ���� )

	//�÷��̾� �ʱ� ������
	int posx = 10;
	int posy = 5;

	//12*12 map 2���� �����Ҵ�
	int** map = NULL;
	map = (int**)malloc(sizeof(int*) * 12);

	if (map != NULL)
	{

		for (int i = 0; i < 12; i++)
		{
			map[i] = (int*)malloc(sizeof(int) * 12);
		}

		//map �ʱ�ȭ(�׵θ�, ��, �÷��̾�, ����)
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (i == 0 || j == 0 || i == 11 || j == 11) //�׵θ�
					*(*(map + i) + j) = 1;
				else if (i == posx && j == posy)
					*(*(map + i) + j) = 3;
				else
					*(*(map + i) + j) = 0;//����
			}
		}
		//�����Լ�
		std::random_device rd;
		std::mt19937 messenne(rd());
		std::uniform_int_distribution<> randNUM(1, 10);

		std::cout << "���� ��� : " << count << std::endl;
		mapPrint(map);

		start = time(NULL);

		while (1)
		{
			//���� ����
			if (count == 0)
			{
				std::cout << "���� ����� �����ϴ�." << std::endl << "---GAME OVER---" << std::endl;
				break;
			}
			

			//�� ������
			for (int i = 9; i > 0; i--)
			{
				for (int j = 1; j < 11; j++)
				{
					if (i == posx && j == posy)
						continue;
					else if (i + 1 == posx && j == posy)
					{
						if (*(*(map + i) + j) == 2)
							count--;
						continue;
					}
					
					*(*(map + (i + 1)) + j) = *(*(map + i) + j);
					*(*(map + i) + j) = 0;
				}
			}

			//���� �� �̱�
			for (int i = 0; i < 5; i++)
			{
				*(*(map + 1) + randNUM(messenne)) = 2;
			}

			//�÷��̾� ����
			if (_kbhit())
			{
				char key = _getch();
				if (key == -32)
				{
					key = _getch();
					*(*(map + posx) + posy) = 0;
					switch (key)
					{
					case 72: //��
					{
						posx--;
						if (posx == 0)
							posx++;
						else if (*(*(map + posx) + posy) == 2)
							count--;

						break;
					}
					case 80: //��
					{
						posx++;
						if (posx == 11)
							posx--;
						else if (*(*(map + posx) + posy) == 2)
							count--;
						break;
					}
					case 75: //��
					{
						posy--;
						if (posy == 0)
							posy++;
						else if (*(*(map + posx) + posy) == 2)
							count--;
						break;
					}
					case 77: //��
					{
						posy++;
						if (posy == 11)
							posy--;
						else if (*(*(map + posx) + posy) == 2)
							count--;
						break;
					}
					}
				}
			}
			*(*(map + posx) + posy) = 3;


			Sleep(300);
			system("cls");
			std::cout << "���� ��� : " << count << std::endl;
			mapPrint(map);
		}
	}
	finish = time(NULL);
	duration = (double)(finish - start);
	std::wcout << "���� ���� : " << duration * 10 << std::endl;

	//2���� �����Ҵ� ����
	for (int i = 0; i < 12; i++)
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
	
	return 0;
}

void mapPrint(int** map)
{ 
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (*(*(map + i) + j) == 0)//����
			{
				std::cout << "  ";
			}
			else if (*(*(map + i) + j) == 1)//�׵θ�
			{
				std::cout << "��";
			}
			else if (*(*(map + i) + j) == 2)//��
			{
				std::cout << "��";
			}
			else if (*(*(map + i) + j) == 3)//�÷��̾�
			{
				std::cout << "��";
			}
		}
		std::cout << std::endl;
	}
}

