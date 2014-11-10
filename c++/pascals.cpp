// A simple O(n^3) program for Pascal's Triangle
#include <stdio.h>

// See http://www.geeksforgeeks.org/archives/25621 for details of this function
int binomialCoeff(int n, int k);

// Function to print first n lines of Pascal's Triangle
void printPascal(int n)
{
    // Iterate through every line and print entries in it
    int even, odd;
    for (int line = 0; line < n; line++)
    {
        // Every line has number of integers equal to line number
        even = odd = 0;
        for (int i = 0; i <= line; i++) {
            if(binomialCoeff(line, i) % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        printf("%d. %d %d\n", line, even, odd);
    }
}

// See http://www.geeksforgeeks.org/archives/25621 for details of this function
int binomialCoeff(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Driver program to test above function
int main()
{
    int n = 200;
    printPascal(n);
    return 0;
}
