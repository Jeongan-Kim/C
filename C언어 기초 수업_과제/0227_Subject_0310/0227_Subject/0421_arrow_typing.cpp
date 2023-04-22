#include <iostream>
#include <random>
#include <conio.h>
#include <ctime>
#include <Windows.h>
#include <chrono>

/*
1. 게임 룰 설명
2. 게임 시작
	-제한 시간(화살표 타이핑과 관련없이 흐름) : 10초
	-화살표 랜덤 생성
	-화살표 입력(앞에서부터 차례대로)
	-화살표 일치하면 별 모양으로 변함
	-남은 횟수와 점수 출력 ( 점수 -> 성공 시 +1000점 )
3. 계속 점수를 얻으며 무한 모드
4. 남은 횟수 모두 소진 시 게임 종료
	-점수 출력
*/

using namespace std;

void gameRulePrint() //게임 룰 출력, 게임 시작 체크
{
	cout << "******** 화살표 타이핑 게임 ********" << endl
		<< "1. 화면에 출력된 화살표를 제한 시간 안에 순서대로 입력하세요." << endl
		<< "2. 틀리면 처음부터 다시 입력하세요." << endl
		<< "3. 목숨을 모두 소진하기 전에 최고 점수를 달성해 보세요." << endl << endl
		<< "-----아무 키나 누르면 게임이 시작됩니다.-----" << endl;

	while (1)
	{
		if (_kbhit()) //키 입력 시 화면 초기화.
		{
			system("cls");
			break;
		}
	}
}

random_device rd;
mt19937 messenne(rd());
uniform_int_distribution<> randNUM(0, 3);

class arrowGame
{
	int arrow[10]{ 0 };
	int score = 0; //게임 점수 : 한 문제 성공할 때마다 1000점 획득
	int lifeCount = 5; //게임 목숨 5개 지급

public:
	void timeStream(int gameTime) //"■■■■■■■■■■■■■■■" 처럼 남은 시간 출력
	{
		cout << "남은 시간 : ";
		for (int i = gameTime; i < 15; i++)
		{
			cout << "■";
		}
		cout << endl;
	}

	void arrowCheck(int& inputNum, int& inputValue) //플레이어가 입력한 값이 정답인지 체크
	{
		if (arrow[inputNum] == inputValue)
			inputNum++;
		else
		{
			inputNum = 0;
			lifeCount--;
		}
	}

	void arrowSet() //랜덤하게 화살표 배열 세팅
	{
		for (int i = 0; i < 10; i++)
		{
			arrow[i] = randNUM(messenne);
		}
	}

	void arrowPrint(int inputNum) //화살표 배열 출력 ( 플레이어가 맞힌 화살표만큼은 별로 출력 )
	{
		for (int i = 0; i < 10; i++)
		{
			if(i < inputNum)
				cout << "☆  ";
			else if (i >= inputNum)
			{
				if(arrow[i] == 0)
					cout << "↑  ";
				else if (arrow[i] == 1)
					cout << "↓  ";
				else if (arrow[i] == 2)
					cout << "←  ";
				else if (arrow[i] == 3)
					cout << "→  ";
			}
		}
		cout << endl;
	}

	void ScoreNLife(int mistake, int success) //남은 목숨과 점수 출력
	{
		score = success * 1000;
		lifeCount -= mistake;
		cout << "남은 목숨 : " << lifeCount << ", 현재 점수 : " << score << endl;
	}

	int gameOver(int gameTime) //게임 오버 체크 : 시간 종료, 목숨 모두 소진
	{
		if (gameTime >= 15)
		{
			cout << "제한 시간 안에 성공하지 못했습니다." << endl << "-----------GAME OVER------------" << endl;
			return 0;
		}
		else if (lifeCount == 0)
		{
			cout << "남은 목숨이 없습니다." << endl << "-----------GAME OVER------------" << endl;
			return 0;
		}
	}

	int gameSuccess(int& inputNum, int& success) // 한 문제 성공 체크
	{
		if (inputNum == 10)
		{
			inputNum = 0;
			success++;
			return 0;
		}
	}

};

class Player
{

public:
	int mistake = 0; //실패 횟수
	int success = 0; //맞힌 문제 수
	int inputValue = -1; //입력된 화살표를 받을 변수
	int inputNum = 0; //각 문제를 푸는 도중 맞힌 화살표 수

	void InputValue() //플레이어가 입력한 값을 정수로 전달하기 위한 함수.
	{
		switch (inputValue)
		{
		case 72:
			inputValue = 0;
			break;
		case 80:
			inputValue = 1;
			break;
		case 75:
			inputValue = 2;
			break;
		case 77:
			inputValue = 3;
			break;
		}
	}
};

int main()
{
	int gameTime = 0; //게임 시간
	gameRulePrint();

	arrowGame arrowgame;
	Player player;

	while (1)
	{
		auto start = chrono::steady_clock::now(); //새로운 문제가 시작되는 순간부터 시간 재기.
		int gameTime = 0;

		arrowgame.arrowSet();

		while (1)
		{			
			system("cls");

			arrowgame.timeStream(gameTime); //시간 출력
			arrowgame.arrowPrint(player.inputNum); //화살표 출력
			arrowgame.ScoreNLife(player.mistake, player.success); //목숨, 점수 출력

			
			if (arrowgame.gameOver(gameTime) == 0) //게임 오버 체크
				return 0;

			if (arrowgame.gameSuccess(player.inputNum, player.success) == 0) //성공 체크
				break;
			


			if (_kbhit()) //키가 입력되면 화살표 확인
			{
				int temp = _getch();

				if (temp != 224)
					continue;

				player.inputValue = _getch();
				player.InputValue();
				arrowgame.arrowCheck(player.inputNum, player.inputValue); //화살표 입력(맞으면 별로 바뀜)
			}


			Sleep(10); 

			auto end = chrono::steady_clock::now(); //이 순간까지 지난 시간
			gameTime = chrono::duration_cast<chrono::seconds>(end - start).count(); //재어진 시간 값
		}	
	}

	return 0;
}