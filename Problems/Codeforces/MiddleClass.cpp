#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, x, a;
priority_queue<int> q;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> x;
        rep(i, n) { cin >> a; q.push(a); }

        int cnt = 0, ans = 0;
        double sum = 0;
        while (!q.empty())
        {
            cnt++;
            sum += q.top(); q.pop();
            if ((sum / cnt) >= x) ans++;
        }

        cout << ans << '\n';
    }
    
}