#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

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

int N, M, Q, l, r;
vector<vector<int>> m;
vector<UF> U;
vector<int> w;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> Q;

    m.assign(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> m[i][j];

    int binSize = sqrt(M);
    int numBins = M / binSize + bool(M % binSize);
    rep(i, numBins)
    {
        int off = i * binSize; // offset
        int width = min(M, (i + 1) * binSize) - off; w.push_back(width);
        UF uf(N * width);
        repx(j, off, min(M, off + binSize)) rep(k, N)
        {
            if (j > off and m[k][j] == m[k][j - 1])
                uf.unionSet(width * k + j - off, width * k + j - off - 1);
            if (k > 0 and m[k][j] == m[k - 1][j])
                uf.unionSet(width * k + j - off, width * (k - 1) + j - off);
        }

        U.push_back(uf);
    }

    rep(_, Q)
    {
        cin >> l >> r; l--; r--;

        int lBin = l / binSize, rBin = r / binSize;

        if (lBin == rBin)
        {
            int off = l, width = r - l + 1;
            UF uf(N * width);
            repx(j, off, width) rep(k, N)
            {
                if (j > off and m[k][j] == m[k][j - 1])
                    uf.unionSet(width * k + j - off, width * k + j - off - 1);
                if (k > 0 and m[k][j] == m[k - 1][j])
                    uf.unionSet(width * k + j - off, width * (k - 1) + j - off);
            }

            cout << uf.numSets << '\n';
        }
        else
        {
            
        }
    }
}