/**@file*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <assert.h>

#include "solve.h"

#define SS_INF_ROOTS -5

#define VARIABLES 19



void All_Tests();
/**
*@brief Structure with coefficients, expected answers, expected number of answer
*/
typedef struct testing
{
    int nTest;
    float coeff_a, coeff_b, coeff_c;
    float root1expected, root2expected;
    enum number_roots nRootsExpected;
} testing;

/**
*@brief Counts the number of errors found by struct testing
*/
int start_verification();

/**
*@brief Checks whether the expected answers and the answers that the program has given have converged
*/
int test_start(struct testing data);

/**
*@brief Introduces coefficients
*/
void input (float *coeff_a,  float *coeff_b, float *coeff_c);

/**
*@brief Displays the answers
*/
void conclusion ( int nRoots, float root1, float root2);

/**
*@brief Sorts in ascending order the roots that the program receives for comparison with the expected roots
*/
void sort (float *root1, float *root2);

/**
*@brief The main body of the main function
*/
int filing_main(int *operation_number, float *coeff_a, float *coeff_b, float *coeff_c);



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

void All_Tests()
{
    int sum = 0;
    const int nTests = 19;
    struct testing data [19] =
                                {{1,  1,      5,    6,    -3,             -2,       TWO},
                                {2,  1,      4,    4,    -2,               0,       ONE},
                                {3,  1,      4,    8,     0,               0,       ZERO},
                                {4,  5,      5,    0,    -1,               0,       TWO},
                                {5,  5,      0,    8,     0,               0,       ZERO},
                                {6,  5,      0,   -5,    -1,               1,       TWO},
                                {7,  0,      5,    5,    -1,               0,       ONE},
                                {8,  0,      0,    5,     0,               0,       ZERO},
                                {9,  0,      5,    0,     0,               0,       ONE},
                                {10, 0,      0,    0,     0,               0,      INFINITYY},
                                {11, 2.3,    2.1, -32,   -4.21437,         3.30133, TWO},
                                {12, 1,      2.2,  1.21, -1.1,             0,       ONE},
                                {13, 1.1,    4.4,  8.8,   0,               0,       ZERO},
                                {14, 5.8,    5.5,  0,    -0.948276,        0,       TWO},
                                {15, 6.7,    0,    7.9,   0,               0,       ZERO},
                                {16, 4.5,    0,   -9.3,  -1.43759,         1.43759, TWO},
                                {17, 0,      5.3,  6.6,  -1.2452830188679, 0,       ONE},
                                {18, 0,      0,    7.798, 0,               0,       ZERO},
                                {19, 0,      6.78, 0,     0,               0,       ONE}};
    int i;
    for( i = 0; i < nTests; i++)
    {
        test_start(data[i]);
        if (test_start (data[i]) == 1)
        sum += test_start (data[i]) ;
    }
    printf ("The number of incorrect answers = %d\n", sum);
}


int test_start(struct testing data)
 {
    float root1 = 0;
    float root2 = 0;


    enum number_roots nRoots =  SolveSquare(data.coeff_a, data.coeff_b, data.coeff_c, &root1, &root2);
    sort (&root1, &root2);
    if(nRoots != data.nRootsExpected || !is_equal(root1,data.root1expected) || !is_equal(root2,data.root2expected))
    {
        printf("Error: %d, coeff_a = %f, coeff_b = %f, coeff_c = %f, root1 = %f, root2 = %f, nRoots = %d\n"
               "Expected nRoots: root1 = %f, root2 = %f, nRoots = %d\n",
               data.nTest, data.coeff_a, data.coeff_b, data.coeff_c, root1, root2, nRoots,
               data.root1expected, data.root2expected, data.nRootsExpected);
               return 1;
    }
    return 0;
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































