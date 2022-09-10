#include <bits/stdc++.h>
using namespace std;

int T, N, A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        int S = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> A;
            S += A;
        }

        cout << bool(S % N) << '\n';
    }
}
