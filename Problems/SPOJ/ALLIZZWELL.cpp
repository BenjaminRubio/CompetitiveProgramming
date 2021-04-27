#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, R, C;
vector<string> M;
vector<vector<int>> V;
string A = "ALLIZZWELL";

int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {1, -1, 0, 1, -1, -1, 1, 0};

bool solve(int r, int c, int i)
{
    if (M[r][c] != A[i]) return false;
    if (i == 9) return true;
    rep(k, 8)
    {
        int r_ = r + dr[k], c_ = c + dc[k];
        if (r_ >= 0 && r_ < R && c_ >= 0 && c_ < C && !V[r_][c_])
        {
            V[r_][c_] = 1;
            if (solve(r_, c_, i + 1)) return true;
            V[r_][c_] = 0;
        }
    }
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> R >> C;
        
        M.resize(R);
        rep(i, R) cin >> M[i];

        V.assign(R, vector<int>(C, 0));
        
        bool ans = 0;
        rep(r, R) rep(c, C) if (solve(r, c, 0)) { ans = 1; goto next; }

        next:
        cout << (ans ? "YES" : "NO") << '\n';
    }
}