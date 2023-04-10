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
	double duration; //게임 시간 ( 1초당 10점 제공 )

	//플레이어 초기 포지션
	int posx = 10;
	int posy = 5;

	//12*12 map 2차원 동적할당
	int** map = NULL;
	map = (int**)malloc(sizeof(int*) * 12);

	if (map != NULL)
	{

		for (int i = 0; i < 12; i++)
		{
			map[i] = (int*)malloc(sizeof(int) * 12);
		}

		//map 초기화(테두리, 별, 플레이어, 공백)
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (i == 0 || j == 0 || i == 11 || j == 11) //테두리
					*(*(map + i) + j) = 1;
				else if (i == posx && j == posy)
					*(*(map + i) + j) = 3;
				else
					*(*(map + i) + j) = 0;//공백
			}
		}
		//랜덤함수
		std::random_device rd;
		std::mt19937 messenne(rd());
		std::uniform_int_distribution<> randNUM(1, 10);

		std::cout << "남은 목숨 : " << count << std::endl;
		mapPrint(map);

		start = time(NULL);

		while (1)
		{
			//루프 종료
			if (count == 0)
			{
				std::cout << "남은 목숨이 없습니다." << std::endl << "---GAME OVER---" << std::endl;
				break;
			}
			

			//별 떨어짐
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

			//랜덤 별 뽑기
			for (int i = 0; i < 5; i++)
			{
				*(*(map + 1) + randNUM(messenne)) = 2;
			}

			//플레이어 무빙
			if (_kbhit())
			{
				char key = _getch();
				if (key == -32)
				{
					key = _getch();
					*(*(map + posx) + posy) = 0;
					switch (key)
					{
					case 72: //상
					{
						posx--;
						if (posx == 0)
							posx++;
						else if (*(*(map + posx) + posy) == 2)
							count--;

						break;
					}
					case 80: //하
					{
						posx++;
						if (posx == 11)
							posx--;
						else if (*(*(map + posx) + posy) == 2)
							count--;
						break;
					}
					case 75: //좌
					{
						posy--;
						if (posy == 0)
							posy++;
						else if (*(*(map + posx) + posy) == 2)
							count--;
						break;
					}
					case 77: //우
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
			std::cout << "남은 목숨 : " << count << std::endl;
			mapPrint(map);
		}
	}
	finish = time(NULL);
	duration = (double)(finish - start);
	std::wcout << "최종 점수 : " << duration * 10 << std::endl;

	//2차원 동적할당 해제
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
			if (*(*(map + i) + j) == 0)//공백
			{
				std::cout << "  ";
			}
			else if (*(*(map + i) + j) == 1)//테두리
			{
				std::cout << "▦";
			}
			else if (*(*(map + i) + j) == 2)//별
			{
				std::cout << "☆";
			}
			else if (*(*(map + i) + j) == 3)//플레이어
			{
				std::cout << "●";
			}
		}
		std::cout << std::endl;
	}
}

