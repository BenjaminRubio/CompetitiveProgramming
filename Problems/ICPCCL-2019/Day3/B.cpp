#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define pb push_back
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugv(v) //        \
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

int n, m, x, y;
graph memo1(1001, vi(1001,-1));
graph memo2(1001, vi(1001,-1));
graph memo3(1001, vi(1001,-1));
graph memo4(1001, vi(1001,-1));
graph a;
#define int ll
int f1(int i, int j) {
    if (i==0 and j==0) return a[i][j];
    if (memo1[i][j] != -1) return memo1[i][j];
    if (!i) return memo1[i][j] = a[i][j] + f1(i, j - 1);
    if (!j) return memo1[i][j] = a[i][j] + f1(i - 1, j);
    return memo1[i][j] = a[i][j] + max(f1(i, j - 1), f1(i - 1, j));
}

int f2(int i, int j) {
    if (i == n - 1 and j==0) return a[i][j];
    if (memo2[i][j] != -1) return memo2[i][j];
    if (i == n - 1) return memo2[i][j] = a[i][j] + f2(i, j - 1);
    if (!j) return memo2[i][j] = a[i][j] + f2(i + 1, j);
    return memo2[i][j] = a[i][j] + max(f2(i, j - 1), f2(i + 1, j));
}

int f3(int i, int j) {
    debugx(i);debugx(j);
    if (i == n - 1 and j == m - 1) return a[i][j];
    if (memo3[i][j] != -1) return memo3[i][j];
    if (i == n - 1) return memo3[i][j] = a[i][j] + f3(i, j + 1);
    if (j == m - 1) return memo3[i][j] = a[i][j] + f3(i + 1, j);
    return memo3[i][j] = (a[i][j] + max(f3(i, j + 1), f3(i + 1, j)));
}

int f4(int i, int j) {
    if (i==0 and j == m - 1) return a[i][j];
    if (memo4[i][j] != -1) return memo4[i][j];
    if (!i) return memo4[i][j] = a[i][j] + f4(i, j + 1);
    if (j == m - 1) return memo4[i][j] = a[i][j] + f4(i - 1, j);
    return memo4[i][j] = a[i][j] + max(f4(i, j + 1), f4(i - 1, j));
}
#undef int
int main() {
    #define int ll
    cin >> n >> m;
    memo1.assign(n, vi(m, -1));
    memo2.assign(n, vi(m, -1));
    memo3.assign(n, vi(m, -1));
    memo4.assign(n, vi(m, -1));
    a.assign(n, vi(m, -1));
    debugx("Hola");
    rep(i, n) rep(j, m) {cin >> a[i][j];}
    debugm(a);

    int ans = -1;

    f1(n - 1, m - 1);debugm(memo1); 
    
    f2(0, m - 1);debugm(memo2); 
    f3(0, 0);debugm(memo3);
 f4(n - 1, 0);debugm(memo4);

    rep(i, n)  {
        rep(j, m) {
            if (i > 0 and j > 0 and i < n - 1 and j < m - 1) {
                ans = max({ans, memo1[i - 1][j] + memo3[i + 1][j] + memo2[i][j - 1] + memo4[i][j + 1],
                           memo4[i - 1][j] + memo2[i + 1][j] + memo1[i][j - 1] + memo3[i][j + 1]});
            }
        }
    }

    cout << ans << '\n';
}
