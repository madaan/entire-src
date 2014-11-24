//sg
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector< vector<int> > vvi;
typedef vector<string> vs;

vvi get_subsets(vi v, int size)
{
    if(size==0) return vvi(1);
    vvi subsets = get_subsets(v,size-1);

    vvi more_subsets(subsets);

    for(auto it = more_subsets.begin(); it !=more_subsets.end(); it++)
    {
        (*it).push_back(v[size-1]);
    }

    subsets.insert(subsets.end(), (more_subsets).begin(), (more_subsets).end());
    return subsets;
}
long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
  return (a*b)/gcd(a,b);
}

long long lcm_v(vi vec) {
    long long ans = vec[0];
    for(size_t i = 1; i < vec.size(); i++) {
        ans = lcm(ans, vec[i]);
    }
    return ans;
}

long long countUneatenLeaves(int N, vector < int > A) {
    vvi ssets = get_subsets(A, A.size());
    long long ans = 0;
    for(long long i = 0, l = ssets.size(); i < l; i++) {
        if(ssets[i].size() <= 0) continue;
        ans += (N / lcm_v(ssets[i])) * (pow(-1, ssets[i].size() - 1)); 
    }
    return N - ans;
}

int main() {
  long long arr[] = {2, 4, 5};
    vector<long long> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << countUneatenLeaves(10, vec) << "\n";
   return 0;
}
