#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, f;
vector<int> g;
vector<bool> r;
set<int> remaining_giv, remaining_rec;

int main()
{
    cin >> n;

    g.assign(n, 0);
    r.assign(n, false);

    rep(i, n)
    {
        cin >> f;
        if (f != 0)
        {
            g[i] = f;
            r[f - 1] = true;
        }
    }

    rep(i, n)
        if (g[i] == 0 && r[i] == false)
            remaining_giv.insert(i);

    rep(i, n)
        if (r[i] == false)
            remaining_rec.insert(i);

    rep(i, n)
    {
        if (g[i] == 0)
        {
            bool done = false;
            for (int e : remaining_giv)
            {
                if (e != i)
                {
                    g[i] = e + 1;
                    remaining_giv.erase(e);
                    remaining_rec.erase(e);
                    done = true;
                    break;
                }
            }
            if (done)
            {
                remaining_giv.erase(i);
                continue;
            }
            for (int e : remaining_rec)
            {
                if (e != i)
                {
                    g[i] = e + 1;
                    remaining_rec.erase(e);
                    break;
                }
            }
            remaining_giv.erase(i);
        }
    }

    rep(i, n)
        cout << g[i] << ' ';
    cout << '\n';
}