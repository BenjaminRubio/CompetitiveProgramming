#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, k;
vector<int> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        a.resize(n);
        rep(i, n)
        {
            char x; cin >> x;
            a[i] = (x - 'a');
        }
        sort(a.begin(), a.end());

        if (a[0] == a[k - 1])
        {
            bool more = false;
            if (n > k) rep(i, n) if (i > k and a[i] != a[k]) more = true;

            if (more)
            {
                rep(i, n) if (i >= k - 1) cout << char(a[i] + 'a');
                cout << '\n';
            }
            else
            {
                int r = (n - k) / k + bool((n - k) % k);
                cout << char(a[k - 1] + 'a');
                rep(i, r) cout << char(a[k] + 'a');
                cout << '\n';
            }
        }
        else cout << char(a[k - 1] + 'a') << '\n';
    }
}