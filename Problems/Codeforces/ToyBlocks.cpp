#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
    
int T, N;
vector<ll> A;
    
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
    
        A.resize(N);
        rep(i, N) cin >> A[i];
    
        if (N == 2) { cout << 0 << '\n'; continue; }
    
        sort(A.rbegin(), A.rend());
    
        ll s = 0;
        rep(i, N) s += A[i];
        ll m = (s / (N - 1)) + bool(s % (N - 1));
    
        if (A[0] >= m) cout << A[0] * (ll)(N - 1) - s << '\n';
        else cout << m * (ll)(N - 1) - s << '\n';
    }
}