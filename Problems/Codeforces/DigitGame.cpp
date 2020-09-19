#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N; char c;
vector<int> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) { cin >> c; A[i] = c - '0'; }

        int e = 0, o = 0;
        if (N & 1)
        {
            rep(i, N - N / 2)
            {
                if (A[2 * i] & 1) o++;
                else e++;
            }
            if (o) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        else
        {
            rep(i, N / 2)
            {
                if (A[2 * i + 1] & 1) o++;
                else e++;
            }
            if (e) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
    }
}