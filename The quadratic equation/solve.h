 int SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2);
 float is_equal (float a, float b);
 float Comparison_more(float a, float b);
 float Comparison_less(float a, float b);





int SolveSquare (float coeff_a, float coeff_b, float coeff_c, float *root1, float *root2)
 {
    if (!is_equal(coeff_a,0)) // quadratic
    {
        float discriminant = coeff_b * coeff_b - 4 * coeff_a * coeff_c;

        if(Comparison_more(discriminant,0))
        {


            *root1 = (-coeff_b + sqrtf(discriminant)) / (2 * coeff_a);
            *root2 = (-coeff_b - sqrtf(discriminant)) / (2 * coeff_a);
            return 2;
        }

        else if(is_equal(discriminant,0))
        {
            *root1 = -coeff_b / (2 * coeff_a);
            return 1;
        }

        else if (Comparison_less(discriminant,0))
        {
            return 0;
        }

    }

    else // linear
    {

        if(is_equal(coeff_b,0))
        {

            if(is_equal(coeff_c,0))
            {
                return -5;
            }

            else if (!is_equal(coeff_c,0))
            {
                return 0;
            }
        }

        else
        {
            *root1 = - coeff_c / coeff_b;
            return 1;
        }

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



