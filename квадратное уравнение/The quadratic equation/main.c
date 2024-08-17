
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

int main()
{
    float a=0;
    float b=0;
    float c=0;
    float x=0;
    float x1=0;
    float x2=0;
    float D;
    printf("Hello, enter the coefficients of the quadratic equation \"a\",\"b\",\"c\" in this sequence \n");
    scanf ("%f%f%f",  &a,  &b,  &c);
    printf("Okay, your odds a=%.2f, b=%.2f, c=%.2f, that's right?\nWrite \"yes\" if everything is correct, \"no\" if you want to change the coefficients\n",a,b,c);
    char world[3];
    scanf("%s", world);
    if(strlen(world) == 3)
        printf("We continue\n");
    if(strlen(world) == 2)
    {
        printf("Change the coefficients\n");
        printf("enter the other coefficients of the quadratic equation \"a\",\"b\",\"c\" in this sequence\n");
        scanf ("%f%f%f", &a, &b, &c);
    }
    printf("Okay, we hope you entered everything correctly\n");
    if (b>0 && c>0)
        printf("your equation has the form %.2fx^2+%.2fx+%.2f=0\n", a,b,c);
    if (b>0 && c<0)
        printf("your equation has the form %.2fx^2+%.2fx%.2f=0\n", a,b,c);
    if (b<0 && c>0)
        printf("your equation has the form %.2fx^2%.2fx+%.2f=0\n", a,b,c);
    if (b<0 && c<0)
        printf("your equation has the form %.2fx^2%.2fx%.2f=0\n", a,b,c);
    printf("getting to the solution\n");
    if(a==0 && b!=0 && c!=0)
    {
        printf("NOTE THAT THE EQUETION IS NOT QUADRATIC\n");
        printf("then the solution of the equation will be   ");
        x = (-c)/b;
        printf("%.2f", x);
    }
    if(a==0 && b==0 && c==0)
        printf("x takes all values");
    if(a!=0 && b==0 && c!=0)
        printf("x takes all values");
    if(a!=0 && b!=0 && c==0)
    {
        x1 = 0;
        x2 = (-b)/a;
        printf("x1=%.2f\nx2=%.2f", x1, x2);
    }
    if(a!=0 && b!=0 && c!=0);
    {
        D = b*b-4*a*c;
        if(D<0 && a!=0 && b!=0 && c!=0)
            printf("There is no answer");
        if(D==0 && a!=0 && b!=0 && c!=0 )
        {
            x = (-b + sqrtf(D))/(2*a);
            printf("%.2f", x);
        }
        if (D>0 && a!=0 && b!=0 && c!=0)
        {
            x1 = (-b + sqrtf(D))/(2*a);
            x2 = (-b - sqrtf(D))/(2*a);
            printf("x1=%.2f\nx2=%.2f", x1, x2);
        }
    }
    return 0;
}
