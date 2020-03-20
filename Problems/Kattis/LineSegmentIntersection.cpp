#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    double operator^(const P &p) const { return x * p.y - p.x * y; }
    double operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const { return x == p.x && y == p.y; }
    bool operator<(const P &p) const
    {
        return x < p.x or (x == p.x and y < p.y);
    }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) { return s << p.x << ' ' << p.y; }

double point_line_dist(P &p, P &a, P &b)
{
    return (abs((b - a) ^ (p - a))) / (b - a).norm();
}

int n;

int sgn(ll x) { return (x < 0) ? -1 : ((x > 0) ? 1 : 0); }

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    cin >> n;
    rep(_, n)
    {
        P p1, q1, p2, q2;
        cin >> p1 >> q1 >> p2 >> q2;

        if (sgn((q1 - p1) ^ (p2 - p1)) * sgn((q1 - p1) ^ (q2 - p1)) < 0 && 
            sgn((q2 - p2) ^ (p1 - p2)) * sgn((q2 - p2) ^ (q1 - p2)) < 0)
        {
            double d1 = (q1 - p1) * (p2 - p1) / (q1 - p1).norm(); // proy 1
            double d2 = (q1 - p1) * (q2 - p1) / (q1 - p1).norm(); // proy 2
            double h1 = point_line_dist(p2, p1, q1);
            double h2 = point_line_dist(q2, p1, q1);
            P x = p1 + ((q1 - p1) * (d2 + (d1 - d2) * (h2 / (h1 + h2)))) 
                        / (q1 - p1).norm();

            cout << x << '\n';
        }
        else if (!sgn((q1 - p1) ^ (p2 - p1)) && !sgn((q1 - p1) ^ (q2 - p1)))
        {
            if (p1 == q1) { swap(p1, p2); swap(q1, q2); }
            if (p1 == q1)
            {
                if (p1 == q2) cout << p1 << '\n';
                else cout << "none\n";
                continue;
            }

            vector<double> v;
            v.push_back(0);
            v.push_back((q1 - p1).norm());
            v.push_back(((q1 - p1) * (p2 - p1)) / (q1 - p1).norm());
            v.push_back(((q1 - p1) * (q2 - p1)) / (q1 - p1).norm());
            sort(v.begin(), v.end());

            if (v[1] == v[2])
            {
                cout << p1 + ((q1 - p1) * (v[1] / (q1 - p1).norm())) << '\n';
                continue;
            }
            
            set<P> s;
            s.insert(p1 + ((q1 - p1) * (v[1] / (q1 - p1).norm())));
            s.insert(p1 + ((q1 - p1) * (v[2] / (q1 - p1).norm())));

            for (P p : s) cout << p << ' ';
            cout << '\n';
        }
        else cout << "none\n";
    }
}