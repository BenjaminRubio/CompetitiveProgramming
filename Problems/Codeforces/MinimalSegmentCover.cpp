#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, l, r;
vector<int> L, R;
vector<pair<int, pair<int, int>>> E;

int Nx[500010][20];

int main()
{
    cin >> N >> M;

    L.resize(N), R.resize(N);
    rep(i, N)
    {
        cin >> l >> r;
        L[i] = l, R[i] = r;
        E.emplace_back(l, make_pair(0, i));
        E.emplace_back(r, make_pair(1, i));
    }

    sort(E.begin(), E.end());

    int i = 0, j = 0;
    multiset<int> S;
    while (j < 2 * N)
    {
        int now = E[j].ff;
        while (i < now) Nx[i++][0] = (S.empty() ? -1 : *S.rbegin());
        while (j < 2 * N && E[j].ff == now)
        {
            if (E[j].ss.ff == 0) S.insert(R[E[j].ss.ss]);
            if (E[j].ss.ff == 1) S.erase(S.find(R[E[j].ss.ss]));
            j++;
        }
        Nx[i++][0] = (S.empty() ? -1 : *S.rbegin());
    }
    while (i < 500001) Nx[i++][0] = -1;

    rep(k, 20) if (k)
    {
        rep(i, 500001) 
        {
            int x = Nx[i][k - 1];
            if (x == -1) Nx[i][k] = -1;
            else Nx[i][k] = Nx[x][k - 1];
        }
    }

    rep(_, M)
    {
        cin >> l >> r;

        int ans = 0;
        for (int k = 19; k >= 0; k--) if (Nx[l][k] != -1 && Nx[l][k] < r) 
        {
            l = Nx[l][k];
            ans += (1 << k);
        }

        if (Nx[l][0] >= r) cout << ans + 1 << '\n';
        else cout << -1 << '\n';
    }
}