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
#define invrep(i, b, a) for (int i = b; i >= a; --i)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
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

const double PI = 3.14159265358979323846;

template <typename T>
struct Point
{
    T x, y, b;

    Point<T> operator-(const Point<T> &p) const { return {x - p.x, y - p.y}; }

    double angle()
    {
        double angle = atan2(y, x);
        if (angle < 0)
            angle += 2 * PI;
        return angle;
    }
};

int n, x, y, b;
vector<Point<ll>> stars;

int main()
{
    cin >> n;
    rep(i, n)
    {
        cin >> x >> y >> b;
        stars.pb({x, y, b});
    }

    vector<pair<double, int>> sweep;
    int c = 0;
    int n_ = 0;

    rep(i, n) repx(j, i, n)
    {
        if (stars[i].b == stars[j].b)
            continue;

        n_++;

        Point<ll> aux;
        if (stars[i].b > stars[j].b)
            aux = stars[j] - stars[i];
        else
            aux = stars[i] - stars[j];

        double left = aux.angle() + PI / 2;
        double right = aux.angle() - PI / 2;
        if (left >= 2 * PI)
        {
            left -= 2 * PI;
            c++;
        }
        if (right < 0)
        {
            right += 2 * PI;
            c++;
        }

        sweep.pb({left, 1});
        sweep.pb({right, 0});
    }

    sort(sweep.begin(), sweep.end());

    if (!n_)
    {
        cout << "Y\n";
        return 0;
    }

    pair<double, int> last = {-1, -1};
    for (auto e : sweep)
    {
        if (e.second && e != last && c >= n_)
        {
            cout << "Y\n";
            return 0;
        }
        if (e.second)
            c--;
        else
            c++;
        last = e;
    }

    cout << "N\n";
}