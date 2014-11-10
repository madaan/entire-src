//sg
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
using namespace std;
double wc(char * str)
{
    int l = strlen(str);
    int insCount[200] = {0};
    int den[500] = {0};
    int dcntr = 0;
    double num = 1, d = 1;
    double div = 1000000007;
    for (int i = 0; i < l; i++)
    {
        insCount[str[i]]++;
        if (insCount[str[i]] > 1) { //found this one twice,will generate a denominator
            den[dcntr++] = insCount[str[i]];
        }
    }
    for (int i = 2; i <= l; i++) {
        num *= i;
        if (dcntr > 0) {
            d *= den[--dcntr];
        }
        if (d != 1) {
            num /= d;
            d = 1;
            // num=fmod(num,div);
        }
    }
    return fmod(num, div);
}
main()
{
    int n, n1;
    n1 = n;
    scanf("%d", &n);
    char str[500];
    double res[500];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        res[i] = wc(str);
    }
    for (int i = 0; i < n; i++) {
        printf("%.0f\n", res[i]);
    }
}