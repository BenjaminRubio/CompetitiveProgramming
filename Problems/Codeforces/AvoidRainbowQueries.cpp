#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int M, N, s, a;
vector<int> A, B;

struct DSU
{
    vector<int> p;
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

int main()
{
    cin >> M >> N;

    A.resize(M);
    rep(i, M) cin >> A[i];
    
    B.resize(N);
    rep(i, N) cin >> B[i];

    vector<pair<int, pair<int, int>>> E;

    rep(i, M)
    {
        cin >> s;
        rep(_, s)
        {
            cin >> a; a--;
            int c = A[i] + B[a];
            E.emplace_back(c, make_pair(a, i));
        }
    }

    sort(E.rbegin(), E.rend());

    DSU dsu(N + M);

    long long ans = 0;
    for (auto &e : E)
    {
        int i = e.ss.ff, j = e.ss.ss;

        if (!dsu.sameSet(i, N + j)) dsu.unite(i, N + j);
        else ans += e.ff;
    }

    cout << ans << '\n';
}