#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        a.resize(n);
        rep(i, n) cin >> a[i];

        sort(a.begin(), a.end());

        bool d = true;
        int i = (n - 1) / 2, j = 1;
        cout << a[i] << ' ';
        while (j < n)
        {
            if (d) i += j;
            else i -= j;
            cout << a[i] << ' ';
            j++; d = !d;
        }
        cout << '\n';
    }
}