#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double EPS = 1e-12;

typedef double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

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

int N;
vector<P> p;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    int k = 1;
    while (cin >> N && N)
    {
        p.resize(N);
        rep(i, N) cin >> p[i];

        vector<P> H = convexHull(p);
        N = H.size();

        double ans = DBL_MAX;
        rep(i, N)
        {
            P p1 = H[i], p2 = H[(i + 1) % N];
            double aux = 0;

            rep(j, N) aux = max(aux, turn(p1, p2, H[j]) / (p2 - p1).norm());

            ans = min(ans, aux);
        }

        cout << "Case " << k++ << ": ";
        cout << ceil(ans * 100.) / 100. << '\n';
    }
}