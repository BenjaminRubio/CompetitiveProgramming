#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

string s;
vector<ll> c(26, 0);
vector<vector<ll>> aux;

int main()
{
    cin >> s;
    int n = s.size();

    aux.assign(n, {});
    rep(i, n)
    {
        c[s[i] - 'a']++;
        aux[i] = c;
    }

    ll ans = 0;
    rep(i, 26) ans = max(ans, c[i]);

    rep(i, 26) rep(j, 26)
    {
        ll partial = 0;
        rep(k, n) if (s[k] == char(j + 'a')) partial += (aux[k][i] - (i == j));
        ans = max(ans, partial);
    }

    cout << ans << '\n';
}