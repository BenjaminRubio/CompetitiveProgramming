#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, a, Q;
char ch;
map<ll, ll> C;

int main()
{
    cin >> N;

    ll c = 0, d = 0;
    rep(i, N)
    {
        cin >> a;
        C[a]++;
        if (C[a] % 2 == 0 && C[a] != 4) d++;
        if (C[a] == 4) c++, d--;
    }

    cin >> Q;
    rep(_, Q)
    {
        cin >> ch >> a;
        if (ch == '+')
        {
            C[a]++;
            if (C[a] % 2 == 0 && C[a] != 4) d++;
            if (C[a] == 4) c++, d--;
        }
        else
        {
            C[a]--;
            if (C[a] % 2 == 1 && C[a] != 3) d--;
            if (C[a] == 3) c--, d++;
        }

        if (c && ((c - 1) * 2 + d) >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}