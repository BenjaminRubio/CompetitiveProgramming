
int LIS(vi &v)
{
    vi L; int S = 0;
    for(int x : v)
    {
        int i = upper_bound(all(L), x) - L.begin();
        if(i == S) L.pb(x), S++;
        else L[i] = x;
    }
    return S;
}
