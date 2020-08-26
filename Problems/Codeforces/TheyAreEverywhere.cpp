#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
string S;
set<char> C;
map<char, vector<int>> M;

int main()
{
    cin >> N >> S;

    for (char c : S) C.insert(c);

    for (char c : C)
    {
        M[c].assign(N + 1, 0);
        rep(i, N) M[c][i + 1] = M[c][i] + (S[i] == c);
    }

    int ans = INT_MAX;
    rep(i, N)
    {
        int l = i + 1, r = N;
        while (l < r)
        {
            int m = (l + r) / 2;

            bool flag = 1;
            for (char c : C) if (M[c][m] - M[c][i] < 1) flag = 0;

            if (flag) r = m;
            else l = m + 1;
        }

        bool flag = 1;
        for (char c : C) if (M[c][l] - M[c][i] < 1) flag = 0;

        if (flag) ans = min(ans, l - i);
    }

    cout << ans << '\n';
}