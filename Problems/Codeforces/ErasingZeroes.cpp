#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string s;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> s;

        bool ones = false;
        int ans = 0, aux = 0;
        for (char c : s)
        {
            if (c == '1' and ones)
            {
                ans += aux;
                aux = 0;
            }
            if (c == '1') ones = true;
            if (c == '0' and ones) aux++;
        }

        cout << ans << '\n';
    }
}