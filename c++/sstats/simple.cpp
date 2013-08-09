//sg
#include <iostream>
#include <map>
#include "simple.h"
using namespace std;
SimpleStats::SimpleStats(double *arr){
    this -> arr = arr;
    l = sizeof(arr) / sizeof(double);
    cout << " l = " << l << endl;
} 

 double SimpleStats::mean(double *arr, int l)
{
    double sum = 0;
    for(int i = 0;i < l; i++) {
       sum += arr[i];
    }
    return static_cast<double>(sum) / l;
}

 double SimpleStats::mode(double *arr, int l)
{
    std::map<double, int> counter;
    int * freq = new int[l];
    for(int i = 0;i < l; i++) {
        counter[arr[i]]++;
    }
    double max = counter[counter.begin() -> first];
    for(map<double, int>::iterator it= counter.begin();it != counter.end(); it++) {
        if(it -> second > max) {
            max = it -> first;
        }
    }
    return max;
}

     double SimpleStats::median(double *arr, int l) 
    {
        //The good old insertion sort
        double temp;
        for(int i = 1;i < l;i++) {
            int j = i - 1;
            while(j >= 0 && arr[j + 1] > arr[j]) {
               temp = arr[j];
               arr[j] = arr[j + 1];
               arr[j + 1] = temp;
               j--;
            }
        }
        if(l % 2 == 0) { //even
            return (arr[l / 2] + arr[l/2 + 1]) / 2;
        } else {
            return arr[l / 2];
        }
    }

