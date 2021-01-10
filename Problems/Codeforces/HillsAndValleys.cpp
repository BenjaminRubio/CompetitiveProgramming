#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
vector<int> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        vector<int> S(N + 1, 0);
        rep(i, N)
        {
            if (i && i < N - 1 && ((A[i] > A[i - 1] && A[i] > A[i + 1]) || (A[i] < A[i - 1] && A[i] < A[i + 1])))
                S[i + 1] = S[i] + 1;
            else S[i + 1] = S[i];
        }

        int ans = S[N];
        rep(i, N)
        {
            vector<int> o;
            if (i) o.push_back(A[i - 1]);
            if (i < N - 1) o.push_back(A[i + 1]);

            int p = A[i];
            for (int opt : o)
            {
                A[i] = opt;
                int aux = S[max(0, i - 1)] + S[N] - S[min(N, i + 2)];
                repx(j, max(0, i - 1), min(N, i + 2)) aux += (j && j < N - 1 && ((A[j] > A[j - 1] && A[j] > A[j + 1]) || (A[j] < A[j - 1] && A[j] < A[j + 1])));
                ans = min(ans, aux);
            }
            A[i] = p;
        }

        cout << ans << '\n';
    }
}