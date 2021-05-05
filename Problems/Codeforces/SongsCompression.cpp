#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, a, b;
vector<int> S;

int main()
{
    cin >> N >> M;

    long long sum = 0;
    rep(i, N) { cin >> a >> b; sum += a; S.push_back(a - b); }

    sort(S.rbegin(), S.rend());

    int ans = 0;
    for (int s : S)
    {
        if (sum <= M) break;
        sum -= s, ans++;
    }

    cout << (sum <= M ? ans : -1) << '\n';
}
