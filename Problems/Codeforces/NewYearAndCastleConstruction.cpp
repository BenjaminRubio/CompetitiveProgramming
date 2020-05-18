#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
typedef long long ll;

typedef ll T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

ll N;
vector<P> p;

int main()
{
    cin >> N;

    p.resize(N);
    rep(i, N) cin >> p[i];

    ll ans = 0, pos = ((N - 1) * (N - 2) * (N - 3) * (N - 4)) / 24ll;
    rep(i, N)
    {
        ll aux = pos;

        vector<P> v;
        rep(j, N) if (i != j) v.push_back(p[j] - p[i]);

        sort(v.begin(), v.end(), [](P &p1, P &p2)
        {
            ll h1 = half(p1), h2 = half(p2);
            return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
        });
        rep(j, N - 1) v.push_back(v[j]);


        ll k = 0;
        rep(j, N - 1)
        {
            while (k < 2 * N - 2 && k < j + N - 1 && (v[j] ^ v[k]) >= 0) k++;
            ll n = k - j - 1;
            aux -= (n * (n - 1) * (n - 2)) / 6ll;
        }

        ans += aux;
    }

    cout << ans << '\n';
}