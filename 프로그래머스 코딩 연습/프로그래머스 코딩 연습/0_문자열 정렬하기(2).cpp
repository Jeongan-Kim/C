#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1000);
    strcpy(answer, my_string);

    //대문자->소문자
    for (int i = 0; i < strlen(answer); i++)
    {
        if (answer[i] < 91)
            answer[i] += 32;
    }

    //순서대로
    int min_index;
    for (int i = 0; i < strlen(answer) - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < strlen(answer); j++)
        {
            if (answer[min_index] > answer[j])
                min_index = j;
        }
        char temp = answer[i];
        answer[i] = answer[min_index];
        answer[min_index] = temp;
    }



    printf("%s", answer);
    return answer;
}

int main()
{
    const char* my_string = "heLLo";
    solution(my_string);

    return 0;
}


//문제 설명
//영어 대소문자로 이루어진 문자열 my_string이 매개변수로 주어질 때, my_string을 모두 소문자로 바꾸고 알파벳 순서대로 정렬한 문자열을 return 하도록 solution 함수를 완성해보세요.
//
//제한사항
//0 < my_string 길이 < 100
// 
//    입출력 예
//    my_string	    result
//    "Bcad"	    "abcd"
//    "heLLo"	    "ehllo"
//    "Python"      "hnopty"
// 
//    입출력 예 설명
//    입출력 예 #1
//
//    "Bcad"를 모두 소문자로 바꾸면 "bcad"이고 이를 알파벳 순으로 정렬하면 "abcd"입니다.
//    입출력 예 #2
//
//    "heLLo"를 모두 소문자로 바꾸면 "hello"이고 이를 알파벳 순으로 정렬하면 "ehllo"입니다.
//    입출력 예 #3
//
//    "Python"를 모두 소문자로 바꾸면 "python"이고 이를 알파벳 순으로 정렬하면 "hnopty"입니다.