#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q, q;
vector<int> a;

int main()
{
    cin >> N >> Q;

    a.resize(N);
    rep(i, N) cin >> a[i];

    rep(i, Q)
    {
        cin >> q;

        int l = 0;
        int r = N; 
        while (l < r)
        {
            int m = (l + r) / 2;
            if (a[m] >= q)
                r = m;
            else
                l = m + 1;
        }
        if (a[l] == q)
            cout << l << '\n';
        else
            cout << -1 << '\n';
    }
}