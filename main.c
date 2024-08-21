
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#define SS_INF_ROOTS -5

float is_equal (float a, float b);
float SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2, float *root);


int main()
{
    int operation_number = 1;
    char continuation_stop [3];
    float coeff_a = 0; //the first coefficient in the equation
    float coeff_b = 0; //the second coefficient in the equation
    float coeff_c = 0; //the third coefficient in the equation
    float root = 0;       //the answer is if the root is one
    float root1 = 0;      //the answer is if there are 2 roots
    float root2 = 0;      //the answer is if there are 2 roots
    float discriminant = 0;
    Beep(440,1000);
    printf("(%d) Hi, this program solves a quadratic equation. Enter \"!\" to stop the program or \"go\" to continue!\n", operation_number);
    scanf("%s", continuation_stop);
    while(strlen(continuation_stop) != 1)

    {
        ++operation_number;
        printf("(%d) Enter the coefficients of the quadratic equation \"coeff_a\", \"coeff_b\", \"coeff_c\" \
in this sequence.\n",operation_number);
        scanf ("%f%f%f", &coeff_a, &coeff_b, &coeff_c);
         ++operation_number;
        printf("(%d) Okay, your coefficients \n  coeff_a = %.2f\n  coeff_b = %.2f\n  coeff_c = %.2f.\nThat's right?\nWrite \"yes\" \
if everything is correct, \"no\" if you want to change the coefficients.\n",operation_number, coeff_a , coeff_b, coeff_c);
        char changing_coefficients[4];
        scanf("%s", changing_coefficients);

        if(strlen(changing_coefficients) == 3)
        {
            ++operation_number;
            printf("(%d) We continue.\n",operation_number);
        }

        if(strlen(changing_coefficients) == 2)
        {
            ++operation_number;
            printf("(%d) Change the coefficients.\n",operation_number);
            ++operation_number;
            printf("(%d) Enter the other coefficients of the quadratic equation \"coeff_a\",\"coeff_b\",\"coeff_c\"\
in this sequence.\n",operation_number);
            scanf ("%f%f%f", &coeff_a, &coeff_b, &coeff_c);
        }

        ++operation_number;
        printf("(%d) Okay, we hope you entered everything correctly.\n",operation_number);
        ++operation_number;
        printf("(%d)Getting to the solution.\n",operation_number);
        int nRoots =  SolveSquare (coeff_a, coeff_b, coeff_c, &root1, &root2, &root);

         switch (nRoots)
        {
        case 0:  printf("* No roots\n");
                 break;
        case 1:  printf("* Answer: %f\n", root);
                 break;
        case 2:  printf("* Answer: x1 = %.2f\n          x2 = %.2f\n", root1, root2);
                 break;
        case SS_INF_ROOTS:  printf("* Any number\n");
                            break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
                 return 1;
        }
       ++operation_number;
       printf("(%d) write \"!\" to stop and \"go\" to continue! \n",operation_number);
       scanf("%s", continuation_stop);
   }
   ++operation_number;
   Beep(440,1000);
   printf("(%d) Thank you for using this program!\n",operation_number);
   return 0;
}

 float is_equal (float a, float b)
 {
    float e = 0.000001;
    if (fabs(a-b) < e)
        return 1;
    else
        return 0;
 }

 float SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2, float *root)
 {
    if (!is_equal(coeff_a,0))
    {
        float discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

        if(discriminant > 0 &&!is_equal(coeff_b,0) && !is_equal(coeff_c,0))
        {
            *root1 = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            *root2 = (-coeff_b - sqrtf(discriminant)) / (2 * coeff_a);
            return 2;
        }

        if (is_equal(discriminant,0) && !is_equal(coeff_a,0) && !is_equal(coeff_b,0) && !is_equal(coeff_c,0))
        {
            *root = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            return 1;
        }

        if (discriminant < 0 && !is_equal(coeff_a,0) && !is_equal(coeff_b,0) && !is_equal(coeff_c,0))
        {
            return 0;
        }

        if (!is_equal(coeff_b,0) && is_equal(coeff_c,0))
        {
            *root1 = 0;
            *root2 = (-coeff_b) / coeff_a;
            return 2;
        }

        if (is_equal(coeff_b,0) && coeff_c > 0)
        {
            return 0;
        }

        if (is_equal(coeff_b,0) && coeff_c < 0)
        {
            *root1 = -sqrt(-coeff_c/coeff_a);
            *root2 =  sqrt(-coeff_c/coeff_a);
            return 2;
        }
    }

    else
    {

        if(!is_equal(coeff_b,0) && !is_equal(coeff_c,0))
        {
            *root = -coeff_c / coeff_b;
            return 1;
        }

        if(is_equal(coeff_b,0) && !is_equal(coeff_c,0))
        {
            return 0;
        }

        if(!is_equal(coeff_b,0) && is_equal(coeff_c,0))
        {
            *root = 0;
            return 1;
        }

        if(is_equal(coeff_b,0) && is_equal(coeff_c,0))
        {
            return -5;
        }
    }
 }
