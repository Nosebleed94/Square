#include "working with the user.h"
#include "solve.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Testing.h"

void  input (float *coeff_a,  float *coeff_b, float *coeff_c)
{
    assert(isfinite(*coeff_a));
    assert(isfinite(*coeff_b));
    assert(isfinite(*coeff_c));
    assert (coeff_a != NULL);
    assert (coeff_b != NULL);
    assert (coeff_c != NULL);
    scanf ("%f%f%f", coeff_a, coeff_b, coeff_c);
}

int filing_main(int *operation_number, float *coeff_a, float *coeff_b, float *coeff_c)
 {
     assert (operation_number != NULL);
     assert (coeff_a != NULL);
     assert (coeff_b != NULL);
     assert (coeff_c != NULL);
     char continuation_stop [3];
     ++(*operation_number);
        printf("(%d) Enter the coefficients of the quadratic equation \"coeff_a\", \"coeff_b\", \"coeff_c\" \
in this sequence.\n", *operation_number);

        input ( coeff_a, coeff_b,  coeff_c);


         ++(*operation_number);
        printf("(%d) Okay, your coefficients \n  coeff_a = %.2f\n  coeff_b = %.2f\n  coeff_c = %.2f.\nThat's right?\nWrite \"yes\" \
if everything is correct, \"no\" if you want to change the coefficients.\n",*operation_number, *coeff_a , *coeff_b, *coeff_c);
        char changing_coefficients[4];
        scanf("%s", changing_coefficients);

        if(strlen(changing_coefficients) == 3)
        {
            ++(*operation_number);
            printf("(%d) We continue.\n",*operation_number);
        }

        if(strlen(changing_coefficients) == 2)
        {
            ++(*operation_number);
            printf("(%d) Change the coefficients.\n",*operation_number);
            ++(*operation_number);
            printf("(%d) Enter the other coefficients of the quadratic equation \"coeff_a\",\"coeff_b\",\"coeff_c\"\
in this sequence.\n",*operation_number);
            input ( coeff_a, coeff_b,  coeff_c);
        }

        ++(*operation_number);
        printf("(%d) Okay, we hope you entered everything correctly.\n",*operation_number);
        ++(*operation_number);
        printf("(%d) Getting to the solution.\n",*operation_number);

    return 0;
 }


void conclusion ( enum number_roots nRoots, float root1, float root2)
 {

    switch (nRoots)
        {
        case ZERO:  printf("* No roots\n");
                 break;
        case ONE:  printf("* Answer: %f\n", root1);
                 break;
        case TWO:  printf("* Answer: x1 = %.2f\n          x2 = %.2f\n", root1, root2);
                 break;
        case INFINITYY:  printf("* Any number\n");
                            break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
        }
 }































