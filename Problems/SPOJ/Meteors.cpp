#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, K, o, p;
vector<ll> L, R, A, V, ans;
vector<vector<int>> O;

struct Event
{
    int t, c, i;
    Event(int t, int c, int i) : t(t), c(c), i(i) {}
    bool operator<(const Event &e) const
    { return t < e.t || (t == e.t && c < e.c); }
};

void solve(int l, int r, vector<pair<int, ll>> &members)
{
    if (l == r && l < K - 1)
    {
        for (auto &e : members) ans[e.ff] = l;
        return;
    }
    if (l == r) r++;

    vector<Event> E;
    for (auto &e : members)
    {
        V[e.ff] = 0;
        for (int s : O[e.ff]) E.emplace_back(s, 1, e.ff);
    }

    int m = (l + r) / 2; ll acc = 0;
    for (int i = l; i <= m; i++)
    {
        E.emplace_back(L[i], 0, i), E.emplace_back(R[i], 2, i);
        if (L[i] > R[i]) acc += A[i];
    }

    sort(E.begin(), E.end());

    for (Event &e : E)
    {
        if (e.c == 0) acc += A[e.i];
        if (e.c == 2) acc -= A[e.i];
        if (e.c == 1)
        {
            V[e.i] += acc;
            if (V[e.i] > 1e9) V[e.i] = 1e9;
        }
    }

    vector<pair<int, ll>> m1, m2;
    for (auto &e : members)
    {
        if (V[e.ff] >= e.ss) m1.emplace_back(e.ff, e.ss);
        else m2.emplace_back(e.ff, e.ss - V[e.ff]);
    }

    if (r == K)
    {
        for (auto &e : m1) ans[e.ff] = l;
        for (auto &e : m2) ans[e.ff] = -1;
        return;
    }

    solve(l, m, m1), solve(m + 1, r, m2);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    O.assign(N, {});
    rep(i, M) { cin >> o; O[o - 1].push_back(i); }

    vector<pair<int, ll>> init;
    rep(i, N) { cin >> p; init.emplace_back(i, p); }

    cin >> K;

    L.resize(K), R.resize(K), A.resize(K);
    rep(i, K) { cin >> L[i] >> R[i] >> A[i]; L[i]--, R[i]--; }

    V.resize(N), ans.resize(N);
    solve(0, K - 1, init);

    rep(i, N) (ans[i] != -1 ? cout << ans[i] + 1 << '\n' : cout << "NIE\n");
}