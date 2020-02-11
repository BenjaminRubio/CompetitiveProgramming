#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

string s;

bool isvowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' ||  c == 'o' || c == 'u';
}

int main()
{
    while (cin >> s)
    {
        int v = 0;
        for (char c : s) if (isvowel(c)) v++;

        if (v and !isvowel(s[0]))
        {
            cout << 0 << '\n';
            continue;
        }
        if (!v)
        {
            cout << 1 << '\n';
            continue;
        }
        
        int ans = 0;
        int aux = 0;
        for (char c : s)
        {
            if (isvowel(c)) aux++;
            if (aux == v - v / 2) ans++;
        }

        cout << ans << '\n';
    }
}