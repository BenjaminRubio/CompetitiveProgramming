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
        rep(i, n) cin >> a[i];

        bool can1 = false, can2 = false;
        if (n == 1 && k == a[0]) can2 = true;

        int l1 = -1, l2 = -1;
        rep(i, n)
        {
            if (a[i] == k) can1 = true;
            if (a[i] >= k && max(l1, l2) >= k) can2 = true;
            l2 = l1; l1 = a[i];
        }

        if (can1 && can2) cout << "yes\n";
        else cout << "no\n";
    }
}