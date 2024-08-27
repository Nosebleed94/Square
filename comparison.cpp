#include "comparison.h"  

#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "working_with_the_user.h"
#include "Testing.h"


void Sort (float *root1, float *root2)
{
    assert (root1 != NULL);
    assert (root2 != NULL);

    if (*root1 > *root2)
    {
        float helper = 0;
        helper = *root1;
                 *root1 = *root2;
                          *root2 = helper;
    }
}

float Is_Equal (float a, float b)
{
    const float e = 0.00001f;
    return (fabs (a - b) < e) ? 1 : 0;
}

float Comparison_More (float a, float b)
{
    const float e = 0.00001f;
    return ((a - b) > e) ? 1 : 0;
}

float Comparison_Less (float a, float b)
{
    const float e = 0.00001f;
    return ((a - b) < -e) ? 1 : 0;
}







