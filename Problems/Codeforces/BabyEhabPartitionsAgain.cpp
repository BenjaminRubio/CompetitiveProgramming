#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int N, S;
vector<int> A;
    
int DP[110][200010];
    
int dp(int i, int s)
{
    if (s == S / 2) return 1;
    if (i == N) return 0;
    if (DP[i][s] != -1) return DP[i][s];
    
    if (dp(i + 1, s + A[i]) || dp(i + 1, s)) return 1;
    return DP[i][s] = 0;
}

int main()
{
    cin >> N;
    
    A.resize(N);
    
    S = 0; int flag = 0, id;
    rep(i, N)
    {
        cin >> A[i]; S += A[i];
        if (A[i] & 1) flag = 1, id = i;
    }
    
    memset(DP, -1, sizeof DP);
    if ((S & 1) || !dp(0, 0)) { cout << 0 << '\n'; return 0; }
    
    while (!flag) rep(i, N)
    {
        A[i] /= 2;
        if (A[i] & 1) flag = 1, id = i;
    }
    cout << 1 << '\n' << id + 1 << '\n';
}