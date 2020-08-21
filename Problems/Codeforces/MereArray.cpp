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

        int m = INT_MAX;
        A.resize(N);
        rep(i, N) { cin >> A[i]; m = min(m, A[i]); }

        vector<int> v;
        rep(i, N) if (A[i] % m == 0)
        {
            v.push_back(A[i]);
            A[i] = -1;
        }

        sort(v.begin(), v.end());

        int j = 0;
        bool flag = true;
        rep(i, N)
        {
            if (A[i] == -1) A[i] = v[j], j++;
            if (i && A[i] < A[i - 1]) flag = false;
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}