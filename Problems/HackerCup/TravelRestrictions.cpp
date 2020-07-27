#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
char aux;
vector<bool> I, O;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ":\n";

        cin >> N;

        I.assign(N, 0); O.assign(N, 0);
        rep(i, N) { cin >> aux; I[i] = (aux == 'Y'); }
        rep(i, N) { cin >> aux; O[i] = (aux == 'Y'); }

        rep(i, N)
        {
            rep(j, N)
            {
                bool ans = true;
                if (j > i) repx(k, i, j) if (!O[k] || !I[k + 1]) ans = false;
                if (j < i) repx(k, j, i) if (!I[k] || !O[k + 1]) ans = false;
                cout << (ans ? 'Y' : 'N');
            }
            cout << '\n';
        }
    }
}