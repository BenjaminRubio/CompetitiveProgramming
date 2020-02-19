#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, d;
vector<int> a;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> d;

        a.resize(n);
        rep(i, n) cin >> a[i];

        int ans = a[0], aux = 0;
        rep(i, n)
        {
            if (!i) continue; 
            int c = min(a[i], (d - aux) / i);
            aux += c * i;
            ans += c;
        }

        cout << ans << '\n';
    }
}