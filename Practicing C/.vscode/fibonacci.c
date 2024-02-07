#include <stdio.h>

// fibonacci() function definition
int fibonacci(int num)
{
    int arr[num + 2]; // array to store fibonacci numbers, [num + 2] because to store the n = 0 case

    arr[0] = 0; // equating the first element of the array to first base value of the fibonacci series
    arr[1] = 1; // equating the second element of the array to second base value of the fibonacci series

    for (int i = 2; i <= num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2]; // adding previous two terms to get the next term
    }

    return arr[num]; // returning the element at index num
}

int main()
{
    int num; // variable to store how many elements to be displayed in the series
    printf("Enter the number of elements to be in the series : ");
    scanf("%d", &num); // taking user input

    for (int i = 0; i < num; i++)
    {
        printf("%d, ", fibonacci(i)); // calling fibonacci() function for each iteration and printing the returned value
    }

    return 0;
}
