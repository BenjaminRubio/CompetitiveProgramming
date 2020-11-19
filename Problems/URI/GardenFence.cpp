#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

typedef ll T; struct P
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
    bool operator==(const P &p) const
    {
        return !((*this) < p) && !(p < (*this));
    }
    T norm2() const { return x * x + y * y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N, M;
vector<P> p;
vector<int> V;

int main()
{
    while (cin >> N >> M && N)
    {
        p.resize(N + M); V.resize(N + M); int l = 0, l_ = 0;
        rep(i, N + M)
        {
            cin >> p[i] >> V[i];
            if (i < N) l_ += V[i];
            else l += V[i];
        }

        int ans = min(l, l_);
        rep(i, N)
        {
            vector<pair<pair<P, ll>, int>> E;
            rep(j, N + M) if (i != j)
                E.emplace_back(mp(p[j] - p[i], (p[j] - p[i]).norm2()), j);

            sort(E.begin(), E.end());
            rep(j, N + M - 1) E.push_back(E[j]);

            int j = 0, k = 0, L = l;
            while (j < N + M - 1)
            {
                while (k < (j + N + M - 1) && ((E[j].ff.ff ^ E[k].ff.ff) > 0 || E[j].ff.ff == E[k].ff.ff))
                    L += V[E[k].ss] * (E[k].ss < N ? 1 : -1), k++;

                ans = min(ans, L);

                int t = j;
                while (j < N + M - 1 && E[j].ff.ff == E[t].ff.ff)
                    L += V[E[j].ss] * (E[j].ss < N ? -1 : 1), j++;
            }
        }

        cout << ans << '\n';
    }
}