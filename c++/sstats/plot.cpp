//sg
#include <iostream>
#include "plot.h"
using namespace std;
void Plotter::plot(double *a, int l, char sep)
{
    cout << "\n";
    for(int i = 0; i < l; i++) {
        cout << " | " << i << "\t";
        for(int j = 0; j < a[i];j++) {
           cout << sep;
        }
       cout <<"# " << a[i] << "\n |\n";
    }
};

void Plotter::labelledPlot(double *a, std::string label[3], int l, char sep)
{
    cout << "\n";
    for(int i = 0; i < l; i++) {
        cout << " | " << label[i] << "\t";
        for(int j = 0; j < a[i];j++) {
           cout << sep;
        }
       cout <<"# " << a[i] << "\n\n";
    }
};
