#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct TrieXOR
{
    int N[10000000][2] = {0}, S[10000000] = {0}, c = 0;
    TrieXOR() {}
    void add(int x, int a = 1)
    {
        int p = 0; S[p] += a;
        rep(i, 31)
        {
            int t = (x >> (30 - i)) & 1;
            if (!N[p][t]) N[p][t] = ++c;
            S[p = N[p][t]] += a;
        }
    }
    int dfs(int p)
    {
        if (N[p][0] && N[p][1])
        {
            int ans = INT_MAX;
            ans = min(ans, S[N[p][0]] - 1 + dfs(N[p][1]));
            ans = min(ans, S[N[p][1]] - 1 + dfs(N[p][0]));
            return ans;
        }
        if (N[p][0]) return dfs(N[p][0]);
        if (N[p][1]) return dfs(N[p][1]);
        return 0;
    }
};

int N, a;

int main()
{
    cin >> N;

    TrieXOR tx;
    rep(i, N) { cin >> a; tx.add(a); }

    cout << tx.dfs(0) << '\n';
}