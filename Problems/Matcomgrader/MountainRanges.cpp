#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, X;
vector<int> A;

int main()
{
    cin >> N >> X;

    A.resize(N);
    rep(i, N) cin >> A[i];

    int ans = 0;
    rep(i, N)
    {
        bool done = false;
        repx(j, i, N - 1) if (A[j + 1] - A[j] > X)
        {
            ans = max(ans, j - i + 1);
            done = true;
            break;
        }
        if (!done)
            ans = max(ans, N - i);
    }

    cout << ans << '\n';
}