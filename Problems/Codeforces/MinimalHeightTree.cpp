#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        int ans = 0, p = 1, n = 0, l = -1;
        rep(i, N) if (i)
        {
            if (A[i] > l) n++;
            else if (A[i] < l && p > 1) p--, n++;
            else if (A[i] < l && p == 1) p = n, n = 1, ans++;
            l = A[i];
        }
        if (n) ans++;

        cout << ans << '\n';
    }
}