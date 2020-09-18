#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<double>> matrix;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N; double P;

matrix mul(matrix &A, matrix &B)
{
    matrix ans = {{0, 0}, {0, 0}};
    rep(i, 2) rep(j, 2) rep(k, 2) ans[i][k] += A[i][j] * B[j][k];
    return ans;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> P;

    matrix M = {{1 - P, P}, {P, 1 - P}}, A = {{1, 0}, {0, 1}};
    while (N)
    {
        if (N & 1) A = mul(A, M);
        M = mul(M, M);
        N >>= 1;
    }

    cout << A[0][0] << '\n';
}