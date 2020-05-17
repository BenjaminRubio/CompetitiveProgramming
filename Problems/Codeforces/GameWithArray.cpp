#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, S;

int main()
{
    cin >> N >> S;

    int a = S / N;
    int b = a + bool(S % N);
    
    bool pos = false; int K;
    rep(i, a + 1) if (i)
    {
        if (i != a && i != b && (S - i) != a && (S - 1) != b)
        {
            pos = true;
            K = i;
            break;
        }
    }

    if (pos)
    {
        cout << "YES\n";
        rep(i, S % N) cout << b << ' ';
        rep(i, N - S % N) cout << a << ' ';
        cout << '\n';
        cout << K << '\n';
    }
    else cout << "NO\n";
}