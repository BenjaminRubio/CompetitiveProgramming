#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

template<int SZ> struct Sieve
{ 
    bitset<SZ> I; vector<int> P;
    Sieve()
    {
        I.set(); I[0] = I[1] = 0;
        for (int i = 4; i < SZ; i += 2) I[i] = 0;
        for (int i = 3; i * i < SZ; i += 2) if (I[i])
            for (int j = i*i; j < SZ; j += i*2) I[j] = 0;
        rep(i, SZ) if (I[i]) P.push_back(i);
    }
}; Sieve<100010> S;

vector<int> factor(int x)
{
    vector<int> ans;
    for (int d : S.P)
    {
        if (d * d > x) break;
        if (x % d == 0) ans.push_back(d);
        while (x % d == 0) if ((x /= d) == 1) return ans;
    }
    if (x > 1) ans.push_back(x);
    return ans;
}

int N, Q, l, r;
vector<int> A, L;

int nx[100010][17];

int main()
{
    cin >> N >> Q;

    A.resize(N); rep(i, N) cin >> A[i];

    L.assign(100010, N); rep(k, 17) nx[N][k] = N;
    for (int i = N - 1; i >= 0; i--)
    {
        int m = (i < N - 1 ? nx[i + 1][0] : N);
        vector<int> factors = factor(A[i]);
        for (int f : factors) m = min(m, L[f]), L[f] = i;
        nx[i][0] = m;
    }

    rep(k, 17) if (k) rep(i, N) nx[i][k] = nx[nx[i][k - 1]][k - 1];

    while (Q--)
    {
        cin >> l >> r; l--, r--;

        int ans = 1;
        for (int k = 16; k >= 0; k--) if (nx[l][k] < r + 1) l = nx[l][k], ans += (1 << k);

        cout << ans << '\n';
    }
}