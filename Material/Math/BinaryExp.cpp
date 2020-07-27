#include <bits/stdc++.h>
using namespace std;

int binexp(int b, int p, int M)
{
    b %= M;
    int ans = 1;
    while (p > 0)
    {
        if (p & 1) ans = (ans * b) % M;
        b = (b * b) % M;
        p >>= 1;
    }
    return ans;
}