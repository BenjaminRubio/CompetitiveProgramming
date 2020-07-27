#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, A;
char aux;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> N; A = 0;
        rep(i, N) { cin >> aux; A += (aux == 'A'); }
        if (abs(A - (N - A)) == 1) cout << "Y\n";
        else cout << "N\n";
    }
}