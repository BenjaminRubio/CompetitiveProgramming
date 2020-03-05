#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

int T, n;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    rep(_, T)
    {
        cin >> n;
        cin >> s;

        set<pair<string, int>> st;
        rep(i, n)
        {
            string aux = "";
            repx(j, i, n) aux += s[j];
            if ((n - i) % 2 == 1) rep_(j, i) aux += s[j];
            else rep(j, i) aux += s[j];
            st.emplace(aux, i);
        }

        pair<string, int> ans = *st.begin();
        cout << ans.first << '\n';
        cout << ans.second + 1 << '\n';
    }
}