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

        sort(A.rbegin(), A.rend());

        int s = 0; bool ok = 0;
        rep(i, N) s += A[i], ok |= (s == 0);

        if (!ok) { cout << "YES\n"; rep(i, N) cout << A[i] << ' '; cout << '\n'; continue; }

        reverse(A.begin(), A.end());

        s = 0, ok = 0;
        rep(i, N) s += A[i], ok |= (s == 0);

        if (!ok) { cout << "YES\n"; rep(i, N) cout << A[i] << ' '; cout << '\n'; }
        else cout << "NO\n";
    }
}