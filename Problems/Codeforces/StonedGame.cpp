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

        int s = 0;
        rep(i, N - 1) s += A[i + 1];

        int t = 0, c = N - 1;
        if (A[0] > s || ((s + A[0]) & 1ll)) cout << "T\n";
        else cout << "HL\n";
    }
}