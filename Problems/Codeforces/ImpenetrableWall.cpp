#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }

    bool operator<(const P &p) const { return mp(p.x, p.y) > mp(x, y); }
    bool operator!=(const P &p) const { return mp(p.x, p.y) != mp(x, y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

const ll MOD = 1e9 + 7;

int N;
P ph, pg;
deque<P> p;

ll DP[310][310];

ll dp(int i, int j)
{
    if (turn(p[i], p[j], ph) <= 0) return 0;

    if (i == 0) return 1;
    if (DP[i][j] != -1) return DP[i][j];

    ll ans = 0;
    rep(k, i) if (turn(p[k], p[i], p[j]) > 0) ans = (ans + dp(k, i)) % MOD;

    return DP[i][j] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> ph >> pg >> N; pg = pg - ph;
    p.resize(N); rep(i, N) { cin >> p[i]; p[i] = p[i] - ph; }
    p.pb(pg); ph = ph - ph;

    sort(p.begin(), p.end(), [](P &p1, P &p2)
    {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });

    while (p.front() != pg) { p.pb(p.front()); p.pop_front(); }
    p.pb(p.front());

    memset(DP, -1, sizeof DP);

    ll ans = 0;
    repx(i, 1, N + 1) ans = (ans + dp(i, N + 1)) % MOD;

    cout << ans << '\n';
}
