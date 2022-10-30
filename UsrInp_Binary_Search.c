#include <stdio.h>
int binarysearch(int A[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[mid] == x)
        {
            return mid;
        }
        if (A[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main(void)
{
    printf("Enter number of elements: ");
  scanf("%d", &n);
    int n = sizeof(A) / sizeof(A[0]);
    int x = 4;
    int result = binarysearch(A, n - 1, x);
    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);
    return 0;
}