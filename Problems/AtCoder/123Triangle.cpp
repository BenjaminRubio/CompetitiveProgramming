#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

int N; char aux; bool flag;
vector<int> A;

int main()
{
    cin >> N;

    flag = 0;
    A.resize(N);
    rep(i, N)
    {
        cin >> aux;
        A[i] = aux - '1';
        if (A[i] == 1) flag = 1;
    }

    rep(i, N) if (A[i] == 2) A[i] = !flag;

    rep_(i, 32) if ((N - 1) & (1 << i))
    {
        rep(j, N - (1 << i)) A[j] = A[j] ^ A[j + (1 << i)];
        N -= (1 << i);
    }

    if (flag) cout << A[0] << '\n';
    else cout << A[0] * 2 << '\n';
}