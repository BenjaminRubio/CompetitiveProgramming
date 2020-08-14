#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
char x;
vector<int> A, S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        
        A.resize(N);
        rep(i, N) { cin >> x; A[i] = x - '0' - 1; }

        map<int, int> m;
        ll ans = 0, s = 0;
        rep(i, N)
        {
            s += A[i];
            ans += m[s] + (s == 0);
            m[s]++;
        }

        cout << ans << '\n';
    }
}