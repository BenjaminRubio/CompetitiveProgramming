#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K, P;

int main()
{
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> q;

    int ans = 0;
    rep(i, N)
    {
        cin >> P;

        if (i - (K + 1) * q.size() >= K) q.push(P);
        else if (i - (K + 1) * q.size() < K and !q.empty() and P > q.top())
        {
            ans += q.top();
            q.pop();
            q.push(P);
        }
        else ans += P;
    }

    cout << ans << '\n';
}