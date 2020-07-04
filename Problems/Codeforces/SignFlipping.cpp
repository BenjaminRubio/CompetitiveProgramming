#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, A;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;

        int last = INT_MIN;
        vector<int> B;
        rep(i, N)
        {
            cin >> A;
            if (i % 2) B.push_back(abs(A));
            else B.push_back(-abs(A));
        }

        rep(i, N) cout << B[i] << ' ';
        cout << '\n';
    }
}