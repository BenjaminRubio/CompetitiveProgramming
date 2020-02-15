#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
string s;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> s;

        stack<int> sl, sh, sh_;
        sh_.push(0);
        rep(i, n - 1)
        {
            if (s[i] == '>')
            {
                while (!sh_.empty()) { sh.push(sh_.top()); sh_.pop(); }
                sl.push(i + 1);
            }
            else sh_.push(i + 1);
        }
        while (!sh_.empty()) { sh.push(sh_.top()); sh_.pop(); }

        stack<int> q;
        queue<int> sl_, qh;
        qh.push(0);
        rep(i, n - 1)
        {
            if (s[i] == '>') q.push(i + 1);
            else
            {
                while (!q.empty()) { sl_.push(q.top()); q.pop(); }
                qh.push(i + 1);
            }
        }
        while (!q.empty()) { sl_.push(q.top()); q.pop(); }

        vector<int> ansl(n), ansh(n);
        int i = 1;
        while (!sl.empty()) { ansl[sl.top()] = i++; sl.pop(); }
        while (!sh.empty()) { ansl[sh.top()] = i++; sh.pop(); }
        i = 1;
        while (!sl_.empty()) { ansh[sl_.front()] = i++; sl_.pop(); }
        while (!qh.empty()) { ansh[qh.front()] = i++; qh.pop(); }

        rep(i, n) cout << ansl[i] << ' ';
        cout << '\n';
        rep(i, n) cout << ansh[i] << ' ';
        cout << '\n';
    }
}