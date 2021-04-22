#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template<int SZ> struct Sieve
{ 
    bitset<SZ> I; vector<int> P;
    Sieve()
    {
        I.set(); I[0] = I[1] = 0;
        for (int i = 4; i < SZ; i += 2) I[i] = 0;
        for (int i = 3; i * i < SZ; i += 2) if (I[i])
            for (int j = i*i; j < SZ; j += i*2) I[j] = 0;
        rep(i, SZ) if (I[i]) P.push_back(i);
    }
};

Sieve<320000> S;
