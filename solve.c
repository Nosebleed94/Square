#include "solve.h"
#include "Testing.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>

enum number_roots SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2)
 {
    assert (isfinite(coeff_a));
    assert (isfinite(coeff_b));
    assert (isfinite(coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);
    if (!is_equal(coeff_a,0)) // quadratic
    {
        return quadratic( coeff_a,  coeff_b, coeff_c,  root1,  root2);
    }

    else // linear
    {
        return linear ( coeff_a, coeff_b, coeff_c, root1, root2);
    }
 }

 float is_equal (float a, float b)
 {
    float e = 0.00001f;  ///////////////////////////////!
    if (fabsf(a-b) < e)
        return 1;
    else
        return 0;
 }


 float Comparison_more(float a, float b)
{
    float e = 0.00001;
    if((a - b) > e)
        return 1;
    else
        return 0;
}


float Comparison_less(float a, float b)
{
    float e = 0.00001;
    if((a-b) < -e)
        return 1;
    else
        return 0;
}

float linear (float coeff_a, float coeff_b,float coeff_c,float *root1,float *root2)
{
    assert (isfinite(coeff_a));
    assert (isfinite(coeff_b));
    assert (isfinite(coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);
    if(is_equal(coeff_b,0))
        {

            if(is_equal(coeff_c,0))
            {
                return INFINITYY;
            }

            else
            {
                return ZERO;
            }
        }
    else
        {
            *root1 = - coeff_c / coeff_b;
            return ONE;
        }

}

float quadratic(float coeff_a, float coeff_b,float coeff_c, float *root1, float *root2)
{
    assert (isfinite(coeff_a));
    assert (isfinite(coeff_b));
    assert (isfinite(coeff_c));
    assert (root1 != NULL);
    assert (root2 != NULL);

    float discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

        if(Comparison_more(discriminant,0))
        {
            *root1 = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            *root2 = (-coeff_b - sqrtf(discriminant)) / (2 * coeff_a);
            return TWO;
        }

        else if(is_equal(discriminant,0))
        {
            *root1 = -coeff_b / (2 * coeff_a);
            return ONE;
        }

        else
        {
            return ZERO;
        }

}





