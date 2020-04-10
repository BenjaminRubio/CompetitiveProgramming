
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef long double ld;

const ld PI = 3.141592653589793238462643383279502884L;
const ld EPS = 1e-12;

struct P
{
    ld x, y, r;
    ld norm() { return sqrt(x * x + y * y); }
    ld ang() { return atan2(y, x); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y >> p.r; }

int T, n;
ld R;
vector<P> C;

ld ang(ld x)
{
    while (x < 0) x += 2. * PI;
    while (x >= 2. * PI) x -= 2. * PI;
    return x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    cin >> T;
    rep(t, T)
    {
        cin >> n >> R;

        C.resize(n);
        rep(i, n) cin >> C[i];

        vector<pair<ld, bool>> s;
        rep(i, n)
        {
            if (C[i].r + C[i].norm() < R + EPS) continue;
            if (C[i].r + R < C[i].norm() + EPS) continue;

            ld d = C[i].norm();
            ld r = C[i].r;
            ld a = acos((R * R + d * d - r * r) / (2. * R * d));

            s.emplace_back(ang(C[i].ang() - a), 0);
            s.emplace_back(ang(C[i].ang() + a), 1);
        }

        sort(s.begin(), s.end());

        int N = s.size();
        rep(i, N) s.emplace_back(s[i].ff + 2. * PI, s[i].ss);

        int j = 0;
        ld ans = -1.;
        rep(i, N)
        {
            while (s[j].ff < s[i].ff + PI) j++;

            if (!s[j].ss and s[j - 1].ss) ans = max(ans, 2. * R);
            ans = max({ans, 2. * R * cos((s[j].ff - (s[i].ff + PI)) / 2.),
                        2. * R * cos(((s[i].ff + PI) - s[j - 1].ff) / 2.)});
        }

        cout << "Case #" << t + 1 << ": " << ans << '\n';
    }
}