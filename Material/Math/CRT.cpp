#include <Euclid.cpp>

pl CRT(pl a, pl b)
{
    if (a.ss < b.ss) swap(a, b);
    ll x, y; tie(x, y) = euclid(a.ss, b.ss); 
    ll g = a.ss * x + b.ss * y, l = a.ss / g * b.ss;
    if ((b.ff - a.ff) % g) return {-1, -1}; // no solution
    x = (b.ff - a.ff) % b.ss * x % b.ss / g * a.ss + a.ff; 
    return {x + (x < 0) * l, l};
}

pl CRT(vector<pl> &v)
{
    int N = v.size(); pl ans = v[0];
    rep(i, N) if (i) ans = CRT(ans, v[i]);
    return ans;
}
