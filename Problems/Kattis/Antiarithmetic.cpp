#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, p; char t;
vector<int> P;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N >> t && N)
    {
        P.resize(N);
        rep(i, N) { cin >> p; P[p] = i; }

        rep(i, N) for (int c = -(i / 2); c <= (N - i - 1) / 2; c++)
        {
            if (P[i + c] > P[i] && P[i + 2 * c] > P[i + c])
            { cout << "no\n"; goto next; }
        }

        cout << "yes\n";

        next:
        continue;
    }
}