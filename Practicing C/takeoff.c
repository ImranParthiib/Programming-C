#include<stdio.h>
#include<math.h>

int main(){
    const double PI = 3.1416;
    double diameter;
    scanf("%lf", &diameter);
    double radius = (diameter / 2);
    double cArea = PI * (radius * radius);
    printf("Circle Area : %.2lf\n", cArea);

    int base, height;
    scanf("%d %d", &base, &height);
   
    double tArea = 0.5*(base*height);

     printf("Triangle Area : %.2lf\n", tArea);
     double result = (cArea - tArea)/3;
     printf("Final Result : %.2lf\n", result);

     return 0;
    
}