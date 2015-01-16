
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
