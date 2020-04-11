#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n;

        string s;
        vector<string> start, mid, end;
        rep(i, n)
        {
            cin >> s;
            string aux, m;
            bool f = true;
            for (char c : s)
            {
                if (c == '*' and f)
                {
                    if (!aux.empty()) { start.push_back(aux); aux.clear(); }
                    f = false; 
                    continue;
                }
                if (c == '*')
                {
                    m += aux;
                    aux.clear();
                }
                else aux += c;
            }
            if (!aux.empty()) end.push_back(aux);
            mid.push_back(m);
        }

        string ans, p1, p2;
        bool pos = true;
        for (string s_ : start)
        {
            rep(i, min(s_.size(), p1.size())) if (s_[i] != p1[i]) pos = false;
            if (s_.size() > p1.size()) p1 = s_;
        }

        for (string s_ : end)
        {
            rep(i, min(s_.size(), p2.size())) if (s_[s_.size() - i - 1] != p2[p2.size() - i - 1]) pos = false;
            if (s_.size() > p2.size()) p2 = s_;
        }

        cout << "Case #" << t + 1 << ": ";
        if (!pos)
        {
            cout << "*\n";
            continue;
        }

        ans = p1;
        for (string s_ : mid) ans += s_;
        ans += p2;

        cout << ans << '\n';
    }
}