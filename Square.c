#include <stdio.h>
void subtraction(int a, int b);
int main()
{
    subtraction(20, 30);
    return 0;
}
void subtraction(int a, int b)
{
    a = 20;
    b = 30;
    int sub = (a - b);
    printf("The Subtraction of the two integer is:%d\n", sub);
}