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
#define ppb poperation_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x)  // cerr << #x << ": " << x << endl
#define debugv(v)  //        \
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
#define print(x) coperationy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

// Fenwick tree 2d de apuntes Pablo Messina.

struct BIT2D { // BIT = binary indexed tree (a.k.a. Fenwick Tree)
    vector<int> bit;
    int R, C;
    BIT2D(int _R, int _C) : R(_R), C(_C) {
        bit.assign((R+1)*(C+1), 0);
    }
    void add(int r, int c, int value) {
        for (int i = r; i <= R; i += (i&-i))
            for (int j = c; j <= C; j += (j&-j))
                bit[i * C + j] += value;
    }
    // sum[(1, 1), (r, c)]
    int sum(int r, int c) {
        int res = 0;
        for (int i = r; i; i -= (i&-i))
            for (int j = c; j; j -= (j&-j))
                res += bit[i * C + j];
        return res;
    }
    // sum[(r1, c1), (r2, c2)]
    int sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1-1, c2) - sum(r2, c1-1) + sum(r1-1, c1-1);
    }
    // get value at cell (r,c)
    int get(int r, int c) {
        return sum(r, c, r, c);
    }
    // set value to cell (r,c)
    void set(int r, int c, int value) {
        add(r, c, -get(r, c) + value);
    }
};

int t, n, x, y, z, w, val;
string operation;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    rep(k, t)
    {
        cin >> n;

        BIT2D ft(n, n);

        while (true)
        {
            cin >> operation;

            if (operation == "END")
                break;

            if (operation == "SET")
            {
                cin >> x >> y >> val;
                ft.set(x + 1, y + 1, val);
            }

            if (operation == "SUM")
            {
                cin >> x >> y >> z >> w;
                cout << ft.sum(x + 1, y + 1, z + 1, w + 1) << '\n';
            }
        }
    }
}