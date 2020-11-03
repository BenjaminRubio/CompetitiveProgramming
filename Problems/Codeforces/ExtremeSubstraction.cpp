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

        int L = 0; bool flag = 1;
        for (int i = N - 1; i > 0; i--)
        {
            if (A[i - 1] > A[i] - L) L = max(L, A[i - 1] - (A[i] - L));
            if (A[i - 1] - L < 0) flag = 0;
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}