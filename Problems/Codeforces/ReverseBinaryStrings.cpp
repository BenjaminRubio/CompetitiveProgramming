#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N; string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> s;

        int c = 0, l = -1;
        rep(i, N)
        {
            if (l == s[i] && s[i] == '1') c++;
            l = s[i];
        }
        if (l == s[0] && s[0] == '1') c++;

        cout << c << '\n';
    }
}