#include <stdio.h>
int main(void)
{
    int num[3][3] = {33, 12, 21, 34, 44, 5, 6, 22, 18}, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", *(&num[i][j]));
        }
        printf("\n");
    }
    return 0;
}