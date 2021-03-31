#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K;
vector<string> C;

int main()
{
    cin >> N >> K;

    C.resize(N); set<string> S;
    rep(i, N) { cin >> C[i]; S.insert(C[i]); }

    int ans = 0;
    rep(i, N) for (int j = i + 1; j < N; j++)
    {
        string aux;
        rep(k, K)
        {
            if (C[i][k] == C[j][k]) aux += C[i][k];
            if ((C[i][k] == 'S' && C[j][k] == 'E') || (C[i][k] == 'E' && C[j][k] == 'S')) aux += 'T';
            if ((C[i][k] == 'S' && C[j][k] == 'T') || (C[i][k] == 'T' && C[j][k] == 'S')) aux += 'E';
            if ((C[i][k] == 'T' && C[j][k] == 'E') || (C[i][k] == 'E' && C[j][k] == 'T')) aux += 'S';
        }

        if (S.count(aux)) ans++;
    }

    cout << ans / 3 << '\n';
}