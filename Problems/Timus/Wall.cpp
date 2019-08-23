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

#define debugx(x)  // cerr << #x << ": " << x << endl
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

#define PI 3.1415926535

// Convex Hull obtenido de apuntes Pablo Messina.

struct Point
{
    ll x, y;
    bool operator<(const Point &p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

ll cross(Point &a, Point &b, Point &c)
{
    ll dx0 = b.x - a.x, dy0 = b.y - a.y;
    ll dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

vector<Point> upper_hull(vector<Point> &P)
{
    // sort points lexicographically
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());

    // build upper hull
    vector<Point> uh(n);
    invrep(i, 0, n)
    {
        while (k >= 2 && cross(uh[k - 2], uh[k - 1], P[i]) <= 0)
            k--;
        uh[k++] = P[i];
    }
    uh.resize(k);
    return uh;
}

vector<Point> lower_hull(vector<Point> &P)
{
    // sort points lexicographically
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());

    // collect lower hull
    vector<Point> lh(n);
    rep(i, n)
    {
        while (k >= 2 && cross(lh[k - 2], lh[k - 1], P[i]) <= 0)
            k--;
        lh[k++] = P[i];
    }
    lh.resize(k);
    return lh;
}

vector<Point> convex_hull(vector<Point> &P)
{
    int n = P.size(), k = 0;

    // set initial capacity
    vector<Point> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }

    // remove extra space
    H.resize(k - 1);
    return H;
}

double norm(Point a)
{
    return sqrt((double)a.x * (double)a.x +
                (double)a.y * (double)a.y);
}

double dot(Point a, Point b)
{
    return (double)a.x * (double)b.x + (double)a.y * (double)b.y;
}

double distance(Point a, Point b)
{
    return sqrt((double)(a.x - b.x) * (double)(a.x - b.x) +
                (double)(a.y - b.y) * (double)(a.y - b.y));
}

double arco(Point a, Point b)
{
    return acos(dot(a, b) / (norm(a) * norm(b)));
}

Point recta(Point a, Point b)
{
    return {b.x - a.x, b.y - a.y};
}

int n, l, x, y;
vector<Point> v;

int main()
{
    cin >> n >> l;

    rep(i, n)
    {
        cin >> x >> y;
        v.pb({x, y});
    }

    vector<Point> ch = convex_hull(v);
    ch.pb(ch[0]);

    double len = 0;

    rep(i, ch.size() - 1)
    {
        debugx(len);
        double d = distance(ch[i], ch[i + 1]);
        len += d;
    }

    cout << round(len + 2.0 * PI * (double)l) << '\n';
}