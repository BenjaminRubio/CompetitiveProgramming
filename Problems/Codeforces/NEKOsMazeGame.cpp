#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, q, r, c;
vector<vector<bool>> m;

int main()
{
    cin >> n >> q;

    m.assign(2, vector<bool>(n, false));

    int count = 0;

    rep(i, q)
    {
        cin >> r >> c;
        r--; c--;

        int aux = 0;
        if (c > 0 && m[(r + 1) % 2][c - 1]) aux++;
        if (m[(r + 1) % 2][c]) aux++;
        if (c < n - 1 && m[(r + 1) % 2][c + 1]) aux++;

        if (m[r][c] == false)
            count += aux;
        else
            count -= aux;

        m[r][c] = !m[r][c];

        if (count) cout << "No\n";
        else cout << "Yes\n";
    }
}