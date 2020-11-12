#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

int N, Q; P q;
vector<P> p;

int main()
{
    cin >> N >> Q;

    p.resize(N);
    rep(i, N) cin >> p[i];

    rep(_, Q)
    {
        cin >> q;

        bool in = 1;
        rep(i, N) if (turn(p[i], p[(i + 1) % N], q) < 0) in = 0;

        if (in) cout << "D\n";
        else cout << "F\n";
    }
}