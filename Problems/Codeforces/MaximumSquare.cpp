#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int k, n;
vector<int> a;

int main()
{
    cin >> k;
    rep(_, k)
    {
        cin >> n;
        a.resize(n);

        rep(i, n) cin >> a[i];

        sort(a.begin(), a.end());

        rep(i, n) if (a[i] >= n - i)
        {
            cout << n - i << '\n';
            break;
        }
    }
}