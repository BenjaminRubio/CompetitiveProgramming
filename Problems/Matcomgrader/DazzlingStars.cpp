#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef long long T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }

    bool half() const { return y > 0 || (y == 0 && x > 0); }
    bool operator<(const P &p) const
    {
        int h1 = half(), h2 = p.half();
        return h1 != h2 ? h1 > h2 : ((*this) ^ p) > 0;
    }

    P rot() { return P(y, -x); }
    P tor() { return P(-y, x); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N; vector<P> p;
vector<int> B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    p.resize(N); B.resize(N);
    rep(i, N) cin >> p[i] >> B[i];

    vector<pair<P, int>> E; int ans = 0, c = 0;
    rep(i, N) rep(j, N) if (B[j] > B[i])
    {
        P v = p[j] - p[i];
        E.emplace_back(v.rot(), 0); E.emplace_back(v.tor(), 1);
        if (v.tor() < v.rot()) c++;
    }

    sort(E.begin(), E.end());

    for (auto &e : E)
    {
        if (e.second == 0) c++;
        if (e.second == 1) c--;
        ans = max(ans, c);
    }

    cout << (ans >= (int)E.size() / 2 ? "Y\n" : "N\n");
}