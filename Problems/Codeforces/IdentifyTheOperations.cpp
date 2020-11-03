#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 998244353;

int T, N, K;
vector<int> A, B, P;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        A.resize(N); P.resize(N);
        rep(i, N)
        {
            cin >> A[i]; A[i]--;
            P[A[i]] = i;
        }

        B.resize(K);
        rep(i, K) { cin >> B[i]; B[i]--; }

        set<int> S; ll ans = 1;
        for (int i = K - 1; i >= 0; i--)
        {
            int p = P[B[i]]; ll now = 0;
            if (p > 0) now += (S.count(A[p - 1]) == 0);
            if (p < N - 1) now += (S.count(A[p + 1]) == 0);
            ans = (ans * now) % MOD;
            S.insert(B[i]);
        }

        cout << (ans + MOD) % MOD << '\n';
    }
}