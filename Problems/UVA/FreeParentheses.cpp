#include <bits/stdc++.h>
using namespace std;

int x, n; char c;
string line;
vector<int> N;
vector<bool> S;
bool V[31][31][6001];
set<int> ans;

void dp(int i, int p, int s)
{
    if (V[i][p][s + 3000]) return;

    if (i == n) { ans.insert(s); return; }

    dp(i + 1, p, s + N[i] * (p & 1 ? -1 : 1));
    if (p) dp(i, p - 1, s);
    if (S[i]) dp(i + 1, p + 1, s + N[i] * (p & 1 ? -1 : 1));

    V[i][p][s + 3000] = 1;
}

int main()
{
    while (getline(cin, line))
    {
        N.clear(); S.clear(); ans.clear();
        memset(V, 0, sizeof V);

        stringstream ss(line);
        ss >> x;
        while (ss >> c >> x) { S.push_back(c == '-'); N.push_back(x * (S.back() ? -1 : 1)); }
        n = S.size();

        dp(0, 0, 0);

        cout << ans.size() << '\n';
    }
}