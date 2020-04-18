#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, m;
string a, b, ans;
vector<string> A, B;
vector<bool> D;

bool check(int i) // checks if adding pair i makes sense
{
    auto na = a.size(), nb = b.size();
    if (a.size() > b.size())
    {
        rep(j, min(na - nb, B[i].size()))
            if (a[j + nb] != B[i][j]) return false;
        if (na - nb > B[i].size()) return true;
        rep(j, min(A[i].size(), B[i].size() - na + nb)) 
            if (A[i][j] != B[i][j + na - nb]) return false;
    }
    else
    {
        rep(j, min(nb - na, A[i].size()))
            if (b[j + na] != A[i][j]) return false;
        if (nb - na > A[i].size()) return true;
        rep(j, min(B[i].size(), A[i].size() - nb + na)) 
            if (B[i][j] != A[i][j + nb - na]) return false;
    }
    return true;
}

void solve(int id) // backtracking function
{
    if (id and a.size() == b.size())
    {
        if (a.size() < m) { m = a.size(); ans = a; }
        else if (a.size() == m and a < ans) ans = a;
        return;
    }
    if (id == N) return;

    rep(i, N) if (!D[i] and check(i))
    {
        D[i] = true;
        a.append(A[i]); b.append(B[i]);
        solve(id + 1);
        a.erase(a.size() - A[i].size(), A[i].size());
        b.erase(b.size() - B[i].size(), B[i].size());
        D[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    while (cin >> N)
    {
        cout << "Case " << T++ << ": ";
        D.clear();

        A.resize(N); B.resize(N);
        rep(i, N) cin >> A[i] >> B[i];

        a.clear(); b.clear(); m = 1e9;
        D.assign(N, false);
        solve(0);

        if (m != 1e9) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}