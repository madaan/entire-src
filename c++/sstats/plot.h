//sg
#include <iostream>
#include <string>

class Plotter
{
    public:
       static void plot(double *a, int l, char d = ' ');
       static void labelledPlot(double *a, std::string label[3], int l, char = ' ');
};

