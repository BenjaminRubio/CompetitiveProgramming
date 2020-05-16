#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N, K;
double m;
vector<vector<P>> L, R;
vector<vector<double>> D;
vector<double> BL, BR;
P aux, first, last;

double DP[1 << 15][15];
bool V[1 << 15][15];

double dp(int b, int l)
{
    if (!b) return BR[l] + (R[l][0].x - L[l][0].x);

    if (V[b][l]) return DP[b][l];

    double ans = DBL_MAX;
    rep(i, N) if (b & (1 << i)) ans = min(ans, D[l][i] + dp(b ^ (1 << i), i));

    V[b][l] = 1;
    return DP[b][l] = ans + (R[l][0].x - L[l][0].x);
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);

    cin >> N;

    L.assign(N, {}); R.assign(N, {});
    rep(i, N)
    {
        cin >> K >> first;

        bool r = true;
        rep(_, K - 1)
        {
            cin >> aux;
            if (_ && r && aux.y == last.y) r = false;
            if (r) R[i].push_back(aux);
            else L[i].push_back(aux);
            last = aux;
        }
        L[i].push_back(first);
    }

    rep(i, N) reverse(L[i].begin(), L[i].end());

    D.assign(N, vector<double>(N));
    rep(i, N) rep(j, N) if (i != j)
    {
        int ii = 0, jj = 0;
        P p1 = R[i][ii++], p2 = R[i][ii++];
        P q1 = L[j][jj++], q2 = L[j][jj++];

        m = 0;
        while (true)
        {
            m = max(m, p1.x - R[i][0].x + L[j][0].x - q1.x);

            if (ii == R[i].size() && jj == L[j].size()) break;
            if (p2.y <= q2.y)
            {
                p1 = p2;
                p2 = R[i][ii++];
                q1 = q1 + (q2 - q1) * ((p1.y - q1.y) / (q2.y - q1.y));
            }
            else
            {
                q1 = q2;
                q2 = L[j][jj++];
                p1 = p1 + (p2 - p1) * ((q1.y - p1.y) / (p2.y - p1.y));
            }
        }
        m = max(m, p2.x - R[i][0].x + L[j][0].x - q2.x);

        D[i][j] = m;
    }

    BL.resize(N); BR.resize(N);
    rep(i, N)
    {
        m = 0;
        rep(ii, L[i].size()) m = max(m, L[i][0].x - L[i][ii].x);
        BL[i] = m;

        m = 0;
        rep(ii, R[i].size()) m = max(m, R[i][ii].x - R[i][0].x);
        BR[i] = m;
    }

    memset(V, 0, sizeof V);
    double ans = DBL_MAX;
    rep(i, N) ans = min(ans, dp(((1 << N) - 1) ^ (1 << i), i) + BL[i]);

    cout << ans << '\n';
}