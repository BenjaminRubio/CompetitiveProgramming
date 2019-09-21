#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<ll> vi;
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
#define debugv(v)         \
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

// Calculo de Area apuntes pablo messina.

const int N = 100001;
struct Point
{
    int x, y;
};
Point P[N];
int n, x, y;

double area(int n)
{
    int A = 0;
    for (int i = n - 1, j = 0; j < n; i = j++)
        A += (P[i].x + P[j].x) * (P[j].y - P[i].y);
    return fabs(A * 0.5);
}

int main()
{
    cin >> n;

    rep(i, n)
    {
        cin >> x >> y;
        P[i] = {x, y};
    }

    double a = area(n);

    ll b = 0;
    rep(i, n - 1)
    {
        x = abs(P[i].x - P[i + 1].x);
        y = abs(P[i].y - P[i + 1].y);
        b += gcd(x, y);
    }
    x = abs(P[n - 1].x - P[0].x);
    y = abs(P[n - 1].y - P[0].y);
    b += gcd(x, y);

    cout << a - (double)b / 2.0 + 1.0 << '\n';
}
