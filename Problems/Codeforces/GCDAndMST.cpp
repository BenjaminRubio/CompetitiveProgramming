#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

struct GCD
{
    ll v;
    GCD() { v = -1; }
    GCD(ll v) : v(v) {}
    GCD(const GCD &a, const GCD &b)
    {
        if (a.v == -1) v = b.v;
        else if (b.v == -1) v = a.v;
        else v = __gcd(a.v, b.v);
    }
};

template <class node>
struct ST
{
    vector<node> t; ll n;

    ST(vector<node> &arr, ll N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (ll i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(ll p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(ll l, ll r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

ll T, N, P;
vector<ll> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> P;

        ll ans = P * (N - 1ll);

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

        A.resize(N);
        rep(i, N) { cin >> A[i]; Q.emplace(A[i], i); }

        vector<GCD> g(N);
        rep(i, N) g[i] = GCD(A[i]);

        ST<GCD> stlgcd(g, N);

        set<int> SS;
        rep(i, N) SS.insert(i);

        while (!Q.empty() && Q.top().first < P)
        {
            ll e = Q.top().first, p = Q.top().second;
            Q.pop();

            int l = 0, r = p;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (stlgcd.query(m, p + 1).v == e) r = m;
                else l = m + 1;
            }

            int i = l;

            l = p, r = N;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (stlgcd.query(p, m + 1).v < e) r = m;
                else l = m + 1;
            }

            int j = l;

            auto itl = SS.lower_bound(i + 1);
            auto itr = SS.lower_bound(j);

            for (auto it = itl; it != itr; it++) ans -= (P - e);

            SS.erase(itl, itr);
        }

        cout << ans << '\n';
    }
}