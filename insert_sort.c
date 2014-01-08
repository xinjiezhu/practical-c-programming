/*
 *function: insert_sort.c
 *description: insert sort algorithm, from small to larger
 *Date: 8-Jan-14
 */

#include <stdio.h>
#include <assert.h>

#define N 10



char *InsertSort(char *array, int num)
{ 
    int first_loop = 1;  /*assume prev value is first, from next*/
    int second_loop = 0;
    int temp = 0;

    assert(NULL != array && 0 != num);
    
    for (; first_loop < num; ++ first_loop)
    {
        if (array[first_loop] > array[first_loop -1])  /*good*/
        {
            continue;
        }
        temp = array[first_loop]; /*save */
        second_loop = first_loop;
        while (second_loop > 0 && temp < array[second_loop-1]) /*key point*/
        {/*shift right*/
            array[second_loop] = array[second_loop - 1];
            --second_loop;
        }
        array[second_loop] = temp; /*swap*/
    }
    return array;
}

int main()
{
    int loop = 0;
    char array[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};  /*the worst situation*/
    InsertSort(array, N);
    
    for (; loop < N; ++ loop)
    {
        printf("%d,", array[loop]);
    }
    printf("\n");
    return 0;
}
