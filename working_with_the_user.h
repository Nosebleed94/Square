#ifndef WORKING_WITH_THE_USER_H
#define WORKING_WITH_THE_USER_H

#include "solve.h"

/**
*@brief Introduces coefficients
*/
void Input (float *coeff_a,  float *coeff_b, float *coeff_c);

/**
*@brief Displays the answers
*/
void Conclusion (enum number_roots nRoots, float root1, float root2);


/**
*@brief The main body of the main function
*/
int Filing_Main (int *operation_number, float *coeff_a, float *coeff_b, float *coeff_c);

#endif // WORKING_WITH_THE_USER_H
