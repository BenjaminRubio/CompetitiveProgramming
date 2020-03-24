#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, n, k;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> k;

        if (n % 2ll == k % 2ll and n >= k * k) cout << "YES\n";
        else cout << "NO\n";
    }
}