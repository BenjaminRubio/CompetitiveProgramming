#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A, L, R, P, NX, l, r, ans;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        ans.clear();
        A.resize(N), L.resize(N), R.resize(N), NX.resize(N), l.resize(N), r.resize(N);
        rep(i, N) cin >> A[i];

        int k = 0;
        L[0] = 0, R[0] = 0, NX[0] = 0;
        rep(i, N) if (i < N - 1)
        {
            if (__gcd(A[i], A[i + 1]) != 1) R[k] = i + 1;
            else k++, L[k] = i + 1, R[k] = i + 1, NX[k - 1] = k;
        }

        rep(i, N) r[i] = (i + 1) % N, l[i] = (i + N - 1) % N;

        if (__gcd(A[0], A[N - 1]) != 1) L[0] = L[k], k--, NX[k] = 0;
        else NX[k] = 0;

        int c = k + 1, i = 0;
        while (c > 0)
        {
            int id = NX[i];

            ans.push_back(L[id] + 1);

            r[l[L[id]]] = r[L[id]];
            l[r[L[id]]] = l[L[id]];

            if (L[id] == R[id]) c--, NX[i] = NX[id];
            else L[id] = r[L[id]];

            if (c > 0 && __gcd(A[R[i]], A[L[NX[i]]]) != 1)
            {
                c--;
                R[i] = R[NX[i]];
                NX[i] = NX[NX[i]];
            }
            else i = NX[i];
        }

        cout << ans.size() << ' ';
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    }
}