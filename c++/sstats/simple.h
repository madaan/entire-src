#ifndef SIMPLE
#define SIMPLE
//sg
#include <iostream>
#include <map>
using namespace std;
class SimpleStats
{
    double *arr;
    int l;
    public:
    SimpleStats(double *arr);
    static double mean(double *arr, int l);
    static double mode(double *arr, int l);
    static double median(double *arr, int l); 
};
#endif
