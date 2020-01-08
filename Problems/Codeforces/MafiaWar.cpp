#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long N, S;
vector<long long> C;

int main()
{
    cin >> N >> S;

    C.resize(N - 1);
    rep(i, N - 1) cin >> C[i];

    sort(C.begin(), C.end());

    S += N - 1;

    rep(i, N - 1)
        S -= (N - 1 - i) * C[i];

    if (S > 0)
        cout << "SI\n";
    else
        cout << "NO\n";
}