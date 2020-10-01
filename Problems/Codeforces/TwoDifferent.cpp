#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<pair<int, int>> A;

void solve(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2, m = (r - l + 1) / 2;
    solve(l, mid), solve(mid + 1, r);
    for (int i = l; i <= mid; i++) A.emplace_back(i, i + m);
}

int main()
{
    cin >> N;

    int b = 0;
    rep(i, 30) if (N & (1 << i)) b = i;

    solve(0, (1 << b) - 1), solve(N - 1 - ((1 << b) - 1), N - 1);

    cout << A.size() << '\n';
    for (auto &e : A) cout << e.first + 1 << ' ' << e.second + 1 << '\n';
}