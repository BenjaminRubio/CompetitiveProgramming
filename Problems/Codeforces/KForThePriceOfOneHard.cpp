#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, p, K;
vector<int> a;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> p >> K;

        a.resize(n);
        rep(i, n) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = 0;
        rep(k, K)
        {
            int aux = 0;
            int count = 0;
            int i = 1;
            while (K * i + k - 1 < n)
            {
                count += a[K * i + k - 1];
                if (count <= p)
                    aux = K * i;
                else
                {
                    count -= a[K * i + k - 1];
                    break;
                }
                i++;
            }
            rep(i, k)
            {
                count += a[i];
                if (count <= p)
                    aux++;
                else
                    break;
            }
            ans = max(ans, aux);
        }

        cout << ans << '\n';
    }
}