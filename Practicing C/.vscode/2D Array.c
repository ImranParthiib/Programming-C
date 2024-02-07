Bappi Pal
#include<stdio.h>
int main()
{
 int i,j,NumOfRow,NumOfColoumn,A[10][10],B[10][10],C[10][10];
 printf("How many row:");
 scanf("%d %d",&i,&j);
 printf("How many Coloumn:");
 scanf("%d %d",&i,&j);
//Scan for A's value:
 for(i=0;i<NumOfRow;i++)
   {
     for(j=0;j<NumOfColoumn;j++)
   {
    scanf("%d",&A[i][j]);
     } }
   // Scan for B's value:
    for (i = 0; i < NumOfRow; i++)
    {
        for (j = 0; j < NumOfColoumn; j++)
        {
           scanf("%d", &B[i][j]);
                  }}
                      // Print for A's value:
  for (i = 0; i < NumOfRow; i++)
  {
     for (j = 0; j < NumOfColoumn; j++)
    {
        printf("%d", A[i][j]);
     }
     printf("\n");
   }
   // Print for B's value:
   for (i = 0; i < NumOfRow; i++)
  {
      for (j = 0; j < NumOfColoumn; j++)
       {
           printf("%d",B[i][j]);
        }
   }
   // Adding Value:
   for (i = 0; i < NumOfRow; i++)
   {
       for (j = 0; j < NumOfColoumn; j++)
       {
           C[i][j]=A[i][j]+B[i][j];
       }
   }
    //output
       printf("A+B=");
    for (i = 0; i < NumOfRow; i++)
    {
        for (j = 0; j < NumOfColoumn; j++)
        {
          printf("%d",C[i][j]);
       }
   }
   return 0;
}