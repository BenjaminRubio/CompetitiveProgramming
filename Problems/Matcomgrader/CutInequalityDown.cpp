#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

template <class t>
class ST
{
    ll n;
    vector<ll> memo, *arr;

public:
    ST(vector<ll> &_arr)
    {
        arr = &_arr; n = arr->size();
        ll maxlog = 31 - __builtin_clz(n);
        memo.assign(n * (maxlog + 1), -1);
    }
    ll dp(ll i, ll e)
    {
        ll &ans = memo[e * n + i];
        if (ans != -1) return ans;
        if (e == 0) return ans = (*arr)[i];
        return ans = t::merge(dp(i, e - 1), dp(i + (1ll << (e - 1)), e - 1));
    }

    ll query(ll l, ll r)
    {
        ll e = 31 - __builtin_clz(r - l + 1);
        return t::merge(dp(l, e), dp(r - (1ll << e) + 1, e));
    }
};

struct MIN
{
    static const ll neutro = LLONG_MAX;
    static ll merge(ll x, ll y) { return min(x, y); }
};

struct MAX
{
    static const ll neutro = LLONG_MIN;
    static ll merge(ll x, ll y) { return max(x, y); }
};

class STN
{
    ll n;
    vector<pair<ll, ll>> memo, *arr[2];

public:
    STN(vector<pair<ll, ll>> &_arr1, vector<pair<ll, ll>> &_arr2)
    {
        arr[0] = &_arr1; arr[1] = &_arr2; n = arr[0]->size();
        memo.assign(n * (31 + 1), {-1, -1});
    }
    pair<ll, ll> dp(ll p, ll i, ll e)
    {
        pair<ll, ll> &ans = memo[e * n + i];
        if (ans.ff != -1) return ans;
        if (e == 0) return ans = (*arr[p])[i];
        return ans = dp(dp(p, i, e - 1).ss, dp(p, i, e - 1).ff, e - 1);
    }

    pair<ll, ll> query(ll p, ll l, ll r)
    {
        for (ll i = 31; i >= 0; i--) if (dp(p, l, i).ff <= r)
            tie(l, p) = dp(p, l, i);
        return {l, p};
    }
};

ll N, L, U, Q, B, E, X;
vector<ll> S;
vector<pair<ll, ll>> Nx[2];

pair<ll, ll> next_dw(ll i, ll v, ST<MIN> &st)
{
    ll l = i + 1, r = N + 1;
    while (l < r)
    {
        ll m = (l + r) / 2;
        if (st.query(i + 1, m) - S[i] + v < L) r = m;
        else l = m + 1;
    }
    return {l, 0};
}

pair<ll, ll> next_up(ll i, ll v, ST<MAX> &st)
{
    ll l = i + 1, r = N + 1;
    while (l < r)
    {
        ll m = (l + r) / 2;
        if (st.query(i + 1, m) - S[i] + v > U) r = m;
        else l = m + 1;
    }
    return {l, 1};
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> L >> U;

    S.assign(N + 1, 0);
    rep(i, N) { cin >> X, S[i + 1] = S[i] + X; }

    ST<MAX> stM(S); ST<MIN> stm(S);

    Nx[0].assign(N + 2, {N + 1, 1}); Nx[1].assign(N + 2, {N + 1, 1});
    rep(i, N)
    {
        Nx[0][i] = min(next_up(i, L, stM), next_dw(i, L, stm));
        Nx[1][i] = min(next_up(i, U, stM), next_dw(i, U, stm));
    }

    STN stn(Nx[0], Nx[1]);

    cin >> Q;
    rep(_, Q)
    {
        cin >> B >> E >> X; B--;
        pair<ll, ll> nx = min(next_up(B, X, stM), next_dw(B, X, stm));
        if (nx.ff <= E)
        {
            nx = stn.query(nx.ss, nx.ff, E);
            B = nx.ff, X = nx.ss ? U : L;
        }
        cout << S[E] - S[B] + X << '\n';
    }
}