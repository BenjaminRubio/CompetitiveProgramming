#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const long double PI = acos(-1.0L);
const long double EPS = 1e-12;

typedef long double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const long double &c) const { return P(x * c, y * c); }
    P operator/(const long double &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }

    T norm2() const { return x * x + y * y; }
    long double norm() const { return sqrt(norm2()); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

long double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) < EPS; }

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool properInter(P &a, P &b, P &c, P &d, P &out)
{
    long double ta = turn(c, d, a), tb = turn(c, d, b),
           tc = turn(a, b, c), td = turn(a, b, d);
    out = (a * tb - b * ta) / (tb - ta);
    return (ta * tb < -EPS && tc * td < -EPS);
}

set<P> inter(P &a, P &b, P &c, P &d)
{
    P out;
    if (properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if (onSegment(c, d, a)) ans.insert(a);
    if (onSegment(c, d, b)) ans.insert(b);
    if (onSegment(a, b, c)) ans.insert(c);
    if (onSegment(a, b, d)) ans.insert(d);
    return ans;
}

long double areaPolygon(vector<P> &p)
{
    long double ans = 0; int n = p.size();
    rep(i, n) ans += p[i] ^ p[(i + 1) % n];
    return abs(ans) / 2.;
}

int N;
long double W, H;
P c, a, b;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);

    int k = 1;
    while (cin >> N >> W >> H >> c)
    {
        vector<P> v = {P(0, 0), P(W, 0), P(W, H), P(0, H)};

        rep(_, N)
        {
            cin >> a >> b;

            if (turn(a, b, c) < 0) swap(a, b);

            vector<P> v_;
            int n = v.size();

            rep(i, n)
            {
                if (turn(a, b, v[i]) > -EPS) v_.push_back(v[i]);
                if (turn(a, b, v[i]) * turn(a, b, v[(i + 1) % n]) < -EPS)
                    v_.push_back(*inter(v[i], v[(i + 1) % n], a, b).begin());
            }

            v = v_;
        }

        cout << "Case #" << k++ << ": " << areaPolygon(v) << '\n';
    }
}