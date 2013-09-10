//sg
#include <stdio.h>
#include <math.h>
double prob(int x, double sigma, double u) {

   double pi = 3.141529;
   double powterm = (.5) * (((x - u) * (x - u)) / (sigma * sigma));
   double px = 
        (1 / (sqrt(2 * pi) * sigma)) * exp(-powterm);
    return px;
}
