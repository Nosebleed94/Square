#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#include "solve.h"

#define SS_INF_ROOTS -5

#define VARIABLES 19

typedef struct testing
{
    int nTest;
    float coeff_a, coeff_b, coeff_c;
    float root1expected, root2expected;
    int nRootsExpected;
} testing;


int start_verification();
int test_start(testing data);




void input (float *coeff_a,  float *coeff_b, float *coeff_c);
void conclusion ( int nRoots, float root1, float root2);
void sort (float *root1, float *root2);
int filing_main(int *operation_number);



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

    start_verification();

    printf("(%d) Hi, this program solves a quadratic equation. Enter \"!\" to stop the program or \"go\" to continue!\n", operation_number);
    scanf("%s", continuation_stop);
    while(strlen(continuation_stop) != 1)

    {

        filing_main(&operation_number);
        int nRoots =  SolveSquare (coeff_a, coeff_b, coeff_c, &root1, &root2 ); //

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
    scanf ("%f%f%f", coeff_a, coeff_b, coeff_c);
 }

 void conclusion ( int nRoots, float root1, float root2)
 {
    switch (nRoots)
        {
        case 0:  printf("* No roots\n");
                 break;
        case 1:  printf("* Answer: %f\n", root1);
                 break;
        case 2:  printf("* Answer: x1 = %.2f\n          x2 = %.2f\n", root1, root2);
                 break;
        case SS_INF_ROOTS:  printf("* Any number\n");
                            break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
        }
}

void sort (float *root1, float *root2)
{
    float helper = 0;
    if (*root1 > *root2)
    {
      helper = *root1;
      *root1 = *root2;
      *root2 = helper;
    }
}

int start_verification()
{
    testing test1 =  {1,  1,      5,    6,    -3,              -2,       2};
    testing test2 =  {2,  1,      4,    4,    -2,               0,       1};
    testing test3 =  {3,  1,      4,    8,     0,               0,       0};
    testing test4 =  {4,  5,      5,    0,    -1,               0,       2};
    testing test5 =  {5,  5,      0,    8,     0,               0,       0};
    testing test6 =  {6,  5,      0,   -5,    -1,               1,       2};
    testing test7 =  {7,  0,      5,    5,    -1,               0,       1};
    testing test8 =  {8,  0,      0,    5,     0,               0,       0};
    testing test9 =  {9,  0,      5,    0,     0,               0,       1};
    testing test10 = {10, 0,      0,    0,     0,               0,      -5};
    testing test11 = {11, 2.3,    2.1, -32,   -4.21437,         3.30133, 2};
    testing test12 = {12, 1,      2.2,  1.21, -1.1,             0,       1};
    testing test13 = {13, 1.1,    4.4,  8.8,   0,               0,       0};
    testing test14 = {14, 5.8,    5.5,  0,    -0.948276,        0,       2};
    testing test15 = {15, 6.7,    0,    7.9,   0,               0,       0};
    testing test16 = {16, 4.5,    0,   -9.3,  -1.43759,         1.43759, 2};
    testing test17 = {17, 0,      5.3,  6.6,  -1.2452830188679, 0,       1};
    testing test18 = {18, 0,      0,    7.798, 0,               0,       0};
    testing test19 = {19, 0,      6.78, 0,     0,               0,       1};
    int sum = 0;

    int start[VARIABLES] =
    {
     (test_start(test1)),
     (test_start(test2)),
     (test_start(test3)),
     (test_start(test4)),
     (test_start(test5)),
     (test_start(test6)),
     (test_start(test7)),
     (test_start(test8)),
     (test_start(test9)),
     (test_start(test10)),
     (test_start(test11)),
     (test_start(test12)),
     (test_start(test13)),
     (test_start(test14)),
     (test_start(test15)),
     (test_start(test16)),
     (test_start(test17)),
     (test_start(test18)),
     (test_start(test19)),
    };

    int variables;
    for(variables = 0; variables < VARIABLES; variables++)
        sum += start[variables];
    printf ("the number of errors: %d\n", sum);
    return 0;

}




int test_start(testing data)
 {
    float root1 = 0;
    float root2 = 0;

    int nRoots =  SolveSquare(data.coeff_a, data.coeff_b, data.coeff_c, &root1, &root2);
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

 int filing_main(int *operation_number)
 {

     float coeff_a = 0;
     float coeff_b = 0;
     float coeff_c = 0;
     char continuation_stop [3];
     ++(*operation_number);
        printf("(%d) Enter the coefficients of the quadratic equation \"coeff_a\", \"coeff_b\", \"coeff_c\" \
in this sequence.\n", *operation_number);

        input ( &coeff_a, &coeff_b,  &coeff_c);


         ++(*operation_number);
        printf("(%d) Okay, your coefficients \n  coeff_a = %.2f\n  coeff_b = %.2f\n  coeff_c = %.2f.\nThat's right?\nWrite \"yes\" \
if everything is correct, \"no\" if you want to change the coefficients.\n",*operation_number, coeff_a , coeff_b, coeff_c);
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
            input ( &coeff_a, &coeff_b,  &coeff_c);
        }

        ++(*operation_number);
        printf("(%d) Okay, we hope you entered everything correctly.\n",*operation_number);
        ++(*operation_number);
        printf("(%d) Getting to the solution.\n",*operation_number);


 }































