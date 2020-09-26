#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<vector<int>> M;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> N;

        M.assign(N, vector<int>(N));
        rep(i, N) rep(j, N) cin >> M[i][j];

        int R = 0, C = 0;
        rep(i, N)
        {
            set<int> sr, sc;
            rep(j, N) { sr.insert(M[i][j]); sc.insert(M[j][i]); }
            if (sr.size() < N) R++;
            if (sc.size() < N) C++;
        }

        int k = 0;
        rep(i, N) k += M[i][i];

        cout << "Case #" << t + 1 << ": " << k << ' ' << R << ' ' << C << '\n';
    }
}