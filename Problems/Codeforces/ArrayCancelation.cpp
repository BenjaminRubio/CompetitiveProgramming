#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

        ll ans = LLONG_MAX, s = 0;
        rep(i, N) s += A[i], ans = min(ans, s);

        cout << -ans << '\n';
    }
}