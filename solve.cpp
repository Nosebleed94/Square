#include "solve.h" 

#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "working_with_the_user.h"
#include "comparison.h"


enum number_roots Solve_Square (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2)
 {
    assert (isfinite (coeff_a));
    assert (isfinite (coeff_b));
    assert (isfinite (coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);

    return !Is_Equal   (coeff_a, 0)
           ? Quadratic (coeff_a,  coeff_b, coeff_c,  root1,  root2)
           : Linear    (coeff_a, coeff_b, coeff_c, root1, root2);
 }

enum number_roots Linear (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2)
{
    assert (isfinite (coeff_a));
    assert (isfinite (coeff_b));
    assert (isfinite (coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);

    if (Is_Equal (coeff_b,0))
    {
        return (Is_Equal (coeff_c,0)) ? INFINITYY : ZERO;
    }
    else
    {
        *root1 = - coeff_c / coeff_b;
        return ONE;
    }
}

enum number_roots Quadratic (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2)
{
    assert (isfinite (coeff_a));
    assert (isfinite (coeff_b));
    assert (isfinite (coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);

    float discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

    if (Comparison_More (discriminant, 0))
    {
        *root1 = (-coeff_b + sqrtf (discriminant)) / (2 * coeff_a);
        *root2 = (-coeff_b - sqrtf (discriminant)) / (2 * coeff_a);
        return TWO;
    }
    else if (Is_Equal (discriminant, 0))
    {
        *root1 = -coeff_b / (2 * coeff_a);
        return ONE;
    }
    else
    {
        return ZERO;
    }
}





