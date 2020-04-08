#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll n, a;

int main()
{
    cin >> n;

    ll ans = 0, sum = 0;
    set<ll> S; S.insert(0);
    queue<ll> Q; Q.push(0);
    rep(_, n)
    {
        cin >> a;
        sum += a;
        
        if (S.count(sum)) while (S.count(sum))
        {
            ans += S.size() - 1;
            S.erase(Q.front()); Q.pop();
        }
        S.insert(sum); Q.push(sum);
    }
    ans += ((ll) S.size() * ((ll) S.size() - 1ll)) / 2ll;

    cout << ans << '\n';
}