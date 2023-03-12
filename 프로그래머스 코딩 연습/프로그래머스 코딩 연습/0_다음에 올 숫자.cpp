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

/*
문제 설명
등차수열 혹은 등비수열 common이 매개변수로 주어질 때, 마지막 원소 다음으로 올 숫자를 return 하도록 solution 함수를 완성해보세요.

제한사항
2 < common의 길이 < 1,000
-1,000 < common의 원소 < 2,000
common의 원소는 모두 정수입니다.
등차수열 혹은 등비수열이 아닌 경우는 없습니다.
등비수열인 경우 공비는 0이 아닌 정수입니다.
입출력 예
common      	result
[1, 2, 3, 4]	5
[2, 4, 8]   	16
입출력 예 설명
입출력 예 #1

[1, 2, 3, 4]는 공차가 1인 등차수열이므로 다음에 올 수는 5이다.
입출력 예 #2

[2, 4, 8]은 공비가 2인 등비수열이므로 다음에 올 수는 16이다.
*/