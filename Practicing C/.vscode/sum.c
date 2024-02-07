#include<stdio.h>

int main(){

    int a , b , sum;
    a = 45;
    b = 89;
    sum = a + b;
    printf("The Summation of a + b is : %d\n ",sum);
    printf("%d + %d = %d\n", a, b, sum);
    printf("%d + %d = %d\n", b, a, sum);
    return 0;
}