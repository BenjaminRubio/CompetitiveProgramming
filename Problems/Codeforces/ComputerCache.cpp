#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef long long ll;

struct SUM
{
    static ll const neutro = 0;
    static ll op(ll x, ll y) { return x + y; }
    static ll lazy_op(int i, int j, ll x) { return x * (j - i + 1); }
};

template <class t>
class STLSUM
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        st[u] += t::lazy_op(i, j, x);
        if (i != j)
        {
            lazy[u * 2 + 1] += x;
            lazy[u * 2 + 2] += x;
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, ll value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

public:
    STLSUM(vector<ll> &v)
    {
        arr = v; n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

template <class t>
class STLSET
{
    vector<ll> arr, st, lazy;
    int n;

    void build(int u, int i, int j)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m); build(r, m + 1, j);
        st[u] = t::op(st[l], st[r]);
    }

    void propagate(int u, int i, int j, ll x)
    {
        st[u] = t::lazy_op(i, j, x);
        if (i != j)
        {
            lazy[u * 2 + 1] = x;
            lazy[u * 2 + 2] = x;
        }
        lazy[u] = 0;
    }

    ll query(int a, int b, int u, int i, int j)
    {
        if (j < a or b < i) return t::neutro;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) return st[u];
        ll x = query(a, b, l, i, m);
        ll y = query(a, b, r, m + 1, j);
        return t::op(x, y);
    }

    void update(int a, int b, ll value, int u, int i, int j)
    {
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (lazy[u]) propagate(u, i, j, lazy[u]);
        if (a <= i and j <= b) propagate(u, i, j, value);
        else if (j < a or b < i) return;
        else
        {
            update(a, b, value, l, i, m);
            update(a, b, value, r, m + 1, j);
            st[u] = t::op(st[l], st[r]);
        }
    }

public:
    STLSET(vector<ll> &v)
    {
        arr = v; n = v.size();
        st.resize(n * 4 + 5);
        lazy.assign(n * 4 + 5, 0);
        build(0, 0, n - 1);
    }

    ll query(int a, int b) { return query(a, b, 0, 0, n - 1); }

    void update(int a, int b, ll value) { update(a, b, value, 0, 0, n - 1); }
};

int N, M, Q, t, i, p, l, r;
vector<int> S;
vector<STLSUM<SUM>> stl;
vector<queue<pair<int, int>>> U;
vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> V;

int main()
{
    cin >> N >> M >> Q;

    S.resize(M);
    rep(i, M)
    {
        cin >> S[i];
        vector<ll> aux(S[i]);
        rep(k, S[i]) cin >> aux[k];
        stl.emplace_back(aux);
    }

    vector<ll> init(N, 0);
    STLSET<SUM> arr(init);

    vector<int> ans;
    int id1 = 1, id2 = 0;
    vector<pair<int, pair<int, int>>> prev;
    vector<int> poss;
    U.resize(M);
    V.resize(M);
    rep(_, Q)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> i >> p; i--, p--;
            prev.emplace_back(i, make_pair(U[i].size(), p));
            arr.update(p, p + S[i] - 1, id1++);
        }
        if (t == 2)
        {
            cin >> p; p--;
            int look = arr.query(p, p);
            ans.push_back(0);
            poss.push_back(0);
            id2++;
            if (look == 0) continue;
            int pos = p - prev[look - 1].second.second;
            poss[id2 - 1] = pos;
            V[prev[look - 1].first].emplace(prev[look - 1].second.first, id2 - 1);
            // cerr << "aaa\n";
        }
        if (t == 3)
        {
            cin >> i >> l >> r; i--, l--, r--;
            U[i].emplace(l, r);
        }
    }

    rep(i, M)
    {
        int curr = 0;
        while (!V[i].empty())
        {
            t = V[i].top().first, id1 = V[i].top().second; V[i].pop();

            // cerr << id1 << ' ' << t << '\n';

            while (curr < t)
            {
                l = U[i].front().first, r = U[i].front().second; U[i].pop();
                stl[i].update(l, r, 1);
                curr++;
            }

            ans[id1] = stl[i].query(poss[id1], poss[id1]) % 256;
        }
    }

    for (int a : ans) cout << a << '\n';
}