#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int array[], size_t array_len) 
{
    int answer = 0;
 
    for (int i = 0; i < array_len; i++)
    {
        int number_size = 0;

        while(true)
        {
            if (array[i] % 10 == 7)
            {
                answer++;
            }
            array[i] /= 10;
           
            if (array[i] < 1)
                break;
        }
    }
    return answer;
}


//for (int i = 0; i < array_len; i++)
//{
//    int number_size = 0;
//
//    while (true)
//    {
//        int A = array[i] / 10;
//        number_size++;
//        if (A < 1)
//            break;
//    }
//
//    for (int j = 0; j < number_size; j++)
//    {
//        if (array[i] % 10 == 7)
//        {
//            answer++;
//        }
//        array[i] = (array[i] - array[i] % 10) / 10;
//    }
//}
//return answer;