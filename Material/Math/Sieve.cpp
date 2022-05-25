#include "../Template.cpp"

template<int SZ> struct Sieve
{ 
    bitset<SZ> I; vi P;
    Sieve()
    {
        I.set();
        for (int i = 2; i * i < SZ; i++) if (I[i])
            for (int j = i * i; j < SZ; j += i) I[j] = 0;
        rep(i, SZ) if (i > 1 && I[i]) P.pb(i);
    }
};

Sieve<320000> S;
