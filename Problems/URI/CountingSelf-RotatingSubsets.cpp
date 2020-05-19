#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

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
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

const int MOD = 1e9 + 7;
const int MAXN = 1000;

int N;
vector<P> p, c;
vector<int> cnt;
set<P> s;
map<P, int> m;
int mul[MAXN + 1][MAXN + 1];

int main()
{
    cin >> N;

    repx(m, 1, MAXN + 1)
    {
        mul[m][0] = mul[m][m] = 1;
        repx(k, 1, m) mul[m][k] = (mul[m - 1][k] + mul[m - 1][k - 1]) % MOD;
    }

    p.resize(N);
    rep(i, N) cin >> p[i];

    rep(i, N) s.insert(p[i]);
    rep(i, N) repx(j, i + 1, N) m[(p[i] + p[j]) * 0.5] += 2;

    vector<pair<int, P>> aux;
    for (auto &e : m) aux.emplace_back(e.second, e.first);
    sort(aux.begin(), aux.end());

    for (auto &e : aux) c.push_back(e.second), cnt.push_back(e.first);
    int M = c.size();

    cout << N;

    int i = 0;
    repx(k, 2, N + 1)
    {
        while (i < M && cnt[i] < k - k % 2) i++;

        int ans = 0;
        repx(j, i, M) if (k % 2 == 0 || s.count(c[j]))
            ans = (ans + mul[cnt[j] / 2][(k - k % 2) / 2]) % MOD;

        cout << ' ' << ans;
    }
    cout << '\n';
}