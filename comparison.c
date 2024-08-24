#include "comparison.h"

#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "solve.h"
#include "working_with_the_user.h"
#include "Testing.h"


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

float is_equal (float a, float b)
 {
    const float e = 0.00001f;
    /*if (fabsf(a - b) < e)
        return 1;
    else
        return 0; */
    return (fabs(a - b) < e) ? 1 : 0;
 }

float Comparison_more(float a, float b)
{
    const float e = 0.00001f;
    /*if((a - b) > e)
        return 1;
    else
        return 0; */
    return ((a - b) > e) ? 1 : 0;
}

float Comparison_less(float a, float b)
{
    const float e = 0.00001f;
   /* if((a-b) < -e)
        return 1;
    else
        return 0; */
    return ((a - b) < -e) ? 1 : 0;
}







