#include <bits/stdc++.h>
using namespace std;

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> ii;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const ll MOD = 999727999;
const ll POT = 325255434;

inline ll add(ll a, ll b) { return (a + b) % MOD; }
inline ll mul(ll a, ll b) { return (a * b) % MOD; }

ll P[1000001];

struct HASH
{
    int p, sz = 0, v, acc, acc_, l = -1, r = -1, lzv = 0;
    bool lz = false, f = false;
    HASH() : p(gen()), v(0), acc(0), acc_(0) {}
    HASH(int x): p(gen()), sz(1), v(x), acc(x), acc_(x) {}
    void recalc(const HASH &a, const HASH &b)
    {
        sz = a.sz + b.sz + 1;
        acc = add(a.acc, add(mul(v, P[a.sz]), mul(b.acc, P[a.sz + 1])));
        acc_ = add(b.acc_, add(mul(v, P[b.sz]), mul(a.acc_, P[b.sz + 1])));
    }
};

template <class node>
struct Treap
{
    vector<node> t; int n, r = -1;

    node get(int u) { return u != -1 ? t[u] : node(); }
    void recalc(int u) { t[u].recalc(get(t[u].l), get(t[u].r)); }
    int merge(int l, int r)
    {
        if (l == -1 || r == -1) return l != -1 ? l : r;
        int ans = (t[l].p < t[r].p) ? l : r;
        if (ans == l) t[l].r = merge(t[l].r, r), recalc(l);
        if (ans == r) t[r].l = merge(l, t[r].l), recalc(r);
        return ans;
    }
    ii split(int u, int id)
    {
        if (u == -1) return {-1, -1};
        if (get(t[u].l).sz >= id)
        {
            ii ans = split(t[u].l, id);
            t[u].l = ans.ss; recalc(u);
            return {ans.ff, u};
        }
        id -= get(t[u].l).sz + 1;
        ii ans = split(t[u].r, id);
        t[u].r = ans.ff; recalc(u);
        return {u, ans.ss};
    }

    Treap(vector<int> &v) : n(v.size())
    { for (int i = 0; i < n; i++) t.emplace_back(v[i]), r = merge(r, i); }
};

int N, Q, root, t, l, r;
string S; char c;

int main()
{
    P[0] = 1;
    rep(i, 1000000) P[i + 1] = mul(P[i], POT);

    cin >> N >> Q >> S;

    vector<int> v(N);
    rep(i, N) v[i] = S[i];

    Treap<HASH> treap(v);
    root = treap.r;

    while (Q--)
    {
        cin >> t;

        if (t == 1)
        {
            cin >> l >> r; l--;
            ii s1 = treap.split(root, r);
            ii s2 = treap.split(s1.ff, l);
            root = treap.merge(s2.ff, s1.ss);
        }
        if (t == 2)
        {
            cin >> c >> l; l--;
            treap.t.emplace_back(c);
            ii s1 = treap.split(root, l); treap.n++;
            root = treap.merge(s1.ff, treap.merge(treap.n - 1, s1.ss));
        }
        if (t == 3)
        {
            cin >> l >> r; l--;
            ii s1 = treap.split(root, r);
            ii s2 = treap.split(s1.ff, l);
            HASH h = treap.get(s2.ss);
            if (h.acc == h.acc_) cout << "yes\n";
            else cout << "no\n";
            root = treap.merge(treap.merge(s2.ff, s2.ss), s1.ss);
        }
    }
}
