#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<float> vfloat;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)  //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                      \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

// Union Find apuntes Ignacio Hermosilla.

class UnionFind
{
private:
    int numS;
    vi p, rank, setSize;

public:
    UnionFind(int n)
    {
        numS = n;
        rank.assign(n, 0);
        setSize.assign(n, 1);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void UnionSet(int i, int j)
    {
        if (not isSameSet(i, j))
        {
            numS--;
            int x = findSet(i), y = findSet(j);
            p[y] = x;
            setSize[x] += setSize[y];
        }
    }
    int numSets()
    {
        return numS;
    }
    int setOfSize(int i)
    {
        return setSize[i];
    }
};

int n;
int B[500000];
int I[500000];
int R[500000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    UnionFind uf(n);

    rep(i, n)
        cin >> B[i];
    rep(i, n)
        cin >> I[i];
    rep(i, n)
        cin >> R[i];
    
    rep(i, n)
    {
        rep(j, i)
        {
            int p1 = uf.findSet(i);
            int p2 = uf.findSet(j);
            if (B[p2] > B[p1] && I[p2] > I[p1] && R[p2] > R[p1])
            {
                uf.UnionSet(p2, p1);
            }
            if (B[p2] < B[p1] && I[p2] < I[p1] && R[p2] < R[p1])
            {
                uf.UnionSet(p1, p2);
            }
        }
    }

    cout << n - uf.numSets() << '\n';
}