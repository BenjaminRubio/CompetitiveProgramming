#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<int> A, B;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    int i = 0, j = N - 1;
    B.resize(N);
    rep(k, N)
    {
        if (k & 1) B[k] = A[i], i++;
        else B[N - k - 1 - (N % 2 == 0)] = A[j], j--;
    }

    int c = 0;
    rep(i, N) if (i && i < N - 1 && B[i - 1] > B[i] && B[i + 1] > B[i]) c++; 
    cout << c << '\n';
    rep(i, N) cout << B[i] << ' ';
    cout << '\n';
}