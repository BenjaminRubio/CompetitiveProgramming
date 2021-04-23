#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int T, N, K;
vector<int> A;
    
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
    
        A.resize(N); rep(i, N) cin >> A[i];
    
        int i = 0, k = 0;
        while (i < N - 1 && k < K)
        {
            if (A[i] == 0) { i++; continue; }
            A[i]--, A[N - 1]++, k++;
        }
    
        rep(i, N) cout << A[i] << ' ';
        cout << '\n';
    }
}