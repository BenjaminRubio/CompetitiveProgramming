#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, N;
string s;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> s;

        int c = 0;
        vector<int> ans(N, 0);
        rep(i, 2 * N - 1)
        {
            if (s[i] == '1') c++;
            else c = 0;

            if (i >= N - 1) cout << (c >= N);
        }
        cout << '\n';
    }
}