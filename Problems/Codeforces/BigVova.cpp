#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, N, a;
vector<int> A, V;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N); V.assign(N, 0);
        rep(i, N) { cin >> A[i]; }

        sort(A.rbegin(), A.rend());

        int t = A[0]; V[0] = 1;
        cout << t << ' ';
        rep(_, N - 1)
        {
            pair<int, int> t_ = {0, 0};
            rep(i, N) if (!V[i])
                t_ = max(t_, make_pair(__gcd(t, A[i]), N - i));
            
            t = t_.ff, V[N - t_.ss] = 1;
            cout << A[N - t_.ss] << ' ';
        }
        cout << '\n';
    }
}