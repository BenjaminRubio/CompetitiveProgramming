#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

struct Node
{
    ll v, m, lzv = 0;
    bool lz = false;
    Node() : v(0), m(0) {}
    Node(ll x) : v(x), m(x) {}
    Node(const Node &a, const Node &b) : v(a.v + b.v), m(min(a.m, b.m)) {}
    Node(ll x, ll i, ll j, const Node &b) { v = (ll)(j - i + 1) * x; m = x; }
};

template <class node>
struct STL
{
    vector<node> st; ll n;

    void build(ll u, ll i, ll j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    void push(ll u, ll i, ll j, ll x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        st[u * 2 + 1].lz = 1, st[u * 2 + 1].lzv = x;
        st[u * 2 + 2].lz = 1, st[u * 2 + 2].lzv = x;
    }
    node query(ll a, ll b, ll u, ll i, ll j)
    {
        if (j < a || b < i) return node();
        ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(ll a, ll b, ll v, ll u, ll i, ll j)
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }
    ll find(ll k)
    {
        ll i = 0, j = n - 1, u = 0;
        while (i < j)
        {
            ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
            if (st[u].lz) push(u, i, j, st[u].lzv);
            if (st[l].lz) push(l, i, m, st[l].lzv);
            if (st[l].m <= k) j = m, u = l;
            else i = m + 1, u = r;
        }
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (st[u].m > k) return n;
        return i;
    }
    ll upper(ll k)
    {
        ll i = 0, j = n - 1, u = 0;
        if (st[u].v <= k) return n;
        while (i < j)
        {
            ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
            if (st[u].lz) push(u, i, j, st[u].lzv);
            if (st[l].lz) push(l, i, m, st[l].lzv);
            if (st[l].v > k) j = m, u = l;
            else k -= st[l].v, i = m + 1, u = r;
        }
        if (st[u].lz) push(u, i, j, st[u].lzv);
        return i;
    }

    STL(vector<node> &v, ll N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(ll a, ll b) { return query(a, b, 0, 0, n - 1); }
    void update(ll a, ll b, ll v) { update(a, b, v, 0, 0, n - 1); }
};

ll N, Q, a, t, x, y;
vector<Node> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;

    A.resize(N);
    rep(i, N) { cin >> a; A[i] = Node(a); }

    STL<Node> stl(A, N);

    rep(_, Q)
    {
        cin >> t >> x >> y; x--;
        if (t == 1)
        {
            ll l = stl.find(y);
            stl.update(l, x, y);
        }
        if (t == 2)
        {
            ll ans = 0;
            while (x < N)
            {
                ll z = y, l;
                x = max(x, stl.find(z));
                if (x < N)
                {
                    if (x > 0) z += stl.query(0, x - 1).v;
                    l = stl.upper(z);
                    if (l > x) y -= stl.query(x, l - 1).v, ans += l - x;
                    assert(y >= 0);
                    x = l;
                }
            }

            cout << ans << '\n';
        }
    }
}