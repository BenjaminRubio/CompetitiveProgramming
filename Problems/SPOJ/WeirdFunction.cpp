#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

const ll MOD = 1e9 + 7;

ll T, A, B, C, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> A >> B >> C >> N;

        priority_queue<int> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        q1.push(1);
        
        ll ans = 1;
        repx(i, 2, N + 1)
        {
            ll F = (A * q1.top() + B * i + C) % MOD;

            ans += F;
            q1.push(F);

            if (!q2.empty() && q1.top() > q2.top())
            {
                q2.push(q1.top()), q1.pop();
                q1.push(q2.top()), q2.pop();
            }

            if (q1.size() > ((i + 1) / 2))
                q2.push(q1.top()), q1.pop();
        }

        cout << ans << '\n';
    }
}