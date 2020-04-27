#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
string t;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> t;
        int n = t.size();
        string s;

        bool one = false, zero = false;
        rep(i, n)
        {
            if (t[i] == '0') zero = true;
            if (t[i] == '1') one = true;
        }

        if (!one or !zero) { cout << t << '\n'; continue; }

        bool on = (t[0] == '1');
        rep(i, n)
        {
            if (on and t[i] == '0') s += '1';
            else if (!on and t[i] == '1') s += '0';
            else on = !on;
            s += t[i];
        }

        cout << s << '\n';
    }
}