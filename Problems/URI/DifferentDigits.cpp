#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int A, B, C[5001];

int main()
{
    rep(i, 5001) if (i)
    {
        bool flag = 0;
        int N = i;

        set<int> s;
        while (N)
        {
            int d = N % 10; N /= 10;
            if (s.count(d)) flag = 1;
            s.insert(d);
        }

        if (flag) C[i] = C[i - 1];
        else C[i] = C[i - 1] + 1;
    }

    while (cin >> A >> B)
    {
        cout << C[B] - C[A - 1] << '\n';
    }
}