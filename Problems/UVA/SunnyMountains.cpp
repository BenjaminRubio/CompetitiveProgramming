#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    bool operator>(const P &p) const { return x > p.x; }
    double norm() const { return sqrt(x * x + y * y); }
};

int C, N;
vector<P> p;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    cin >> C;
    rep(_, C)
    {
        cin >> N;

        p.resize(N);
        rep(i, N) cin >> p[i].x >> p[i].y;

        sort(p.begin(), p.end(), greater<P>());

        double ans = 0, M = 0;
        for (int i = N - 1, j = 0; j < N; i = j++)
        {
            if (p[j].y > M)
            {
                double r = (p[j].y - M) / (p[j].y - p[i].y);
                ans += (p[j] - p[i]).norm() * r;
            }
            M = max(M, p[j].y);
        }

        cout << ans << '\n';
    }
}