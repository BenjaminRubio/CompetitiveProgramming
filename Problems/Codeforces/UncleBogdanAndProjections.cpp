#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N;
vector<pair<pair<ld, ld>, ld>> C;
vector<pair<ld, int>> v;
vector<ld> p;

ld get_diff(ld proj)
{
    ld m = 1e15, M = -1e15;
    rep(i, N)
    {
        m = min(m, C[i].ff.ff + proj * C[i].ss);
        M = max(M, C[i].ff.ss + proj * C[i].ss);
    }
    return M - m;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(8);

    cin >> N;

    C.resize(N);
    rep(i, N) cin >> C[i].ff.ff >> C[i].ff.ss >> C[i].ss;

    bool on = false;
    rep(i, N) rep(j, N) if (C[i].ss > C[j].ss)
    {
        v.emplace_back((C[j].ff.ff - C[i].ff.ss) / (C[i].ss - C[j].ss),  1);
        v.emplace_back((C[j].ff.ss - C[i].ff.ff) / (C[i].ss - C[j].ss), -1);
        on = true;
    }
    
    if (!on) p.push_back(0);
    else
    {
        sort(v.begin(), v.end());

        int on = 0;
        for (auto &e : v)
        {
            if (e.ss ==  1 && on == 0) p.push_back(e.ff);
            if (e.ss == -1 && on == 1) p.push_back(e.ff);
            on += e.ss;
        }
    }

    int l = 0, r = p.size() - 1;
    while (r - l > 2)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        ld v1 = get_diff(p[m1]);
        ld v2 = get_diff(p[m2]);

        if (v1 <= v2) r = m2;
        if (v2 <= v1) l = m1;
    }

    ld ans = 1e15;
    for (int i = l; i <= r; i++) ans = min(ans, get_diff(p[i]));

    cout << ans << '\n';
}