#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string s;
vector<int> l, r;

int main()
{
    cin >> s;
    int n = s.size();

    l.assign(n + 1, 0);
    r.assign(n + 1, 0);

    l[0] = 0;
    rep(i, n)
    {
        if (s[i] == '(') l[i + 1] = l[i] + 1;
        else l[i + 1] = l[i];
    }
    r[n] = 0;
    rep(i, n)
    {
        if (s[n - i - 1] == ')') r[n - i - 1] = r[n - i] + 1;
        else r[n - i - 1] = r[n - i];
    }

    rep(i, n + 1)
    {
        if (l[i] == r[i])
        {
            if (l[i] == 0)
            {
                cout << 0 << '\n';
                return 0;
            }
            cout << 1 << '\n';
            cout << l[i] + r[i] << '\n';
            rep(j, n)
            {
                if (j < i and s[j] == '(') cout << j + 1 << ' ';
                if (j >= i and s[j] == ')') cout << j + 1 << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
}