#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
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


//���� ����
//���ڿ� str1, str2�� �Ű������� �־����ϴ�.str1 �ȿ� str2�� �ִٸ� 1�� ���ٸ� 2�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
//
//���ѻ���
//1 �� str1�� ���� �� 100
//1 �� str2�� ���� �� 100
//���ڿ��� ���ĺ� �빮��, �ҹ���, ���ڷ� �����Ǿ� �ֽ��ϴ�.
//����� ��
//str1	                            str2	        result
//"ab6CDE443fgh22iJKlmn1o"	        "6CD"	        1
//"ppprrrogrammers"             	"pppp"	        2
//"AbcAbcA"	                        "AAA"	           2
//����� �� ����
//����� �� #1
//
//"ab6CDE443fgh22iJKlmn1o" str1�� str2�� �����ϹǷ� 1�� return�մϴ�.
//����� �� #2
//
//"ppprrrogrammers" str1�� str2�� �����Ƿ� 2�� return�մϴ�.
//����� �� #3
//
//"AbcAbcA" str1�� str2�� �����Ƿ� 2�� return�մϴ�.