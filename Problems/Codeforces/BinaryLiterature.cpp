#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<string> S;

int main()
{
    cin >> T;
    S.resize(3);
    while (T--)
    {
        cin >> N >> S[0] >> S[1] >> S[2];

        int a[3] = {0, 0, 0};
        rep(i, 2 * N) a[0] += (S[0][i] == '1'), a[1] += (S[1][i] == '1'), a[2] += (S[2][i] == '1');
        rep(i, 3) a[i] = (a[i] >= N);
        string aux; int i = 0, j = 0;
        rep(x, 3) rep(y, 3) if (x != y && a[x] == a[y])
        {
            char o = (a[x] ? '0' : '1');
            while (i < 2 * N && j < 2 * N)
            {
                while (i < 2 * N && j < 2 * N && S[x][i] == S[y][j]) aux += S[x][i], i++, j++;
                while (i < 2 * N && j < 2 * N && S[x][i] != S[y][j])
                {
                    aux += o;
                    if (S[x][i] == o) i++;
                    else j++;
                }
            }
            while (i < 2 * N) aux += S[x][i], i++;
            while (j < 2 * N) aux += S[y][j], j++;

            cout << aux << '\n';
            goto next;
        }

        next:
        continue;
    }
}