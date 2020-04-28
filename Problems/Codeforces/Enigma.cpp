#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> S;
int P[1001], DP[1001][1001], final[1001];

bool dp(int i, int r)
{
    int j = S.size() - i - 1;
    if (i == S.size()) return r == 0;

    if (DP[i][r] != -1) return DP[i][r] == 1;

    if (S[i] != -1)
        return DP[i][r] = dp(i + 1, (r - (S[i] * P[j]) % N + N) % N);
    
    bool ans = false;
    rep(k, 10) if (i + k != 0) if (dp(i + 1, (r - (k * P[j]) % N + N) % N))
    {
        ans = true;
        final[i] = k;
        break;
    }

    return DP[i][r] = ans;
}

int main()
{
    memset(DP, -1, sizeof DP);

    string s;
    cin >> s >> N;
    for (char c : s) S.push_back(c != '?' ? c - '0' : -1);
    rep(i, s.size()) if (S[i] != -1) final[i] = S[i];

    int p = 1;
    rep(i, s.size() + 1) { P[i] = p; p = (p * 10) % N; }

    if (dp(0, 0))
    {
        rep(i, S.size()) cout << final[i];
        cout << '\n';
    }
    else cout << "*\n";
}