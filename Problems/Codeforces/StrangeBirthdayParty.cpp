#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
vector<ll> K, C, S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        K.resize(N);
        rep(i, N) cin >> K[i];

        C.resize(M);
        rep(i, M) cin >> C[i];

        sort(K.begin(), K.end());

        S.assign(N + 1, 0);
        rep(i, N) S[i + 1] = S[i] + C[K[i] - 1];

        ll ans = S[N], p = 0, l = 0;
        rep(i, N) if (K[N - i - 1] - 1 >= l)
        {
            p += C[l++];
            ans = min(ans, S[N - i - 1] + p);
        }

        cout << ans << '\n';
    }
}