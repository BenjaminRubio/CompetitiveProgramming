#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q, q;
vector<int> A;

int main()
{
    cin >> N >> Q;

    A.resize(N);
    rep(i, N) cin >> A[i];

    while (Q--)
    {
        cin >> q;

        int l = 0, r = N;
        while (l < r)
        {
            int m = (l + r) / 2;

            if (A[m] >= q) r = m;
            else l = m + 1;
        }

        if (l == N || A[l] != q) cout << -1 << '\n';
        else cout << l << '\n';
    }
}