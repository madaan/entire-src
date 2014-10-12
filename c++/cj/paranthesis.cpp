//sg
#include<bits/stdc++.h>
using namespace std;
# define MAX_SIZE 100
 
void _printParenthesis(int pos, int n, int open, int close);
 
/* Wrapper over _printParenthesis()*/
void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}     
 
int printed = 0;
int lim;
void _printParenthesis(int pos, int n, int open, int close)
{
  static char str[MAX_SIZE];     
 
  if(close == n) 
  {
    printed++;
    if(printed == lim) printf("%s \n", str);
    return;
  }
  else
  {
    if(open < n) {
       str[pos] = '(';
       _printParenthesis(pos+1, n, open+1, close);
    }
    if(open > close) {
        str[pos] = ')';
        _printParenthesis(pos+1, n, open, close+1);
    }
  }
}
 
/* driver program to test above functions */
int main()
{
  int t;
  int n, k;
  cin >> t;
  for(int qq = 1; qq <= t; qq++) {
      cin >> n >> k;
      lim = k;
        printParenthesis(n);
  }
  return 0;
}
