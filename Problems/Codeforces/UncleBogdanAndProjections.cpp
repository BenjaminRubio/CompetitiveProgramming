#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N;
vector<pair<pair<double, double>, double>> C;

int main()
{
    cin >> N;

    C.resize(N);
    rep(i, N) cin >> C[i].ff.ff >> C[i].ff.ss >> C[i].ss;

    sort(C.begin(), C.end());

    rep(i, N - 1)
    {
        if (C[i].ss <= C[i + 1].ss)
        {
            
        }
    }
}