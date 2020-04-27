#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

int n, k, x;
vector<int> s, m;

int main()
{
    cin >> n >> k;

    s.assign(k, 0);
    rep(i, n)
    {
        cin >> x;
        s[x - 1]++;
    }

    int aux = INT_MAX;
    m.assign(k + 1, 0);
    rep(i, k)
    {
        cin >> x; aux = min(x, aux);
        m[i] = aux;
    }
    
    int f = 0, fr = 0;
    vector<vector<int>> ans(n);
    vector<vector<int>> r(n);
    rep_(i, k) if (s[i])
    {

        int left = 0, right = f;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (ans[mid].size() < m[i]) right = mid;
            else left = mid + 1;
        }

        repx(j, left, f) rep(_, m[i] - ans[j].size())
        {
            ans[j].push_back(i + 1);
            s[i]--;
            if (s[i] == 0) goto next;
        }
        next:

        if (s[i] == 0) continue;

        int d = s[i] / m[i];
        while (d--)
        {
            rep(_, m[i]) ans[f].push_back(i + 1);
            f++;
        }

        int rest = s[i] % m[i];
        if (rest)
        {
            rep(j, fr) rep(_, m[i] - r[j].size())
            {
                r[j].push_back(i + 1);
                rest--;
                if (rest == 0) goto next2;
            }
        }

        next2:

        if (rest) while (rest)
        {
            if (r[fr].size() < m[i]) { r[fr].push_back(i + 1); rest--; }
            else fr++;
        }
    }

    cout << f + fr + bool(r[fr].size()) << '\n';
    rep(i, f)
    {
        cout << ans[i].size() << ' ';
        for (int x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
    rep(i, fr)
    {
        cout << r[i].size() << ' ';
        for (int x : r[i]) cout << x << ' ';
        cout << '\n';
    }
    if (r[fr].size())
    {
        cout << r[fr].size() << ' ';
        for (int x : r[fr]) cout << x << ' ';
        cout << '\n';
    }
}