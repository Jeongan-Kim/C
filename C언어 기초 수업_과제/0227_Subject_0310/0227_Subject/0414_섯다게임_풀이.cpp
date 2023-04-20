#include <iostream>
#include <Windows.h>

using namespace std;

/*
    38
    13 18
    ��
    �˸�
    ����
    ����
    ���
    ���
    ����
    ����
    ��
*/

enum JOKBO
{
    KK_0,
    KK_9 = 9,
    SR,
    JS,
    JB,
    GB,
    DS,
    AL,
    DD_1 = 21,
    DD_10 = 30,
    KD
};

struct Hwatoo
{
    int month;
    string shape;
};

struct Player
{
    string name;
    int money;
    int jokbo;
    Hwatoo card[2];
};

void Swap(Hwatoo* deck, int sour, int dest)
{
    Hwatoo temp = deck[sour];
    deck[sour] = deck[dest];
    deck[dest] = temp;
}

void Shuffle(Hwatoo* deck)
{
    for (int i = 0; i < 1000; i++)
    {
        int sour = rand() % 20;
        int dest = rand() % 20;
        Swap(deck, sour, dest);
    }
}

void MakeJokbo(int playernum, Player* players)
{
    for (int i = 0; i < playernum; i++)
    {
        if (players[i].card[0].month == players[i].card[1].month)
        {
            players[i].jokbo = players[i].card[0].month + (DD_1 - 1);
        }
        else if (players[i].card[0].shape == "��" &&
            players[i].card[1].shape == "��")
        {
            players[i].jokbo = KD;
        }
        else
        {
            players[i].jokbo = KK_0 + (players[i].card[0].month + players[i].card[1].month) % 10;

            if (players[i].card[0].month == 1)
            {
                if (players[i].card[1].month == 2)
                {
                    players[i].jokbo = AL;
                }
                else if (players[i].card[1].month == 2)
                {
                    players[i].jokbo = AL;
                }
                else if (players[i].card[1].month == 9)
                {
                    players[i].jokbo = GB;
                }
                else if (players[i].card[1].month == 10)
                {
                    players[i].jokbo = JB;
                }
            }
            else
            {
                if (players[i].card[0].month == 4)
                {
                    if (players[i].card[1].month == 10)
                    {
                        players[i].jokbo = JS;
                    }
                    else if (players[i].card[1].month == 6)
                    {
                        players[i].jokbo = SR;
                    }
                }
            }
        }
    }
}

void PrintPlayer(int playernum, Player* players)
{
    for (int i = 0; i < playernum; i++)
    {
        cout << players[i].name << "\t" <<
            players[i].card[0].month << players[i].card[0].shape << "\t" <<
            players[i].card[1].month << players[i].card[1].shape << "\t" <<
            players[i].money << "\t";

        if (players[i].jokbo == KD)
        {
            cout << players[i].card[0].month << players[i].card[1].month << "�ö�" << endl;
        }
        else if (players[i].jokbo < DD_1)
        {
            if (players[i].jokbo == AL)
            {
                cout << "�˸�" << endl;
            }
            else if (players[i].jokbo == DS)
            {
                cout << "����" << endl;
            }
            else if (players[i].jokbo == GB)
            {
                cout << "����" << endl;
            }
            else if (players[i].jokbo == JB)
            {
                cout << "���" << endl;
            }
            else if (players[i].jokbo == JS)
            {
                cout << "���" << endl;
            }
            else if (players[i].jokbo == SR)
            {
                cout << "����" << endl;
            }
            else
                cout << players[i].jokbo << "��" << endl;
        }
        else
        {
            cout << players[i].jokbo - 20 << "��" << endl;
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int playernum;
    Player* players;
    int bet = 0;

    while (true)
    {
        cout << "�÷��̾� �� : ";
        cin >> playernum;

        if (playernum > 10)
        {
            cout << "�ٽ� �Է��ϼ���" << endl;
            continue;
        }
        else
            break;
    }

    players = new Player[playernum];

    for (int i = 0; i < playernum; i++)
    {
        string name;
        cout << i + 1 << "��° �̸� : ";
        cin >> name;
        players[i].name = name;
        players[i].money = 10000;
    }

    Hwatoo deck[20];

    for (int i = 0; i < 20; i++)
    {
        deck[i].month = i % 10 + 1;
        deck[i].shape = "��";
    }
    deck[0].shape = deck[2].shape = deck[7].shape = "��";

    int start = 0;
    while (not start)
    {
        Shuffle(deck);

        for (int i = 0; i < playernum; i++)
        {
            bet += 500;
            players[i].money -= 500;

            players[i].card[0] = deck[i];
            players[i].card[1] = deck[i + 10];

            if (players[i].card[0].month > players[i].card[1].month)
            {
                Swap(players[i].card, 0, 1);
            }
        }

        MakeJokbo(playernum, players);

        int max = KK_0;
        int winner = 0;

        for (int i = 0; i < playernum; i++)
        {
            if (players[i].jokbo > max)
            {
                max = players[i].jokbo;
                winner = 1;
            }
            else if (players[i].jokbo == max)
                winner++;                
        }

        for (int i = 0; i < playernum; i++)
        {
            if (players[i].jokbo == max)
            {
                players[i].money += bet / winner;
                cout << players[i].name << "\t";
            }
        }
        cout << "�¸�!!" << endl;

        PrintPlayer(playernum, players);
        bet = 0;

        cout << endl;
        cout << "0. ��� 1. ������ => ";
        cin >> start;
        Sleep(1000);
        system("cls");
    }

    return 0;
}