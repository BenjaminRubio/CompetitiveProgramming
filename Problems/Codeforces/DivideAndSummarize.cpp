#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, Q, s;
vector<int> A;
set<ll> S;

void calc(int i, int j)
{
    int m = INT_MAX, M = INT_MIN; ll sm = 0;
    for (int k = i; k < j; k++) m = min(m, A[k]), M = max(M, A[k]), sm += A[k];

    S.insert(sm);

    if (m == M) return;

    int mid = (m + M) / 2, k = 0;
    while (A[k] <= mid) k++;
    calc(i, k); calc(k, j);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;

        A.resize(N);
        rep(i, N) cin >> A[i];

        sort(A.begin(), A.end());

        S.clear();
        calc(0, N);

        rep(_, Q)
        {
            cin >> s;
            if (S.count(s)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}