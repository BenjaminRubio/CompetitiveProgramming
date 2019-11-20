#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;
typedef vector<pair<int, int>> vp;

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
        if (!isSameSet(i, j))
        {
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
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n, x, y, r;
vi rads;
vp coords;

int main()
{
    cin >> n;

    rads.resize(n);
    coords.resize(n);
    rep(i, n)
    {
        cin >> x >> y >> r;
        rads[i] = r;
        coords[i] = {x, y};
    }

    UnionFind uf(n + 2);
    int i = 0;
    while (i < n)
    {
        // cerr << i << ' ' << coords[i].first << ' ' << coords[i].second << ' ' << rads[i] << '\n';
        if (coords[i].first - rads[i] < 0)
            uf.unionSet(0, i + 2);
        if (coords[i].first + rads[i] > 200)
            uf.unionSet(1, i + 2);

        rep(j, i)
        {
            x = coords[i].first - coords[j].first;
            y = coords[i].second - coords[j].second;
            r = rads[i] + rads[j];
            if (x * x + y * y < r * r)
                uf.unionSet(i + 2, j + 2);
        }

        if (uf.isSameSet(0, 1))
            break;

        i++;
    }

    cout << i << '\n';
}