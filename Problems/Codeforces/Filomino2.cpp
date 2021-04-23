#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> P;
vector<vector<int>> A;

int main()
{
    cin >> N;

    P.resize(N); rep(i, N) cin >> P[i];
    A.assign(N, vector<int>(N, -1));

    rep(i, N)
    {
        int k = P[i] - 1;
        int x = i, y = i;

        A[x][y] = P[i];
        while (k--)
        {
            if (y && A[x][y - 1] == -1) A[x][--y] = P[i];
            else A[++x][y] = P[i];
        }
    }

    rep(i, N)
    {
        for (int j = 0; j <= i; j++) cout << A[i][j] << ' ';
        cout << '\n';
    }
}