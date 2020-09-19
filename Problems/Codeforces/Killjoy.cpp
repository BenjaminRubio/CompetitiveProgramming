#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X;
vector<int> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> X;

        A.resize(N); multiset<int> s;
        rep(i, N) { cin >> A[i]; s.insert(A[i]); }

        if (s.count(X) == N && A[0] == X) { cout << 0 << '\n'; continue; }
        if (s.count(X) > 1) { cout << 1 << '\n'; continue; }
        if (s.count(X) == 0)
        {
            int s = 0;
            rep(i, N) s += A[i] - X;
            if (s == 0) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        else cout << 1 << '\n';
    }
}