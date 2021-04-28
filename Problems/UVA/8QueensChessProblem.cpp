#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, r, c;
vector<int> aux;
set<vector<int>> ans;
vector<vector<int>> V;

void add(int i, int j, int c)
{
    rep(k, 8) V[i][k] += c;
    rep(k, 8) V[k][j] += c;
    if (i > j) rep(k, 8 - (i - j)) V[(i - j) + k][k] += c;
    else rep(k, 8 - (j - i)) V[k][(j - i) + k] += c;
    if (i + j < 8) rep(k, (i + j) + 1) V[(i + j) - k][k] += c;
    else rep(k, 14 - (i + j) + 1) V[7 - k][(i + j) - 7 + k] += c;
}

void solve(int k, int c)
{
    if (c == 7) { ans.insert(aux); return; }

    int i = k / 8, j = k % 8;
    if (k == 64) return;
    solve(k + 1, c);

    if (!V[i][j])
    {
        aux[j] = i + 1;
        add(i, j, 1); solve(k + 1, c + 1); add(i, j, -1);
    }
}

int main()
{
    cin >> T;
    
    aux.resize(8);
    while (T--)
    {
        ans.clear();

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        V.assign(8, vector<int>(8, 0));
        cin >> r >> c; add(r - 1, c - 1, 1);
        aux[c - 1] = r;

        solve(0, 0);

        int t = 0;
        for (auto &v : ans)
        {
            cout << (t < 9 ? " " : "") << ++t << "      ";
            rep(i, 8) cout << v[i] << (i < 7 ? " " : "");
            cout << '\n';
        }
        if (T) cout << '\n';
    }
}