#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, Q, K;
vector<vector<ll>> A;

int main()
{
    cin >> N;

    A.assign(N + 1, vector<ll>(N + 1, -1));
    rep(i, N)
    {
        rep(j, N)
        {
            int off = min(i, N - j - 1);
            A[i][j] = (1ll << (i + j)) * (off % 2);
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << endl;

    cin >> Q;
    rep(_, Q)
    {
        cin >> K;
        int i = 0, j = 0;
        cout << 1 << ' ' << 1 << '\n';
        while (i + j < 2 * N - 2)
        {
            ll on = K & (1ll << (i + j + 1));
            if (A[i + 1][j] == on) i++;
            else if (A[i][j + 1] == on) j++;
            cout << i + 1 << ' ' << j + 1 << '\n'; 
        }

        cout << endl;
    }
}