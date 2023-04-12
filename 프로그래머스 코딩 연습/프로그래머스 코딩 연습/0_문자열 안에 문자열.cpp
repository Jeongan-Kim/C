#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* str1, const char* str2) 
{
    int answer = 0;
    int i= 0;
    int j = 0;
    while(1)
    {
        if (str1[j] != str2[i])
        {
            answer = 2;
            printf("str1[%d] = %c, str2[%d] = %c, answer = %d\n", j, str1[j], i, str2[i], answer);
            j = j - i + 1;
            i = 0;
            printf("i : %d, j : %d\n", i, j);
        }
        else if (str1[j] == str2[i])
        {
            if (i == strlen(str2) - 1)
            {
                answer = 1;
                break;
            }
            printf("str1[%d] = %c, str2[%d] = %c, answer = %d\n", j, str1[j], i, str2[i], answer);
            i++;
            j++;
            printf("i : %d, j : %d\n", i, j);
        }

        if (j == strlen(str1))
            break;
    }

    if (answer == 0)
        answer = 2;

    printf("%d", answer);
    return answer;
}

int main()
{
    const char* str2 = "AAAAbcA";
    const char* str1 = "AAA";

    solution(str1, str2);
    return 0;
}


//문제 설명
//문자열 str1, str2가 매개변수로 주어집니다.str1 안에 str2가 있다면 1을 없다면 2를 return하도록 solution 함수를 완성해주세요.
//
//제한사항
//1 ≤ str1의 길이 ≤ 100
//1 ≤ str2의 길이 ≤ 100
//문자열은 알파벳 대문자, 소문자, 숫자로 구성되어 있습니다.
//입출력 예
//str1	                            str2	        result
//"ab6CDE443fgh22iJKlmn1o"	        "6CD"	        1
//"ppprrrogrammers"             	"pppp"	        2
//"AbcAbcA"	                        "AAA"	           2
//입출력 예 설명
//입출력 예 #1
//
//"ab6CDE443fgh22iJKlmn1o" str1에 str2가 존재하므로 1을 return합니다.
//입출력 예 #2
//
//"ppprrrogrammers" str1에 str2가 없으므로 2를 return합니다.
//입출력 예 #3
//
//"AbcAbcA" str1에 str2가 없으므로 2를 return합니다.