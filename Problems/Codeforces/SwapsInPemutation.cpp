#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct UnionFind
{
    vector<int> p, rank, setSize;
    int numSets;
    UnionFind(int n)
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
        if (rank[x] > rank[y])
        {
            p[y] = x;
            setSize[x] += setSize[y];
        }
        else
        {
            p[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n, m, x, y;
vector<int> p;

int main()
{
    cin >> n >> m;

    p.resize(n);
    rep(i, n) cin >> p[i];

    UnionFind uf(n);

    rep(i, m)
    {
        cin >> x >> y;
        uf.unionSet(x - 1, y - 1);
    }

    set<int> parents;
    vector<priority_queue<int>> aux(n);

    rep(i, n)
    {
        parents.insert(uf.findSet(i));
        aux[uf.findSet(i)].push(p[i]);
    }

    rep(i, n)
    {
        p[i] = aux[uf.findSet(i)].top();
        aux[uf.findSet(i)].pop();
    }

    rep(i, n) cout << p[i] << ' ';
    cout << '\n';
}