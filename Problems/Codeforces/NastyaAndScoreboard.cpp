#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, k;
vector<int> a, bt;
string aux;
vector<int> cd = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};
vector<int> b = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int DP[2010][2010];
int ans[2010];

bool dp(int i, int r)
{
    if (i == n and r == 0) return true;
    if (i == n) return false;

    if (DP[i][r] != -1) return ((DP[i][r] == 1) ? true : false);

    bool ans_ = false;
    rep(j, 10)
    {
        int nw = 10 - j - 1;
        if (((bt[i] & cd[nw]) == bt[i]) and (r >= b[nw] - a[i]) and 
            dp(i + 1, r - b[nw] + a[i]))
        {
            ans_ = true;
            ans[i] = nw;
            break;
        }
    }
    if (ans_) DP[i][r] = 1;
    else DP[i][r] = 2;
    return ans_;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    a.resize(n);
    bt.assign(n, 0);

    rep(i, n)
    {
        cin >> aux;
        int c = 0;
        rep(j, aux.size()) if (aux[aux.size() - j - 1] == '1')
        {
            c++;
            bt[i] |= (1 << j);
        }
        a[i] = c;
    }

    memset(DP, -1, sizeof DP);

    if (dp(0, k))
    {
        rep(i, n) cout << ans[i];
        cout << '\n';
    }
    else cout << "-1\n";
}