#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m;
set<string> w;
string s, mid;

int main()
{
    cin >> n >> m;

    string start;
    stack<string> end;
    rep(i, n)
    {
        cin >> s;
        string s_;
        rep(j, m) s_ += s[m - j - 1];
        if (w.find(s_) != w.end())
        {
            w.erase(s);
            start += s;
            end.push(s_);
        }
        else w.insert(s);
    }
    
    for (string s : w)
    {
        bool pal = true;
        rep(i, m / 2) if (s[i] != s[m - i - 1]) pal = false;

        if (pal) { start += s; break; }
    }

    while (!end.empty()) { start += end.top(); end.pop(); }

    cout << start.size() << '\n';
    cout << start << '\n';
}