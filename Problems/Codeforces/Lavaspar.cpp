#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int L, C, N; string s;
vector<string> M;
vector<vector<int>> O;

int main()
{
    cin >> L >> C;

    M.resize(L);
    rep(i, L) cin >> M[i];

    O.assign(L, vector<int>(C, 0));

    cin >> N;
    rep(_, N)
    {
        cin >> s; int l = s.size();
        vector<int> T(26, 0); rep(x, l) T[s[x] - 'A']++;

        vector<vector<bool>> OO(L, vector<bool>(C, 0));

        rep(i, L) rep(j, C)
        {
            if (L - i >= l)
            {
                vector<int> t(26, 0);
                rep(x, l) t[M[i + x][j] - 'A']++;

                bool is = 1;
                rep(x, 26) if (T[x] != t[x]) is = 0;

                if (is) rep(x, l) OO[i + x][j] = 1;
            }
            if (C - j >= l)
            {
                vector<int> t(26, 0);
                rep(x, l) t[M[i][j + x] - 'A']++;

                bool is = 1;
                rep(x, 26) if (T[x] != t[x]) is = 0;

                if (is) rep(x, l) OO[i][j + x] = 1;
            }
            if (L - i >= l && C - j >= l)
            {
                vector<int> t(26, 0);
                rep(x, l) t[M[i + x][j + x] - 'A']++;

                bool is = 1;
                rep(x, 26) if (T[x] != t[x]) is = 0;

                if (is) rep(x, l) OO[i + x][j + x] = 1;
            }
            if (i >= l - 1 && C - j >= l)
            {
                vector<int> t(26, 0);
                rep(x, l) t[M[i - x][j + x] - 'A']++;

                bool is = 1;
                rep(x, 26) if (T[x] != t[x]) is = 0;

                if (is) rep(x, l) OO[i - x][j + x] = 1;
            }
        }

        rep(i, L) rep(j, C) O[i][j] += OO[i][j];
    }

    int ans = 0;
    rep(i, L) rep(j, C) if (O[i][j] > 1) ans++;

    cout << ans << '\n';
}