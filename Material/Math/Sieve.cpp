#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template<int SZ> struct Sieve
{ 
    bitset<SZ> I; vector<int> P;
    Sieve()
    {
        I.set();
        for (int i = 2; i * i < SZ; i++) if (I[i])
            for (int j = i * i; j < SZ; j += i) I[j] = 0;
        rep(i, SZ) if (i > 1 && I[i]) P.push_back(i);
    }
};

Sieve<320000> S;
