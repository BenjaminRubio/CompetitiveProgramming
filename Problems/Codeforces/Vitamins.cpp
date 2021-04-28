#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, ans;
string S;
vector<int> C, V;

void solve(int i, int v, int c)
{
    if (v == 7) { ans = min(ans, c); return; }
    if (i == N) return;

    if ((V[i] & ~v)) solve(i + 1, v | V[i], c + C[i]);
    solve(i + 1, v, c);
}

int main()
{
    cin >> N;

    C.resize(N), V.assign(N, 0);
    rep(i, N)
    {
        cin >> C[i] >> S;
        for (char c : S) V[i] |= (1 << (c - 'A'));
    }

    ans = INT_MAX; solve(0, 0, 0);
    cout << (ans != INT_MAX ? ans : -1) << '\n';
}