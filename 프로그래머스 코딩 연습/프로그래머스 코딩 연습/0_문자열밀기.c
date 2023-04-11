#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int answer = 0;
    //int count = 0;
    char A[] = "hghgh";
    char B[] = "ghghh";
    char arr1[100] = { 0 };

    strcpy(arr1, B);
    printf("cpy : %s\n", arr1);
    //printf("len : %d\n", strlen(arr1));
    strcat(arr1, B);
    printf("cat : %s\n", arr1);
    //printf("len : %d\n", strlen(arr1));

    printf("A : %s\n", A);
    printf("B : %s\n", B);
 
    int i = 0, j = 0;
    while (j < strlen(arr1))
    {
        if (i == strlen(A))
            break;

        if (A[i] == arr1[j])
        {
            if (i == strlen(A) - 1)
                answer = j - i;
            printf("answer : %d  A[%d] = %c, arr1[%d] = %c\n", answer, i, A[i], j, arr1[j]);
            i++;
            j++;
        }
        else
        {
            answer = -1;
            printf("answer : %d  A[%d] = %c, arr1[%d] = %c\n", answer, i, A[i], j, arr1[j]);
            j -= i - 1;
            i = 0;
            
        }
    }
  

    printf("a : %d\n", answer);

    return 0;
}

