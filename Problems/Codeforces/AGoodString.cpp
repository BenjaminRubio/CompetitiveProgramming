#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
string S;
vector<int> A;

int solve(int i, int j, int c)
{
    if (i == j - 1) return A[i] != c;

    int c1 = 0, c2 = 0;
    repx(k, i, i + (j - i) / 2) c1 += A[k] != c;
    repx(k, i + (j - i) / 2, j) c2 += A[k] != c;

    int ans = INT_MAX;
    ans = min(ans, c1 + solve(i + (j - i) / 2, j, c + 1));
    ans = min(ans, c2 + solve(i, i + (j - i) / 2, c + 1));

    return ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> S;

        A.resize(N);
        rep(i, N) A[i] = S[i] - 'a';

        cout << solve(0, N, 0) << '\n';
    }
}