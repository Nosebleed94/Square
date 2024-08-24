#ifndef SOLVE_H
#define SOLVE_H

enum number_roots
{
    ZERO      = 0,
    ONE       = 1,
    TWO       = 2,
    INFINITYY = -5,
};

/**
*@brief Enumerated type for the number of roots of the equation
*/
enum number_roots SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2);

/**
*@brief lenear
*/
enum number_roots linear (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2);

/**
*@brief quadratic
*/
enum number_roots quadratic(float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2);

#endif // SOLVE_H


