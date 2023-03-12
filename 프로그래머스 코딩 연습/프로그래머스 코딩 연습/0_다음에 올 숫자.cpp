#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int common[], size_t common_len) 
{
    int answer = 0;
    int i = common[0];
    int j = common[1];
    int k = common[2];
    if ((j-i) == (k-j))
    {
        answer = common[common_len-1] + (j - i);
    }
    else if (j / i == k / j)
    {
        answer = common[common_len-1] * (j / i);
    }
    return answer;
}