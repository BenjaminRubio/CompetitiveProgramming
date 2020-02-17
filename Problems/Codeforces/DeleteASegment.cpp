#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Segment
{
    int l, r, id;
    Segment() {}
    bool operator<(const Segment &s)
    {
        return l < s.l or (l == s.l and r > s.r);
    }
};

int T, n, l, r;
vector<Segment> S;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;
        S.resize(n);
        rep(i, n)
        {
            cin >> l >> r;
            S[i].l = l; S[i].r = r; S[i].id = i;
        }

        sort(S.begin(), S.end());

        int tot = 0, lastl = INT_MIN, lastr = INT_MIN, M = 0;
        int max1 = INT_MIN, max2 = INT_MIN, id;
        vector<int> aux(n, 0);
        queue<pair<int, int>> q;
        bool up = false;
        for (Segment s : S)
        {
            if (s.l != lastl) while (!q.empty())
            {
                pair<int, int> f = q.front();
                if (f.ff >= max1)
                {
                    max2 = max1;
                    max1 = f.ff; id = f.ss;
                }
                else if (f.ff > max2) { max2 = f.ff; }
                q.pop();
            }
            
            int c = (s.l <= max1) + (s.l <= max2);
            if (s.l != lastl and c == 1 and !up) aux[id]++;
            if (s.l != lastl and !c) { tot++; up = true; }
            else up = false;

            q.push({s.r, s.id});
            lastl = s.l; lastr = s.r;
        }

        if (tot == n) { cout << n - 1 << '\n'; continue; }
        int ans = 0;
        rep(i, n) ans = max(ans, tot + aux[i]);

        cout << ans << '\n';
    }
}