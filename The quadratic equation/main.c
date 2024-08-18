
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char continuation_stop [3];
    float coeff_a = 0; //the first coefficient in the equation
    float coeff_b = 0; //the second coefficient in the equation
    float coeff_c = 0; //the third coefficient in the equation
    float x = 0;       //the answer is if the root is one
    float x1 = 0;      //the answer is if there are 2 roots
    float x2 = 0;      //the answer is if there are 2 roots
    float discriminant = 0;
    printf("~ Hi, this program solves a quadratic equation. Enter \"!\" to stop the program or \"go\" to continue!\n");
    scanf("%s", continuation_stop);
    while(strlen(continuation_stop) != 1)

    {
        printf("~ Enter the coefficients of the quadratic equation \"coeff_a\", \"coeff_b\", \"coeff_c\" \
in this sequence.\n");
        scanf ("%f%f%f", &coeff_a, &coeff_b, &coeff_c);
        printf("~ Okay, your coefficients \n  coeff_a = %.2f\n  coeff_b = %.2f\n  coeff_c = %.2f.\n~ That's right?\nWrite \"yes\" \
if everything is correct, \"no\" if you want to change the coefficients.\n", coeff_a , coeff_b, coeff_c);
        char changing_coefficients[4];
        scanf("%s", changing_coefficients);
        if(strlen(changing_coefficients) == 3)
            printf("~ We continue.\n");
        if(strlen(changing_coefficients) == 2)

        {
            printf("~ Change the coefficients.\n");
            printf("~ Enter the other coefficients of the quadratic equation \"coeff_a\",\"coeff_b\",\"coeff_c\"\
in this sequence.\n");
            scanf ("%f%f%f", &coeff_a, &coeff_b, &coeff_c);

        }

        printf("~ Okay, we hope you entered everything correctly.n");
        if (coeff_b > 0 && coeff_c > 0) printf("your equation has the form %.2fx^2 + %.2fx + %.2f = 0.\n", coeff_a, coeff_b, coeff_c);
        if (coeff_b > 0 && coeff_c < 0) printf("your equation has the form %.2fx^2 + %.2fx%.2f = 0.\n", coeff_a, coeff_b, coeff_c);
        if (coeff_b < 0 && coeff_c > 0) printf("your equation has the form %.2fx^2%.2fx + %.2f = 0.\n", coeff_a, coeff_b, coeff_c);
        if (coeff_b < 0 && coeff_c < 0) printf("yout equation has the firm %.2fx^2%.2fx%.2f = 0.\n", coeff_a, coeff_b, coeff_c);
        printf("~ Getting to the solution.\n");
        if(coeff_a == 0 && coeff_b != 0 && coeff_c !=0)

        {
            printf("~ NOTE THAT THE EQUETION IS NOT QUADRATIC.\n");
            printf("~ Then the solution of the equation will be. ");
            x = (-coeff_c) / coeff_b;
            printf("* Answer: x = %.2f", x);
        }

        if (coeff_a == 0 && coeff_b == 0 && coeff_c == 0)
            printf("* Answer: x takes all values");
        if (coeff_a != 0 && coeff_b == 0 && coeff_c != 0)
            printf("* Answer: x takes all values\n");
        if (coeff_a != 0 && coeff_b != 0 && coeff_c == 0)

        {
            x1 = 0;
            x2 = (-coeff_b) / coeff_a;
            printf("* Answer: x1 = %.2f\n          x2 = %.2f\n", x1, x2);

        }

        if (coeff_a != 0 && coeff_b != 0 && coeff_c != 0)

        {
            discriminant = coeff_b * coeff_b-4 * coeff_a * coeff_c;
            if (discriminant < 0 && coeff_a!=0 && coeff_b!=0 && coeff_c != 0)
            printf("* There is no answer.\n");

        }

        if (discriminant == 0 && coeff_a != 0 && coeff_b != 0 && coeff_c != 0 )

        {
            x = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            printf("* Answer: x = %.2f\n", x);
        }

        if (discriminant > 0 && coeff_a != 0 && coeff_b != 0 && coeff_c !=0 )

        {
            x1 = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            x2 = (-coeff_b - sqrtf(discriminant)) / (2 * coeff_a);
            printf("* Answer: x1 = %.2f\n          x2 = %.2f\n", x1, x2);
        }

      printf("~ write \"!\" to stop and \"go\" to continue! \n");
      scanf("%s", continuation_stop);

    }

    printf("$ Thank you for using this program!");
    return 0;

}
