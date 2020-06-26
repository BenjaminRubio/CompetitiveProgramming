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
        int o = 0, c = 0;
        for (char ch : s)
        {
            if (ch == '1') o++;
            else c++;
        }

        if (min(o, c) % 2) cout << "DA\n";
        else cout << "NET\n";
    }
}