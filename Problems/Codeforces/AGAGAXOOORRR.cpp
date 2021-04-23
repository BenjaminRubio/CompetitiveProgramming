#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int T, N;
vector<int> A, X;
    
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
    
        A.resize(N); rep(i, N) cin >> A[i];
    
        X = A;
        rep(i, N - 1) X[i + 1] = X[i + 1] ^ X[i];
    
        bool flag = 0;
        rep(i, N - 1) if (X[i] == (X[N - 1] ^ X[i])) flag = 1;
        rep(i, N - 1) for (int j = i + 1; j < N - 1; j++)
        {
            if (X[i] == (X[j] ^ X[i]) && (X[j] ^ X[i]) == (X[N - 1] ^ X[j]))
                flag = 1;
        }
    
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}