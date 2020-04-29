#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.141592653589793238462643383279502884L;
const double EPS = 1e-12;

struct P
{
    double x, y, z;
    P() {}
    P(double x, double y, double z) : x(x), y(y), z(z) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const double &c) const { return P(x * c, y * c, z * c); }
    P operator/(const double &c) const { return P(x / c, y / c, z / c); }
    P operator^(const P &p) const
    {
        return P(y * p.z - z * p.y, 
                 z * p.x - x * p.z,
                 x * p.y - y * p.x);
    }
    double operator*(const P &p) const { return x * p.x + y * p.y + z * p.z; }
    double operator%(const P &p) const
    {
        return acos((*this) * p) / (norm() * p.norm());
    }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) + abs(y - p.y) + abs(z - p.z) < EPS;
    }

    double norm() const { return sqrt(norm2()); }
    double norm2() const { return x * x + y * y + z * z; }
    P unit() { return (*this) / norm(); }
};
P polar(double r, double a, double b)
{
    return P(r * cos(a) * cos(b), r * cos(a) * sin(b), r * sin(a));
}
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y >> p.z; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << p.x << ' ' << p.y << ' ' << p.z;
}

bool in_arc(P &a, P &b, P &n, P &p)
{
    double ab = a % b;
    double ap = a % p;
    P c = (a * cos(ap) + (n ^ a) * sin(ap));
    return ab > ap && p == c;
}

bool find_intersection(P &a1, P &b1, P &a2, P &b2, double &angle)
{
    P n1 = (a1 ^ b1).unit(), n2 = (a2 ^ b2).unit(), i = (n1 ^ n2);
    if (i.norm() < EPS) return false;
    i = i.unit() * a1.norm();
    if (in_arc(a1, b1, n1, i) and in_arc(a2, b2, n2, i))
    {
        angle = a1 % i;
        return true;
    }
    i = i * -1.;
    if (in_arc(a1, b1, n1, i) and in_arc(a2, b2, n2, i))
    {
        angle = a1 % i;
        return true;
    }
    return false;
}

int c, n, m;
double a, b;
vector<vector<P>> C;
vector<P> R;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> c;
    C.assign(c, {});
    rep(i, c)
    {
        cin >> n;
        C[i].resize(n);
        rep(j, n)
        {
            cin >> a >> b; a = (a / 180.) * PI; b = (b / 180.) * PI;
            C[i][j] = polar(1, a, b);
        }
    }

    cin >> m;
    R.resize(m);
    rep(i, m)
    {
        cin >> a >> b; a = (a / 180.) * PI; b = (b / 180.) * PI;
        R[i] = polar(1, a, b);
    }

    double t = 0, w = 0;
    bool in = true;
    for (int i = 0, j = 1; j < m; i = j++)
    {
        P p1 = R[i], p2 = R[j];
        vector<double> inter;
        rep(k, c) for (int i_ = C[k].size() - 1, j_ = 0; j_ < C[k].size(); i_ = j_++)
        {
            if (find_intersection(p1, p2, C[k][i_], C[k][j_], a))
                inter.push_back(a);
        }

        sort(inter.begin(), inter.end());

        double l = 0;
        for (double a : inter)
        {
            if (!in) w += (a - l);
            l = a;
            in = !in;
        }
        if (!in) w += (p1 % p2 - l);
        t += p1 % p2;
    }
    
    cout << t * 6370. << ' ' << w / t * 100. << '\n';
}