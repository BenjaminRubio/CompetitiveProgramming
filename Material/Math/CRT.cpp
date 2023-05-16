#include "../Template.cpp"
#include "Euclid.cpp"

pll CRT(pll a, pll b)
{
    if (a.ss < b.ss) swap(a, b);
    ll x, y; tie(x, y) = euclid(a.ss, b.ss); 
    ll g = a.ss * x + b.ss * y, l = a.ss / g * b.ss;
    if ((b.ff - a.ff) % g) return {-1, -1}; // no solution
    x = (b.ff - a.ff) % b.ss * x % b.ss / g * a.ss + a.ff; 
    return {x + (x < 0) * l, l};
}

pll CRT(vector<pll> &v)
{
    pll ans = v[0];
    rep(i, sz(v)) if (i) ans = CRT(ans, v[i]);
    return ans;
}
