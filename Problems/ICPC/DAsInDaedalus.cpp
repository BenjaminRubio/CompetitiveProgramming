#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, B, first, x;
int c[5] = {1, 10, 100, 1000, 10000};

int main()
{
    while (cin >> N >> M)
    {
        long long ans = 0;
        rep(i, M)
        {
            int aux = 0;
            cin >> B >> first;
            int sum = first;
            rep(j, N - 1)
            {
                cin >> x;
                sum += x;
            }

            rep(k, 5) if (sum - first + c[k] <= B) aux = max(aux, c[k] - first * (sum <= B));

            ans += aux;
        }

        cout << ans << '\n';
    }
}