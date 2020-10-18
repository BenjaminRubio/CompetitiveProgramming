#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;

vector<int> match(string &p, string &t)
{
    int n = p.size(), m = t.size(), L[n]; L[0] = 0;
    rep(j, n - 1)
    {
        int i = L[j]; while (p[i] != p[j + 1] && i) i = L[i - 1];
        L[j + 1] = p[i] == p[j + 1] ? i + 1 : 0;
    }
    vector<int> ans; int i = 0; rep(j, m)
    {
        while (p[i] != t[j] && i) i = L[i - 1];
        if (p[i] == t[j] && ++i == n) i = L[n - 1], ans.push_back(j - n + 1);
    }
    return ans;
}

string S;

int main()
{
    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> S; int N = S.size();

        string t = "START", s = "KICK";
        vector<int> C = match(t, S);
        reverse(C.begin(), C.end());

        vector<int> O(N + 1, 0);
        int i = N - 1;
        for (int j : C)
        {
            while (i > j) O[i] = O[i + 1], i--;
            O[i] = O[i + 1] + 1, i--;
        }
        while (i >= 0) O[i] = O[i + 1], i--;

        vector<int> C_ = match(s, S);
        ll ans = 0;
        for (int j : C_) ans += O[j];

        cout << ans << '\n';
    }
}