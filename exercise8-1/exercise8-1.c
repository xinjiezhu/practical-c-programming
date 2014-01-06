/*
 *@function: exercise8-1.c
 *@description:Print a checker board (8-by-8 grid). 
 *             Each square should be 5-by-3 characters wide. 
 *             A 2-by-2 example follows:
 *              +-----+-----+ 
 *              |     |     | 
 *              |     |     | 
 *              |     |     | 
 *              +-----+-----+ 
 *              |     |     | 
 *              |     |     | 
 *              |     |     | 
 *              +-----+-----+
 *Date: 6-Jan-2014
 */

#include <stdio.h>

const int NUM = 8;


void PrintAddSymbol(int num)
{
    int loop = 0;
    for(; loop < num; ++ loop)
    {
        printf("+-----");
    }
    printf("+\n");
}

void PrintVerticalSymbol(int num)
{
    int loop = 0;
    for(; loop < num; ++ loop)
    {
        printf("|     ");
    }
    printf("|\n");
}

int main()
{
    int row_loop = 0;
    for(; row_loop < NUM; ++ row_loop)
    {
        PrintAddSymbol(NUM);
        PrintVerticalSymbol(NUM);
        PrintVerticalSymbol(NUM);
        PrintVerticalSymbol(NUM); 
    }
    PrintAddSymbol(NUM);
    return 0;
}
