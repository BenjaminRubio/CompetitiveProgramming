#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (T i = 0; i < (T)n; i++)

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
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

T N;
vector<P> p;

int main()
{
    cin >> N;

    p.resize(N);
    rep(i, N) cin >> p[i];

    T ans = (N * (N - 1ll) * (N - 2ll) * (N - 3ll)) / 24ll;
    rep(i, N)
    {
        T aux = ((N - 1ll) * (N - 2ll) * (N - 3ll)) / 6ll;

        vector<P> v; int M = N - 1;
        rep(j, N) if (i != j) v.push_back(p[j] - p[i]);

        sort(v.begin(), v.end());

        T k = 0;
        rep(j, M)
        {
            while (k < j + M && (v[j] ^ v[k % M]) >= 0) k++;
            aux -= T((k - j - 1ll) * (k - j - 2ll)) / 2ll;
        }

        ans -= aux;
    }

    cout << ans << '\n';
}