
enum number_roots
 {
  ZERO = 0,
  ONE = 1,
  TWO = 2,
  INFINITYY = -5,
 };
void All_Tests();
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



/**
*@brief Checks whether the expected answers and the answers that the program has given have converged
*/
int test_start(struct testing data);
