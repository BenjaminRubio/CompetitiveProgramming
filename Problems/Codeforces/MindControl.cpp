#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int t, n, m, k;
vector<int> a;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        k = min(k, m - 1);

        a.resize(n);
        rep(i, n) cin >> a[i];

        SparseTable<Min> st(a);

        int ans = -1;
        rep(i, k + 1)
        {
            int aux = INT_MAX;
            repx(j, i, i + m - k)
                aux = min(aux, max(a[j], a[j + n - m]));

            ans = max(ans, aux);
        }

        cout << ans << '\n';
    }
}