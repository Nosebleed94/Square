/**@file*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <assert.h>
#include "Testing.h"
#include "solve.h"

#define SS_INF_ROOTS -5

#define VARIABLES 19



/**
*@brief Sorts in ascending order the roots that the program receives for comparison with the expected roots
*/
void sort (float *root1, float *root2);

int main()
{
    int operation_number = 1;
    char continuation_stop [3];
    float coeff_a = 0;
    float coeff_b = 0;
    float coeff_c = 0;
    float root1 = 0;
    float root2 = 0;

    Beep(440,1000);

    All_Tests();

    printf("(%d) Hi, this program solves a quadratic equation. Enter \"!\" to stop the program or \"go\" to continue!\n", operation_number);
    scanf("%s", continuation_stop);
    while(strlen(continuation_stop) != 1)

    {

        filing_main(&operation_number, &coeff_a, &coeff_b, &coeff_c);
        enum number_roots nRoots = SolveSquare (coeff_a, coeff_b, coeff_c, &root1, &root2 ); //


        conclusion ( nRoots,  root1,  root2);
        ++operation_number;
        printf("(%d) write \"!\" to stop and \"go\" to continue! \n",operation_number);
        scanf("%s", continuation_stop);


   }
   ++operation_number;
   Beep(440,1000);
   printf("(%d) Thank you for using this program!\n",operation_number);
   return 0;
}

void sort (float *root1, float *root2)
{
    assert (root1 != NULL);
    assert (root2 != NULL);
    float helper = 0;
    if (*root1 > *root2)
    {
      helper = *root1;
      *root1 = *root2;
      *root2 = helper;
    }
}

