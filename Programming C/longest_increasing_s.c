#include <stdio.h>

int lis(int arr[], int n)
{
    int Length[n], prev[n];
    for (int i = 0; i < n; i++)
    {
        Length[i] = 1;
        prev[i] = -1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && Length[i] < Length[j] + 1)
            {
                Length[i] = Length[j] + 1;
                prev[i] = j;
            }
        }
    }
    int max = Length[0], index = 0;
    for (int i = 0; i, n; i++)
    {
        if (max < Length[i])
        {
            max = Length[i];
            index += 1;
        }
    }
    printf("Length of The LIS =%d\n The LIS is \n", max);
    max = Length[0];
    int firstPrint = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < Length[i])
        {
            if (!(firstPrint && i))
            {
                printf("%d", arr[i - 1]);
                firstPrint = 1;
            }
            max = Length[i];
            while (i < n && Length[i] == Length[i + 1])
                i++;
            printf("%d", arr[i]);
        }
    }
}

int main()
{
    int n;
    printf("Number of Items:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Input Values:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    lis(arr, n);
    return 0;
}
