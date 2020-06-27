#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int D, S;

pair<int, int> P[500][5001];  // parent array
int N[500][5001];  // num array
string ans;

int main()
{
    cin >> D >> S;

    memset(N, -1, sizeof N);

    queue<pair<int, int>> q; q.emplace(0, 0); P[0][0] = {-1, -1}; N[0][0] = 0;
    while (!q.empty())
    {
        int r = q.front().ff, s = q.front().ss; q.pop();

        if (r == 0 && s == S)
        {
            while (P[r][s] != make_pair(-1, -1))
            {
                ans += '0' + N[r][s];
                int x = P[r][s].ff, y = P[r][s].ss;
                r = x, s = y;
            }
            reverse(ans.begin(), ans.end());
            break;
        }

        rep(i, 10)
        {
            int nr = (r * 10 + i) % D, ns = s + i;
            if (ns <= S && N[nr][ns] == -1)
            {
                q.emplace(nr, ns);
                P[nr][ns] = {r, s};
                N[nr][ns] = i;
            }
        }
    }

    if (!ans.empty()) cout << ans << '\n';
    else cout << -1 << '\n';
}