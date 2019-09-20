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
        numS--;
        int x = findSet(i), y = findSet(j);
        p[y] = x;
        setSize[x] += setSize[y];
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

int n, a, b, c;
ll x, y;
umap<ll, int> cx, cy;

int main()
{
    cin >> n;
    c = 0;
    UnionFind uf(2 * n);

    rep(i, n)
    {
        cin >> x >> y >> a >> b;
        if (cx.find(x) == cx.end())
            cx[x] = c++;
        if (cy.find(x) == cy.end())
            cy[y] = c++;
        if (a == b)
        {
            uf.UnionSet(cx[x], cy[y]);
            cout << "Yes\n";
        }
        else
        {
            if (uf.isSameSet(cx[x], cy[y]))
            {
                cout << "No\n";
                continue;
            }
            cout << "Yes\n";
        }
    }
}