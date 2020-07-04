#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        
        A.resize(N);
        rep(i, N) cin >> A[i];

        if (A[0] > A[N - 1]) cout << "NO\n";
        else cout << "YES\n";
    }
}