#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

ll N, P;
vector<ll> A;
ll F[2001];

int main()
{
    cin >> N >> P;

    A.resize(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    F[0] = 1;
    rep(i, N + 1) if (i) F[i] = (F[i - 1] * i) % P;

    ll c = 0;
    vector<ll> ans;
    rep(i, N)
    {
        ll aux = 1;

        int m = 0;
        while (m < N && A[m] <= A[i]) m++;

        aux = F[m];

        if (aux == 0) continue;

        // cerr << m << '\n';

        bool flag = false;
        repx(j, m, N)
        {
            if (A[i] + j < A[j]) { flag = true; break; }
            aux = (aux * (N - (A[j] - A[i]) - (N - j - 1ll))) % P;
            // cerr << N - (A[j] - i) - (N - j - 1) << '\n';
        }

        if (flag) continue;

        cerr << i << ' ' << aux << '\n';

        if (aux != 0)
        {
            c += A[i + 1] - A[i];
            repx(j, A[i], A[i + 1]) ans.push_back(j);
        }
    } 

    cout << c << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}