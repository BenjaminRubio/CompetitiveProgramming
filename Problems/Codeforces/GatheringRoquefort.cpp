#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, D, s;
vector<int> R, S;

int main()
{
    cin >> N >> D;

    R.resize(N);
    rep(i, N) cin >> R[i];

    S.resize(N);
    rep(i, N) { cin >> s; S[i] = (s != -1) ? s - 1 : -1; }

    vector<int> ans(D, 0), aux(D, 0);
    rep(i, N)
    {
        int id = i;
        bool pos = true;
        rep(j, D)
        {
            if (j < D - 1 and S[id] == -1) { pos = false; break; }
            aux[D - j - 1] = R[id];
            id = S[id];
        }
        if (!pos) continue;

        bool flag = false;
        rep(i, D)
        {
            if (aux[i] > ans[i]) { flag = true; break; }
            if (aux[i] < ans[i]) break;
        }

        if (flag) swap(ans, aux);
    }

    rep(i, D) cout << ans[i] << ' ';
    cout << '\n';
}