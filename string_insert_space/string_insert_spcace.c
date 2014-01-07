/*name: string_insert_space.c
 *
 *Description: Insert space in the middle position of string
 *             fox example, 0011XXX-> 00 1 1XXX, 00301XX->00 30 1XX,
 *             003501XXX-> 00 350 1XXX and 0017581XXX-> 00 1758 1XX,
 *             input 9, exit.
 *Date: 7-Jan-14
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SRC_NUM 16
#define DEST_NUM (SRC_NUM + 2)

enum
{
    IS_1,
    IS_30,
    IS_350,
    IS_1758
};

const char num[][5] = {"1", "30", "350", "1758"}; /*const string*/

char *StrInsertSpace(char *dest, const char *src)
{
    if (NULL == src || NULL == dest)
    {
        return NULL;
    }
    
    if (0 != strncmp(src, "00", 2))
    {
        strcat(dest, src);
        return dest; 
    }
    src += 2; /*move 2 bit*/
    strncat(dest, "00", 2);

    if (0 == strncmp(src, num[IS_1], strlen(num[IS_1])) 
        && 0 != strncmp(src, num[IS_1758], strlen(num[IS_1758])))
    {/*middle numbers is 1 and not 1758*/
        strncat(dest, " ", 1);
        strncat(dest, num[IS_1], strlen(num[IS_1]));
        strncat(dest, " ", 1);
        strcat(dest, src + strlen(num[IS_1]));
    }
    else if (0 == strncmp(src, num[IS_30], strlen(num[IS_30])))
    {/*middle numbers is 30*/
        strncat(dest, " ", 1);
        strncat(dest, num[IS_30], strlen(num[IS_30]));
        strncat(dest, " ", 1);
        strcat(dest, src + strlen(num[IS_30]));
    }
    else if (0 == strncmp(src, num[IS_350], strlen(num[IS_350])))
    {/*middle numbers is 350*/
        strncat(dest, " ", 1);
        strncat(dest, num[IS_350], strlen(num[IS_350]));
        strncat(dest, " ", 1);
        strcat(dest, src + strlen(num[IS_350]));
    }
    else if (0 == strncmp(src, num[IS_1758], strlen(num[IS_1758])))
    {/*middle numbers is 1758*/
        strncat(dest, " ", 1);
        strncat(dest, num[IS_1758], strlen(num[IS_1758]));
        strncat(dest, " ", 1);
        strcat(dest, (src + strlen(num[IS_1758])));
    }
    else
    {/*default, do nothing*/
        strcat(dest, src);
    }
    return dest;
}


int main()
{
    char src[SRC_NUM+1] = {0};   /*end of '\0'*/
    char dest[DEST_NUM+1] = {0};
    
    printf("Welcome\n");
    
    while (1)
    {
        memset(dest, 0, sizeof(dest));      /*clear dest*/
        printf("Please input number:(9,exit)");
        fgets(src, sizeof(src), stdin);
        src[strlen(src)-1] = '\0';         /*replace '\n' with '\0'*/
        if (0 == strncmp(src, "9", 1))
        {/*input 9, exit loop*/
            break;
        }
        printf("Before convert, the string is %s\n", src);
        StrInsertSpace(dest, src);
        printf("After convert, the string is %s\n", dest);
    }
    
    printf("exit\n");
    return 0;
}
