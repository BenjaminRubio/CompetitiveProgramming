#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

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

struct Point
{
    ll x, y;
    double dist(Point &p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

int N;
ll X, Y, W, H;
vector<Point> dinosaur;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);

    while (cin >> N >> W >> H)
    {
        if (N == -1 && W == -1 && H == -1)
            break;

        dinosaur.resize(N);
        rep(i, N)
        {
            cin >> X >> Y;
            dinosaur[i] = {X, Y};
        }

        double low = 0;
        double high = 1000000;
        rep(k, 38)
        {
            double m = (low + high) * 0.5;

            UnionFind uf(N + 4);
            rep(i, N)
            {
                Point d = dinosaur[i];
                if (d.x <= m)
                    uf.unionSet(0, i + 4);
                if (d.y <= m)
                    uf.unionSet(1, i + 4);
                if (W - d.x <= m)
                    uf.unionSet(2, i + 4);
                if (H - d.y <= m)
                    uf.unionSet(3, i + 4);

                rep(j, i) if ((double)d.dist(dinosaur[j]) * 0.5 <= m)
                    uf.unionSet(i + 4, j + 4);

                if (uf.isSameSet(0, 1) || uf.isSameSet(2, 3) || uf.isSameSet(1, 3) || uf.isSameSet(0, 2))
                    break;
            }

            if (uf.isSameSet(0, 1) || uf.isSameSet(2, 3) || uf.isSameSet(1, 3) || uf.isSameSet(0, 2))
                high = m;
            else
                low = m;
        }

        cout << low << '\n';
    }
}