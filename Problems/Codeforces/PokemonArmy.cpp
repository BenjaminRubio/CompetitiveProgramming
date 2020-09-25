#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, Q, l, r;
vector<int> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N >> Q;

        A.resize(N);
        rep(i, N) cin >> A[i];

        ll ans = 0;
        if (N == 1)
        {
            ll ans = A[0];
            cout << ans << '\n';
            while (Q--) { cin >> l >> r; cout << ans << '\n'; }
            continue;
        }

        rep(i, N)
        {
            if (i == 0 && A[i + 1] < A[i]) ans += A[i];
            else if (i == N - 1 && A[i - 1] < A[i]) ans += A[i];
            else if (i > 0 && i < N - 1 && A[i - 1] < A[i] && A[i + 1] < A[i]) ans += A[i];
            else if (i > 0 && i < N - 1 && A[i - 1] > A[i] && A[i + 1] > A[i]) ans -= A[i];
        }

        cout << ans << '\n';

        while (Q--)
        {
            cin >> l >> r; l--, r--;
            set<int> I = {l - 1, l, l + 1, r - 1, r, r + 1};
            for (int i : I) if (i >= 0 && i < N)
            {
                if (i == 0 && A[i + 1] < A[i]) ans -= A[i];
                else if (i == N - 1 && A[i - 1] < A[i]) ans -= A[i];
                else if (i > 0 && i < N - 1 && A[i - 1] < A[i] && A[i + 1] < A[i]) ans -= A[i];
                else if (i > 0 && i < N - 1 && A[i - 1] > A[i] && A[i + 1] > A[i]) ans += A[i];
            } swap(A[l], A[r]);
            for (int i : I) if (i >= 0 && i < N)
            {
                if (i == 0 && A[i + 1] < A[i]) ans += A[i];
                else if (i == N - 1 && A[i - 1] < A[i]) ans += A[i];
                else if (i > 0 && i < N - 1 && A[i - 1] < A[i] && A[i + 1] < A[i]) ans += A[i];
                else if (i > 0 && i < N - 1 && A[i - 1] > A[i] && A[i + 1] > A[i]) ans -= A[i];
            }

            cout << ans << '\n';
        }
    }
}