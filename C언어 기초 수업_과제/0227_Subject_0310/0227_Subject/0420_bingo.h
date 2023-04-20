#pragma once

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define X 5
#define Y 5

using namespace std;

void Swap(int x1, int y1, int x2, int y2, int arr[X][Y]);
void shuffle(int n, int arr[X][Y]);
int BingoCount(int arr[X][Y]);
int CheckWin(Player player, Computer computer, int myBingo[X][Y], int comBingo[X][Y]);
void bingoPrint(int arr[X][Y]);

