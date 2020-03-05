#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
typedef long long ll;

int n, m, p;
vector<ll> a, b;
ll ans;

int main()
{
    scanf("%d %d %d", &n, &m, &p);

    a.resize(n);
    rep(i, n) scanf("%d", &a[i]);

    b.resize(m);
    rep(i, m) scanf("%d", &b[i]);

    if (n < m) swap(a, b);
    if (n < m) swap(n, m);

    rep(i, n + m - 1)
    {
        ans = 0;
        repx(j, max(i - m + 1, 0), min(max(i - m + 1, 0) + min(i + 1, m), n)) ans += a[j] * b[i - j];
        if (ans % p)
        {
            printf("%d\n", i);
            return 0;
        }
    }
}