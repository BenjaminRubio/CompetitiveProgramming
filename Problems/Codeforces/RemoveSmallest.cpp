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

        sort(A.begin(), A.end());

        int l = -1, ans = 0;
        for (int x : A)
        {
            if (x > l + 1) ans++;
            l = x;
        }

        cout << (ans == 1 ? "YES" : "NO") << '\n';
    }
}