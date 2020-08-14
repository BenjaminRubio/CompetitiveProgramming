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

        priority_queue<int> q;

        int c = 0, l = 0;
        for (char ch : s)
        {
            if (ch == '1') c++;
            if (ch == '0' && l == 1) { q.push(c); c = 0; }
            l = ch - '0';
        }
        if (l == 1) { q.push(c); c = 0; }

        int ans = 0;
        while (!q.empty()) { ans += q.top(); q.pop(); if (!q.empty()) q.pop(); }
        
        cout << ans << '\n';
    }
}