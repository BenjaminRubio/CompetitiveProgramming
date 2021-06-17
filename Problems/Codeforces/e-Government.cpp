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

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

struct FT
{
    vi t;
    FT(int N) { t.resize(N + 2, 0); }
    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) ans += t[i];
        return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v)
    {
        for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};

struct AC
{
    int c = 0, ec = 0, M, A;
    vector<vi> N, G;
    vi L, E;

    AC (int M, int A) : M(M), A(A), N(M, vi(A, 0)), E(M, 0) {}
    int add(string s)
    {
        int p = 0;
        for (char l : s)
        {
            int t = l - 'a';
            if (!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
        } E[p]++;
        return p;
    }
    void init()
    {
        L.assign(M, 0), G.assign(M, {});
        queue<int> q; q.push(0); L[0] = -1;
        while (!q.empty())
        {
            int p = q.front(); q.pop();
            rep(c, A)
            {
                int u = N[p][c]; if (!u) continue;
                L[u] = L[p] == -1 ? 0 : N[L[p]][c], q.push(u);
                G[L[u]].pb(u);
            }
            if (p) rep(c, A) if (!N[p][c]) N[p][c] = N[L[p]][c];
        }
    }
};

const int MAXN = 1e6 + 10;

int N, K, ec;
vector<string> S;
string s;
vi LL, LR, P, C;

void euler(int u, AC &ac, int acc, FT &ft)
{
    acc += ac.E[u];
    LL[u] = ec++; ft.update(ec, ec, acc);
    for (int v : ac.G[u]) euler(v, ac, acc, ft);
    LR[u] = ec;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;

    AC ac(MAXN, 26);

    S.resize(K), P.resize(K), C.resize(K);
    rep(i, K)
    {
        cin >> S[i];
        P[i] = ac.add(S[i]), C[i] = 1;
    }

    ac.init();

    LL.resize(MAXN), LR.resize(MAXN);
    FT ft(MAXN);
    ec = 0, euler(0, ac, 0, ft);

    rep(_, N)
    {
        char t; cin >> t;
        if (t == '?')
        {
            cin >> s;

            int p = 0, ans = 0;
            for (char c : s) { p = ac.N[p][c - 'a']; ans += ft.query(LL[p] + 1); }

            cout << ans << '\n';
        }
        if (t == '+')
        {
            int j; cin >> j; j--;
            int p = P[j];
            if (C[j] == 0) ft.update(LL[p] + 1, LR[p], 1), C[j] = 1;
        }
        if (t == '-')
        {
            int j; cin >> j; j--;
            int p = P[j];
            if (C[j] == 1) ft.update(LL[p] + 1, LR[p], -1), C[j] = 0;
        }
    }
}
