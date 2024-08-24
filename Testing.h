#ifndef TESTING_H
#define TESTING_H
#include "solve.h"


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

void All_Tests();

/**
*@brief Checks whether the expected answers and the answers that the program has given have converged
*/
int test_start(struct testing data);

#endif // TESTING_H

