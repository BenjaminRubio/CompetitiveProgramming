#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;

        int ans = INT_MAX, cnt = 0;
        bool f = true;
        char lt, l;
        rep(i, s.size())
        {
            if (i == 0) l = s[i], cnt++;
            else if (l != s[i])
            {
                if (f) f = 0;
                else 
                {
                    if (lt != l && lt != s[i])
                        ans = min(ans, cnt + 2);
                }
                lt = l, l = s[i], cnt = 0;
            }
            cnt++;
        }

        if (ans == INT_MAX) cout << 0 << '\n';
        else cout << ans << '\n';
    }
}