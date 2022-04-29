#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

struct MIN
{
    ll v;
    MIN() { v = 1e18; } // neutro
    MIN(ll v) : v(v) {}
    MIN(const MIN &a, const MIN &b) { v = min(a.v, b.v); }
};

template <class node>
struct ST
{
    vector<node> t; int n;

    ST() : n(3010), t(3010 * 2) {}
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
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

int N;
vl S, D, F, SS;

ll DP[3010][3010][2];
ST<MIN> st[2][2][3010];

void set0(int i, int j, ll x)
{
    st[0][0][j].set(i, MIN(x + D[i - 1] + SS[i]));
    st[0][1][j].set(i, MIN(x + D[i - 1] - SS[i]));
    DP[i][j][0] = x;
}

void set1(int i, int j, ll x)
{
    st[1][0][i].set(j, MIN(x + D[j - 1] + SS[j]));
    st[1][1][i].set(j, MIN(x + D[j - 1] - SS[j]));
    DP[i][j][1] = x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    S.resize(N + 1), D.resize(N + 1), F.resize(N + 1);
    rep(i, N - 1) cin >> S[i];
    rep(i, N) cin >> D[i];
    rep(i, N + 1) cin >> F[i];

    SS.assign(N + 1, 0);
    repx(i, 2, N + 1) SS[i] = SS[i - 1] + S[i - 2];

    rep(i, N + 1) set0(i, i + 1, F[i]), set1(i, i + 1, F[i]);

    repx(d, 2, N + 2) rep(i, N + 2 - d)
    {
        int j = i + d;

        int l = i + 1, r = j;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (DP[i][m][1] > DP[m][j][0]) r = m;
            else l = m + 1;
        }

        set0(i, j, min(st[0][0][j].query(i + 1, l).v, st[1][0][i].query(l, j).v) - SS[i]);
        set1(i, j, min(st[0][1][j].query(i + 1, l).v, st[1][1][i].query(l, j).v) + SS[j]);
    }
    
    cout << DP[0][N + 1][0] << '\n';
}
