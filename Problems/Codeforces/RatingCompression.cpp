#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<int> A, C;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N); C.assign(N, 0);
        rep(i, N) { cin >> A[i]; A[i]--, C[A[i]]++; }

        vector<bool> ans; bool p = 1; int l = 0, r = N - 1;
        rep(i, N - 1)
        {
            if (C[i] && p) ans.push_back(1);
            else ans.push_back(0);
            if (C[i] == 1 && A[l] == i) l++;
            else if (C[i] == 1 && A[r] == i) r--;
            else p = 0;
        }

        bool lst = 1;
        rep(i, N) if (C[i] != 1) lst = 0;
        ans.push_back(lst);

        while (!ans.empty()) { cout << ans.back(); ans.pop_back(); }
        cout << '\n';
    }
}