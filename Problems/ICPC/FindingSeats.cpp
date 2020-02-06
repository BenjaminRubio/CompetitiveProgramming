#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int R, C, K;
vector<vector<char>> m(300, vector<char>(300, '.'));;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (true)
    {
        cin >> R >> C >> K;

        if (R == 0) break;

        rep(i, R) rep(j, C) cin >> m[i][j];

        int ans = 1e5;
        rep(r, R)
        {
            vector<int> p(C + 1, 0);

            repx(r_, r, R)
            {
                int acc = 0;
                rep(c, C)
                {
                    if (m[r_][c] == '.') acc++;
                    p[c + 1] += acc;
                }

                int aux = 500;
                rep(c, C)
                {
                    int low = c + 1;
                    int high = C + 1;
                    int _ = p[c];
                    while (low < high)
                    {
                        int m = (low + high) / 2;
                        if (p[m] - _ >= K) high = m;
                        else low = m + 1;
                    }

                    if (low != C + 1) aux = min(aux, low - c);
                }

                if (aux != 500) ans = min(ans, aux * (r_ - r + 1));
            }
        }

        cout << ans << '\n';
    }
}