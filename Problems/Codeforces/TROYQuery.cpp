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

ll N, x, y, t;
char a, b;
set<ll> X, Y;
map<ll, ll> mX, mY;
vector<pair<pair<ll, ll>, pair<ll, ll>>> Q;

int main()
{
    cin >> N;

    rep(i, N)
    {
        cin >> x >> y >> a >> t >> b >> t;
        X.insert(x); Y.insert(y);
        Q.emplace_back(mp(x, y), mp(a, b));
    }

    int idx, idy = 0;
    for (ll x : X) mX[x] = idx++;
    for (ll y : Y) mY[y] = idy++;

    UF uf(2 * idx + 2 * idy);

    bool flag = 1;
    for (auto &q : Q)
    {
        x = mX[q.ff.ff], y = mY[q.ff.ss], tie(a, b) = q.ss;
        if (a == b)
        {
            uf.unionSet(x, 2 * idx + y);
            uf.unionSet(idx + x, 2 * idx + idy + y);
        }
        else
        {
            uf.unionSet(x, 2 * idx + idy + y);
            uf.unionSet(idx + x, 2 * idx + y);
        }
        if (uf.isSameSet(x, idx + x) || uf.isSameSet(2 * idx + y, 2 * idx + idy + y))
            flag = 0;

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
}