#include "Testing.h"

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>

#include "working_with_the_user.h"
#include "solve.h"
#include "comparison.h"


void All_Tests()
{
    int sum = 0;
    const int nTests = 19;
    struct testing data [19] =
                               {{1,  1,      5,    6,    -3,              -2,       TWO},
                                {2,  1,      4,    4,    -2,               0,       ONE},
                                {3,  1,      4,    8,     0,               0,       ZERO},
                                {4,  5,      5,    0,    -1,               0,       TWO},
                                {5,  5,      0,    8,     0,               0,       ZERO},
                                {6,  5,      0,   -5,    -1,               1,       TWO},
                                {7,  0,      5,    5,    -1,               0,       ONE},
                                {8,  0,      0,    5,     0,               0,       ZERO},
                                {9,  0,      5,    0,     0,               0,       ONE},
                                {10, 0,      0,    0,     0,               0,       INFINITYY},
                                {11, 2.3,    2.1, -32,   -4.21437,         3.30133, TWO},
                                {12, 1,      2.2,  1.21, -1.1,             0,       ONE},
                                {13, 1.1,    4.4,  8.8,   0,               0,       ZERO},
                                {14, 5.8,    5.5,  0,    -0.948276,        0,       TWO},
                                {15, 6.7,    0,    7.9,   0,               0,       ZERO},
                                {16, 4.5,    0,   -9.3,  -1.43759,         1.43759, TWO},
                                {17, 0,      5.3,  6.6,  -1.2452830188679, 0,       ONE},
                                {18, 0,      0,    7.798, 0,               0,       ZERO},
                                {19, 0,      6.78, 0,     0,               0,       ONE}};

    for(int i = 0; i < nTests; i++)
    {
        sum += test_start (data[i]);
    }
    printf ("The number of incorrect answers = %d\n", sum);
}

int test_start(struct testing data)
{
    float root1 = 0;
    float root2 = 0;

    enum number_roots nRoots =  SolveSquare(data.coeff_a, data.coeff_b, data.coeff_c, &root1, &root2);
    sort (&root1, &root2);

    if(nRoots != data.nRootsExpected
       || !is_equal(root1,data.root1expected)
       || !is_equal(root2,data.root2expected))
    {
        printf("Error: %d, coeff_a = %f, coeff_b = %f, coeff_c = %f, root1 = %f, root2 = %f, nRoots = %d\n"
               "Expected nRoots: root1 = %f, root2 = %f, nRoots = %d\n",
               data.nTest, data.coeff_a, data.coeff_b, data.coeff_c, root1, root2, nRoots,
               data.root1expected, data.root2expected, data.nRootsExpected);
               return 1;
    }
    return 0;
}

