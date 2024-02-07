#include <stdio.h>
int main()
{

    int savings;
    scanf("%d", &savings);
    if (savings > 5000)
    {
        if (savings > 10000)
        {
            printf("Roadtrip with Neha\n");
        }
        else
        {
            printf("Shopping with Neha\n");
        }
    }
    else if (savings < 0)
    {
        printf("Rashni\n");
    }
    else
    {
        printf("Friends");
    }
    return 0;
}