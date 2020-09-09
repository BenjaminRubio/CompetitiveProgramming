#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

struct UF
{
    int numSets;
    vector<int> p, rank, setSize;
    UF(int n)
    {
        numSets = n;
        setSize.assign(n, 1);
        rank.assign(n, 0);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (isSameSet(i, j)) return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x, setSize[x] += setSize[y];
        else p[x] = y, setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
    }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

struct Query
{
    int P, T, X, id;
    Query(int P, int T, int X, int id) : P(P), T(T), X(X), id(id) {}
    bool operator<(const Query &q) const { return mp(P, T) > mp(q.P, q.T); }
};

int N, L, U, Q, B, E, X;
vector<int> A;
priority_queue<Query> q;

int main()
{
    cin >> N >> L >> U;

    A.resize(N);
    rep(i, N) cin >> A[i];

    cin >> Q;

    rep(i, Q)
    {
        cin >> B >> E >> X;
        q.emplace(B - 1, 0, X, i);
        q.emplace(E - 1, 1, X, i);
    }

    UF uf(Q);

    ll off = 0;
    set<pair<ll, int>> S;
    vector<ll> ans(Q), V(Q);
    rep(i, N)
    {
        while (!q.empty() && q.top().T == 0 && q.top().P == i)
        {
            Query qq = q.top(); q.pop();
            V[qq.id] = qq.X - off; S.emplace(qq.X - off, qq.id);
        }

        off += A[i];

        pair<ll, int> aux, t;
        if (!S.empty() && S.begin()->ff + off < L)
        {
            aux = *S.begin(); S.erase(aux);
            aux.ff = L - off; S.insert(aux);
            V[uf.findSet(aux.ss)] = L - off;
        }
        while (!S.empty() && S.begin()->ff + off < L)
        {
            t = *S.begin(); S.erase(t);
            uf.unionSet(aux.ss, t.ss);
            V[uf.findSet(t.ss)] = L - off;
        }

        if (!S.empty() && S.rbegin()->ff + off > U)
        {
            aux = *S.rbegin(); S.erase(aux);
            aux.ff = U - off; S.insert(aux);
            V[uf.findSet(aux.ss)] = U - off;
        }
        while (!S.empty() && S.rbegin()->ff + off > U)
        {
            t = *S.rbegin(); S.erase(t);
            uf.unionSet(aux.ss, t.ss);
            V[uf.findSet(t.ss)] = U - off;
        }

        while (!q.empty() && q.top().T == 1 && q.top().P == i)
        {
            Query qq = q.top(); q.pop();
            // cerr << qq.id << ' ' << V[uf.findSet(qq.id)] << ' ' << off << '\n';
            ans[qq.id] = V[uf.findSet(qq.id)] + off;
        }
    }

    rep(i, Q) cout << ans[i] << '\n';
}