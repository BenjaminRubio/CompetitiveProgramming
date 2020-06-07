#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        a.resize(n);
        rep(i, n) cin >> a[i];

        b.resize(n);
        rep(i, n) cin >> b[i];

        if (n & 1 && a[n / 2] != b[n / 2]) { cout << "No\n"; continue; }

        vector<pair<int, int>> pa, pb;
        rep(i, n / 2) pa.emplace_back(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1]));
        rep(i, n / 2) pb.emplace_back(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]));

        sort(pa.begin(), pa.end());
        sort(pb.begin(), pb.end());

        bool flag = true;
        rep(i, n / 2) if (pa[i] != pb[i]) flag = false;

        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
}