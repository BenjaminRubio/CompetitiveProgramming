#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A;

int DP[200010];

int dp(int i)
{
    if (i >= N) return 0;
    if (DP[i] != -1) return DP[i];

    return DP[i] = A[i] + dp(i + A[i]);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N); rep(i, N) cin >> A[i];

        rep(i, N) DP[i] = -1;
        
        int ans = 0;
        rep(i, N) ans = max(ans, dp(i));

        cout << ans << '\n';
    }
}
