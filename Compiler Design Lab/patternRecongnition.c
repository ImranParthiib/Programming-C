#include <stdio.h>
#include <string.h>
int main()
{
    char input[10];
    fgets(input, 10, stdin);

    int state = 0;

    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        if (input[i] == 'a')
        {
            state = 0;
        }
        else if (state == 0 && input[i] == 'b')
        {
            state = 1;
        }
        else if (input[i] != 'a' && input[i] != 'b')
        {
            state = -1;
        }
    }

    if (state == 0)
    {
        printf("String goes under a*");
    }
    else if (state == 1)
    {
        printf("String goes under a*b+");
    }
    else if (state == -1)
    {
        printf("Rejected!");
    }
}