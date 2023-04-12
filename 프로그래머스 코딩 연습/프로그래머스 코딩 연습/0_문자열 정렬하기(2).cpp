#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char* solution(const char* my_string) 
{
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    char* answer = (char*)malloc(1000);
    strcpy(answer, my_string);

    //�빮��->�ҹ���
    for (int i = 0; i < strlen(answer); i++)
    {
        if (answer[i] < 91)
            answer[i] += 32;
    }

    //�������
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


//���� ����
//���� ��ҹ��ڷ� �̷���� ���ڿ� my_string�� �Ű������� �־��� ��, my_string�� ��� �ҹ��ڷ� �ٲٰ� ���ĺ� ������� ������ ���ڿ��� return �ϵ��� solution �Լ��� �ϼ��غ�����.
//
//���ѻ���
//0 < my_string ���� < 100
// 
//    ����� ��
//    my_string	    result
//    "Bcad"	    "abcd"
//    "heLLo"	    "ehllo"
//    "Python"      "hnopty"
// 
//    ����� �� ����
//    ����� �� #1
//
//    "Bcad"�� ��� �ҹ��ڷ� �ٲٸ� "bcad"�̰� �̸� ���ĺ� ������ �����ϸ� "abcd"�Դϴ�.
//    ����� �� #2
//
//    "heLLo"�� ��� �ҹ��ڷ� �ٲٸ� "hello"�̰� �̸� ���ĺ� ������ �����ϸ� "ehllo"�Դϴ�.
//    ����� �� #3
//
//    "Python"�� ��� �ҹ��ڷ� �ٲٸ� "python"�̰� �̸� ���ĺ� ������ �����ϸ� "hnopty"�Դϴ�.