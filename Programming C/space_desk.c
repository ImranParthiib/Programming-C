#include <stdio.h>
int main()
{
    int x, y, z, S;
    x = y = z = 50;
    int myNum = 23;
    float myage = 23.17;
    char myName = 'I';
    printf("I am %d years old\n", myNum);
    printf("My actual age is %f years old\n", myage);
    printf("My name started with the letter \"%C\"\n", myName);
    S = x + y + z;
    printf("%d\n", S);
    // Student Data
    int student_Id = 211153964;
    int student_Age = 23;
    float student_fee = 75.25;
    char student_Grade = 'A';

    // print Variables
    printf("Student Id %d\n", student_Id);
    printf("Student Age is %d\n", student_Age);
    printf("Student fee for Registration %f\n", student_fee);
    printf("The Grade of the Student is %c\n", student_Grade);

    // Lets Learn about float & double
    float my_Float_Num = 2.89;
    double mydoubleNum = 30.90;
    printf("%.2f\n", my_Float_Num);
    printf("%.2lf\n", mydoubleNum);
    // Type Conversion Learning

    int a = 5;
    int b = 2;
    float sum = (float)a / b;
    int remainder = a % b;
    printf("%d\n", remainder);
    printf("%.1f\n", sum);

    return 0;
}