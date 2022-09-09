#include <bits/stdc++.h>
using namespace std;

int T, N;
string A, B;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> A >> B;
        bool ans = true;
        for (int i = 0; i < N; i++)
        {
            if ((A[i] == 'R' || B[i] == 'R') && A[i] != B[i]) ans = false;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
