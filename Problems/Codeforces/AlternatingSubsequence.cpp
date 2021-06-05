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

        A.resize(N); rep(i, N) cin >> A[i];

        ll ans = 0;

        int i = 0, j = 0;
        while (i < N)
        {
            while (j < N && (A[j] > 0) == (A[i] > 0)) j++;

            ll aux = INT_MIN;
            for (int k = i; k < j; k++) aux = max(aux, (ll)A[k]);

            ans += aux;
            i = j;
        }

        cout << ans << '\n';
    }
}
