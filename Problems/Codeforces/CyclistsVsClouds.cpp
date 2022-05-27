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

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef int T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator*(const int &c) const { return P(x * c, y * c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p)
{
    return turn(a, b, p) == 0 && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q)
{
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

int xo, yo, xd, yd, N, V, x, y;
char C; map<char, P> CD = {{'N', P(0, 1)}, {'S', P(0, -1)}, {'E', P(1, 0)}, {'W', P(-1, 0)}};
vector<P> D;
vector<vector<P>> p;

bool inPolygon(int i, int t, P &a, bool strict = true)
{
    int c = 0, n = p[i].size();
    P b = a - (D[i] * t);
    rep(j, n)
    {
        if (onSegment(p[i][j], p[i][(j + 1) % n], b)) return !strict;
        c += crossesRay(b, p[i][j], p[i][(j + 1) % n]);
    }
    return c & 1;
}

bool check(P a, int t)
{
    rep(i, N) if (inPolygon(i, t, a)) return 0;
    return 1;
}

int M[310][310];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> xo >> yo >> xd >> yd;
    xo *= 3, yo *= 3, xd *= 3, yd *= 3;

    if (xo == xd && yo == yd) { cout << 0 << '\n'; return 0; }

    cin >> N;
    p.assign(N, {});
    D.resize(N);
    rep(i, N)
    {
        cin >> C >> V;
        D[i] = CD[C];
        p[i].resize(V);
        rep(j, V) { cin >> x >> y; p[i][j] = P(3 * x, 3 * y); }
    }

    P a; int d;
    queue<pair<P, int>> Q; M[xo][yo] = 1; Q.emplace(P(xo, yo), 0);
    while (!Q.empty())
    {
        tie(a, d) = Q.front(); Q.pop();
        rep(k, 4)
        {
            P dir = P(dx[k], dy[k]), n = a + (dir * 3);
            if (n.x >= 0 && n.x <= 300 && n.y >= 0 && n.y <= 300 && !M[n.x][n.y])
            {
                if (check(a + dir, d + 1) && check(a + (dir * 2), d + 2))
                {
                    if (n.x == xd && n.y == yd)
                    {
                        cout << d / 3 + 1 << '\n';
                        return 0;
                    }
                    M[n.x][n.y] = 1;
                    Q.emplace(n, d + 3);
                }
            }
        }
        Q.emplace(a, d + 3);
    }
}
