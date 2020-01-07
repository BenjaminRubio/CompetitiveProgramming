#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> T;

int dist(int i, int j)
{
    return min(abs(i - j), 24 - abs(i - j));
}

int main()
{
    while (cin >> N)
    {
        T.resize(N);
        rep(i, N) cin >> T[i];

        sort(T.begin(), T.end());

        int ans1 = 0;
        rep(i, N / 2) ans1 += dist(T[2 * i], T[(2 * i + 1) % N]);
        int ans2 = 0;
        rep(i, N / 2) ans2 += dist(T[(2 * i + 1) % N], T[(2 * i + 2) % N]);

        cout << min(ans1, ans2) << '\n';
    }
}