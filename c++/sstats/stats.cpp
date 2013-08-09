//sg
#include "plot.h"
#include "simple.h"
#include <string>
#include <stdlib.h>
int main()
{
    double data[10];
    for(int i = 0; i < 10; i++){
        data[i] = rand() % 10;
    }

    double res[3];
    res[0] = SimpleStats::mean(data, 10);
    res[1] = SimpleStats::median(data, 10);
    res[2] = SimpleStats::mode(data, 10);
    std::string labels[3] = {"mean  ", "median", "mode  "};
    Plotter::plot(data, 10, '=');
    Plotter::labelledPlot(res, labels, 3, '-');

    return 0;
}

        

