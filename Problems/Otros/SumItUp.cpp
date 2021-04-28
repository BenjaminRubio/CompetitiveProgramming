#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int S, N;
vector<int> A, aux;
set<vector<int>> ans;

void solve(int i, int s)
{
    if (s == S) ans.insert(aux);
    if (i == N) return;

    solve(i + 1, s);

    if (s + A[i] <= S)
    {
        aux.push_back(A[i]);
        solve(i + 1, s + A[i]);
        aux.pop_back();
    }
}

int main()
{
    while (cin >> S >> N)
    {
        ans.clear();

        A.resize(N); rep(i, N) cin >> A[i];
        sort(A.rbegin(), A.rend());

        solve(0, 0);

        cout << "Sums of " << S << ":\n";
        if (!ans.empty()) for (auto v = ans.rbegin(); v != ans.rend(); v++) rep(i, (*v).size())
            cout << (*v)[i] << "+\n"[(i == (*v).size() - 1)];
        else cout << "NONE\n";
    }
}