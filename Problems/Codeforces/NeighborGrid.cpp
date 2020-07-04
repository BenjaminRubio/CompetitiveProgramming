#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
vector<vector<int>> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        A.assign(N, vector<int>(M));
        bool flag = true;
        rep(i, N) rep(j, M)
        {
            cin >> A[i][j];
            if (i == 0 && j == 0 && A[i][j] > 2) flag = false;
            else if (i == N - 1 && j == 0 && A[i][j] > 2) flag = false;
            else if (i == N - 1 && j == M - 1 && A[i][j] > 2) flag = false;
            else if (i == 0 && j == M - 1 && A[i][j] > 2) flag = false;
            else if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && A[i][j] > 3) flag = false;
            else if (A[i][j] > 4) flag = false;
        }

        if (!flag) { cout << "NO\n"; continue; }
        cout << "YES\n";
        rep(i, N)
        {
            rep(j, M)
            {
                if (i == 0 && j == 0) cout << 2 << ' ';
                else if (i == N - 1 && j == 0) cout << 2 << ' ';
                else if (i == N - 1 && j == M - 1) cout << 2 << ' ';
                else if (i == 0 && j == M - 1) cout << 2 << ' ';
                else if (i == 0 || j == 0 || i == N - 1 || j == M - 1) cout << 3 << ' ';
                else cout << 4 << ' ';
            }
            cout << '\n';
        }
    }
}