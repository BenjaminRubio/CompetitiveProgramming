#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

struct Node
{
    int v;
    Node() : v(-1) {}
    Node(int x) : v(x) {}
    Node(const Node &a, const Node &b) : v(max(a.v, b.v)) {}
};

template <class node>
struct ST
{
    vector<node> st; int n;

    void build(int u, int i, int j, vector<node> &arr)
    {
        if (i == j) { st[u] = arr[i]; return; }
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        build(l, i, m, arr), build(r, m + 1, j, arr);
        st[u] = node(st[l], st[r]);
    }
    node query(int a, int b, int u, int i, int j)
    {
        if (j < a || b < i) return node();
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(int p, int v, int u, int i, int j)
    {
        if (j < p || p < i) return;
        int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (i == j) { st[u] = v; return; }
        update(p, v, l, i, m); update(p, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    ST(vector<node> &v, int N) : n(N), st(N * 4 + 5) { build(0, 0, n - 1, v); }
    node query(int a, int b) { return query(a, b, 0, 0, n - 1); }
    void update(int p, int v) { update(p, v, 0, 0, n - 1); }
};

int N, t, x, y, ans;
map<pii, int> mX; map<int, int> m_;
vl T, X, Y;

bool check(int i, int j)
{
    ll x = X[i] - X[j], y = Y[i] - Y[j];
    return (x * x + y * y) < (Y[j] * Y[j]);
}

void search(int id, int p, int u, int i, int j, ST<Node> &st)
{
    if (i > p || st.st[u].v < p) return;
    int m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
    if (i == j && check(id, m_[i])) ans = m_[i] + 1;
    if (i == j) return;
    search(id, p, l, i, m, st); search(id, p, r, m + 1, j, st);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    vector<pair<pii, int>> sX;
    T.resize(N), X.resize(N), Y.resize(N);
    rep(i, N)
    {
        cin >> T[i] >> X[i] >> Y[i];
        if (T[i] == 1) sX.eb(mp(X[i] - Y[i], T[i]), i);
        if (T[i] == 2) sX.eb(mp(X[i], T[i]), i);
    }

    sort(sX.begin(), sX.end());

    int id = 0;
    for (auto &e : sX) mX[mp(e.ff.ff, e.ss)] = id, m_[id] = e.ss, id++;

    vector<Node> v(N);
    ST<Node> st(v, N);

    rep(i, N)
    {
        if (T[i] == 1)
        {
            int l = 0, r = N, fl = mX[mp(X[i] - Y[i], i)], fr;
            while (l < r)
            {
                int m = (l + r) / 2;
                if (sX[m].ff.ff >= X[i] + Y[i]) r = m;
                else l = m + 1;
            } fr = l - 1;

            if (fl <= fr) st.update(fl, fr);
        }
        if (T[i] == 2)
        {
            ans = -1;
            search(i, mX[mp(X[i], i)], 0, 0, N - 1, st);
            cout << ans << '\n';

            if (ans != -1)
                st.update(mX[mp(X[ans - 1] - Y[ans - 1], ans - 1)], -1);
        }
    }
}
