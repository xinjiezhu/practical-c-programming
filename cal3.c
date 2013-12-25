#include <stdio.h>
char  line[100];   /* line of text from input */

int   result;      /* the result of the calculations */
char  operator;    /* operator the user specified */
int   value;       /* value specified after the operator */
int main()
{
    result = 0;    /* initialize the result */

    /* loop forever (or until break reached) */
    while (1) {
        printf("Result: %d\n", result);
        printf("Enter operator and number: ");

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c %d", &operator, &value);

        if ((operator == 'q') || (operator == 'Q'))
            break;
        switch (operator) {
        case '+':
            result += value;
            break;
        case '-':
            result -= value;
            break;
        case '*':
            result *= value;
            break;
        case '/':
            if (value == 0) {
                printf("Error:Divide by zero\n");
                printf("   operation ignored\n");
            } else
                result /= value;
            break;
        default:
            printf("Unknown operator %c\n", operator);
            break;
        }
    }
    return (0);
}
