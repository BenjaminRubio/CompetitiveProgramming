#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q;
vector<int> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;

    A.resize(N); rep(i, N) cin >> A[i];

    vector<int> T(51, 0); vector<int> q(Q);
    rep(i, Q) { cin >> q[i]; T[q[i]] = 1; }

    vector<int> P(51, -1);
    rep(i, N) if (T[A[i]] && P[A[i]] == -1) P[A[i]] = i;

    vector<int> p(51, -1);
    vector<vector<int>> C(Q, vector<int>(51, 0));
    rep(i, Q)
    {
        if (i > 0) rep(j, 51) C[i][j] = C[i - 1][j];
        if (T[q[i]])
        {
            int off = 0;
            rep(j, 51) if (p[j] > P[q[i]]) off++;
            cout << P[q[i]] + off + 1 << ' ';

            p[q[i]] = P[q[i]];
            P[q[i]] = i, T[q[i]] = 0;
            C[i][q[i]]++;
        }
        else
        {
            int aux = 0;
            rep(j, 51) if (C[i][j] > C[P[q[i]]][j]) aux++;
            cout << aux + 1 << ' ';
            P[q[i]] = i, C[i][q[i]]++;
        }
    }
    cout << '\n';
}