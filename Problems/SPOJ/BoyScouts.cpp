#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const { return y < p.y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

int C, N;
vector<P> p;
int DP[101][101][101];

int dp(int i, int j, int k)
{
    if (DP[i][j][k] != -1) return DP[i][j][k];

    int ans = 0;
    repx(ii, i + 1, N) if (ii != j && ii != k)
    {
        if (turn(p[i], p[k], p[ii]) > 0 and turn(p[j], p[k], p[ii]) > 0)
            ans = max(ans, dp(i, k, ii) + 1);
    }
    return DP[i][j][k] = ans;
}

int main()
{
    memset(DP, -1, sizeof DP);

    cin >> N;

    p.resize(N);
    rep(i, N) cin >> p[i];

    sort(p.begin(), p.end());

    int ans = 0;
    rep(i, N) repx(j, i + 1, N) repx(k, j + 1, N)
    {
        if (turn(p[i], p[j], p[k]) > 0)
            ans = max(ans, dp(i, j, k) + 3);
        else ans = max(ans, dp(i, k, j) + 3);
    }

    cout << ans << '\n';
}