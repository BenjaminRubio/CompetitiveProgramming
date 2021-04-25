
const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y, ll M = MOD) { return (x + y) % M; }
inline ll mul(ll x, ll y, ll M = MOD) { return (x * y) % M; }

ll binPow(ll a, ll b, const ll M)
{
    if (b == 0) return 1;
    ll r = binPow(a, b / 2, M); r = mul(r, r, M);
    return (b & 1) ? mul(r, a, M) : r;
}

// If multiplication goes over ll

ul modMul(ul a, ul b, const ul M)
{
    ll r = a * b - M * (ul)((db)a * b / M);
    return r + ((r < 0) - (r >= (ll)M)) * M;
}

ul modPow(ul a, ul b, const ul M)
{
    if (b == 0) return 1;
    ul r = modPow(a, b / 2, M); r = modMul(r, r, M);
    return b & 1 ? modMul(r, a, M) : r;
}
