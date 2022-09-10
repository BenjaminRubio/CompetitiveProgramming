#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T, N;
vector<ll> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        ll cnt = 0;
        for (int i = 0; i < N; i++)
        {
            while (A[i] % 2 == 0) A[i] /= 2, cnt++;
        }

        ll M = *max_element(A.begin(), A.end());
        while (cnt--) M *= 2ll;

        ll ans = M;
        for (int i = 0; i < N; i++) ans += A[i];
        ans -= *max_element(A.begin(), A.end());

        cout << ans << '\n';
    }
}