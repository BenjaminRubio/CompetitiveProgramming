#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N1, N2;
vector<int> C1, C2, ans;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N1; C1.resize(N1 + 1);
        rep(i, N1 + 1) cin >> C1[i];

        cin >> N2; C2.resize(N2 + 1);
        rep(i, N2 + 1) cin >> C2[i];

        ans.assign(N1 + N2 + 1, 0);
        rep(i, N1 + 1) rep(j, N2 + 1)
            ans[i + j] += C1[i] * C2[j];

        cout << N1 + N2 << '\n';
        rep(i, N1 + N2 + 1) cout << ans[i] << ' ';
        cout << '\n';
    }
}