#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef long double T;
const T PI = acos(-1.0L);
const T EPS = 1e-12;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const T &c) const { return P(x * c, y * c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator<(const P &p) const
    {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

vector<P> convexHull(vector<P> &p)
{
    int n = p.size(), k = 0;
    vector<P> H(2 * n);
    sort(p.begin(), p.end());
    rep(i, n)
    {
        while (k >= 2 && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q)
{
    return (above(a, q) - above(a, p)) * turn(a, p, q) > EPS;
}

bool inPolygon(vector<P> &p, P &a, bool strict = true)
{
    int c = 0, n = p.size();
    rep(i, n)
    {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

bool properInter(P &a, P &b, P &c, P &d)
{
    double ta = turn(c, d, a), tb = turn(c, d, b),
           tc = turn(a, b, c), td = turn(a, b, d);
    return (ta * tb < 0 && tc * td < 0);
}

T t, s1, w1, l1, s2, w2, l2; char d1, d2;
map<char, P> D = {{'N', P(0, 1)}, {'S', P(0, -1)}, {'E', P(1, 0)}, {'W', P(-1, 0)}};

int main()
{
    cin >> t;

    P p1, p2;
    cin >> d1 >> p1 >> s1 >> w1 >> l1;
    cin >> d2 >> p2 >> s2 >> w2 >> l2;

    if (d1 == 'E' || d1 == 'W') swap(w1, l1);
    if (d2 == 'E' || d2 == 'W') swap(w2, l2);

    vector<P> V, C;
    V.push_back(p2 + P(-w2 / 2., -l2 / 2.)); V.push_back(p2 + P(w2 / 2., -l2 / 2.)); 
    V.push_back(p2 + P(w2 / 2., l2 / 2.)); V.push_back(p2 + P(-w2 / 2., l2 / 2.));

    P a, b, dir = (D[d1] * s1 - D[d2] * s2) * t;
    a = p1 + P(w1 / 2., l1 / 2.), b = a + dir;
    C.push_back(a); C.push_back(b);
    a = p1 + P(-w1 / 2., l1 / 2.), b = a + dir;
    C.push_back(a); C.push_back(b);
    a = p1 + P(w1 / 2., -l1 / 2.), b = a + dir;
    C.push_back(a); C.push_back(b);
    a = p1 + P(-w1 / 2., -l1 / 2.), b = a + dir;
    C.push_back(a); C.push_back(b);

    vector<P> H = convexHull(C);
    int crash = 0, c = 0;
    rep(i, 4)
    {
        bool on = 0;
        if (inPolygon(H, V[i])) crash = 1;
        rep(j, H.size())
        {
            if (properInter(V[i], V[(i + 1) % 4], H[j], H[(j + 1) % H.size()])) crash = 1;
            if (onSegment(H[j], H[(j + 1) % H.size()], V[i])) on = 1;
        }
        if (on) c++;
    }

    if (crash || c == 4) cout << "crash\n";
    else cout << "safe\n";
}