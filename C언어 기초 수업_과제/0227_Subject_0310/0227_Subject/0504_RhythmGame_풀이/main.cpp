#include "stdafx.h"

#define COLUMN 6
#define ROW 29
#define CHECK_LINE 3
#define DROP_TIME 0.05f
#define SPAWN_TIME 0.4f

void Start();
bool Update();
void CheckNote(int x);
void Render();

struct note
{
    int x;
    int y;
};

std::vector<note> gameNote;

Timer timer;
float noteDropCount;
float noteSpawnCount;
int score = 100;

int main()
{
    Start();

    while (Update())
    {
        Render();
    }

    return 0;
}

void Start()
{
    system("title RhythmGame");
    system("mode con:cols=60 lines=30");

    {
        HANDLE hConsole;
        CONSOLE_CURSOR_INFO ConsoleCursor;

        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        ConsoleCursor.bVisible = 0;
        ConsoleCursor.dwSize = 1;

        SetConsoleCursorInfo(hConsole, &ConsoleCursor);
    }

    cout << "#########¸®µë°ÔÀÓ!!##########" << endl;

    system("pause");
}

bool Update()
{
    timer.Update();
    noteDropCount += timer.GetDeltaTimeSEC();
    noteSpawnCount += timer.GetDeltaTimeSEC();

    if (GetAsyncKeyState('Q')) CheckNote(1);
    if (GetAsyncKeyState('W')) CheckNote(2);
    if (GetAsyncKeyState('E')) CheckNote(3);
    if (GetAsyncKeyState('R')) CheckNote(4);

    if (noteSpawnCount >= SPAWN_TIME)
    {
        note temp;

        temp.x = Math::Random(1, COLUMN - 2);
        temp.y = 0;

        gameNote.push_back(temp);

        noteSpawnCount = 0.0f;
    }

    if (noteDropCount >= DROP_TIME)
    {
        for (auto& note : gameNote)
            note.y++;

        for (auto iter = gameNote.begin(); iter != gameNote.end();)
        {
            if (iter->y >= ROW - 1)
            {
                iter = gameNote.erase(iter);
                score -= 10;

                if (score == 0)
                    exit(1);
            }
            else
                iter++;
        }

        noteDropCount = 0.0f;
    }

    return true;
}

void CheckNote(int x)
{
    for (auto iter = gameNote.begin(); iter != gameNote.end();)
    {
        if (iter->x == x && iter->y >= ROW - CHECK_LINE - 1)
        {
            iter = gameNote.erase(iter);
            score += 10;
        }
        else
            iter++;
    }
}

void gotoxy(int x, int y)
{
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Render()
{
    system("cls");

    for (int i = 0; i < ROW; i++)
    {
        gotoxy(0, i);
        cout << "¡Ø";
        gotoxy(COLUMN - 1, i);
        cout << "¡Ø";
    }

    for (int i = 0; i < COLUMN; i++)
    {
        gotoxy(i, ROW - 1);
        cout << "¡Ø";
    }

    for (int i = 0; i < CHECK_LINE; i++)
    {
        gotoxy(0, ROW - i - 2);
        cout << "¢º";
        gotoxy(COLUMN - 1, ROW - i - 2);
        cout << "¢¸";
    }

    {
        gotoxy(1, ROW);
        cout << " Q W E R";
    }

    for (const auto& note : gameNote)
    {
        gotoxy(note.x, note.y);
        cout << "¢Ü";
    }

    {
        gotoxy(10, 5);
        cout << "score : " << score;
    }
}