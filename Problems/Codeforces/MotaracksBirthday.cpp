#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;
vector<int> a;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    rep(t, T)
    {
        cin >> n;
        
        a.resize(n);
        rep(i, n) cin >> a[i];

        double l = 0, r = 1000000000;
        rep(j, 500)
        {
            double t = (r - l) / 3.0;
            double m1 = l + t;
            double m2 = r - t;

            double M1 = 0, M2 = 0;
            rep(i, n - 1)
            {
                M1 = max(M1, abs(((a[i] == -1) ? m1 : a[i]) - ((a[i + 1] == -1) ? m1 : a[i + 1])));
                M2 = max(M2, abs(((a[i] == -1) ? m2 : a[i]) - ((a[i + 1] == -1) ? m2 : a[i + 1])));
            }
        
            if (M1 < M2) r = m2;
            else if (M2 < M1) l = m1;
            else l = m1, r = m2;
        }

        l = round((l + r) * 0.5);

        double M = 0;
        rep(i, n - 1)
            M = max(M, abs(((a[i] == -1) ? l : a[i]) - ((a[i + 1] == -1) ? l : a[i + 1])));
        cout << (int)M << ' ' << (int)l << '\n';
    }
}