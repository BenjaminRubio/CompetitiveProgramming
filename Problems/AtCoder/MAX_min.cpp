#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> A;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    while (1)
    {
        int m = INT_MAX, M = INT_MIN;
        rep(i, N) m = min(A[i], m), M = max(A[i], M);

        if (m == M) { cout << m << '\n'; return 0; }

        rep(i, N) A[i] = (A[i] % m ? A[i] % m : m);
    }
}