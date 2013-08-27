#include <stdio.h>
#include <math.h>
#include  "arith.h"

float *sqrt_1(int *opn, CLIENT *req)
{
    float res = sqrt(*opn);
    return &res;
}
