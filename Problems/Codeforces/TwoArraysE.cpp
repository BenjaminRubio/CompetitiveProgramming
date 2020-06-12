#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

struct Node
{
    ll v;
    Node() { v = LLONG_MAX; }
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b)
    {
        v = min(a.v, b.v);
    }
};

template <class node>
class ST
{
    vector<node> t;
    int n;

public:
    ST(vector<node> &arr)
    {
        n = arr.size();
        t.resize(n * 2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i)
            t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set_point(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1; )
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
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

const ll MOD = 998244353;

ll n, m, x;
vector<Node> a;
vector<ll> b;

int main()
{
    cin >> n >> m;

    map<ll, vector<ll>> mp;
    rep(i, n)
    {
        cin >> x;
        a.emplace_back(x);
        mp[x].push_back(i);
    }

    b.resize(m);
    rep(i, m) cin >> b[i];

    ST<Node> st(a);

    ll ans = 1;
    repx(i, 1, m)
    {
        ll l = n, r, cnt = 0;
        for (ll j : mp[b[i]])
            if (st.query(j, n).v == b[i]) cnt++, l = min(l, j), r = j + 1;
        if (cnt) ans = ((ll) ans * (r - l)) % MOD;
        else ans = 0;
    }

    if (st.query(0, n).v < b[0]) ans = 0;
    cout << ans << '\n';
}