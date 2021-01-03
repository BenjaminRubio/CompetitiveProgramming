#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> S; N = S.size();

        int ll = -1, l = -1, b = 0, ans = 0;
        rep(i, N)
        {
            if (S[i] == ll || (!b && S[i] == l))
            {
                ans++, b = 1;
                ll = l, l = -1;
                continue;
            }
            if (b) b = 0;
            ll = l, l = S[i];
        }

        cout << ans << '\n';
    }
}