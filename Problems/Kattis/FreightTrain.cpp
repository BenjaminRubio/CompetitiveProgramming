#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, W, L, x;
vector<int> w;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> W >> L;

        w.resize(W);
        rep(i, W) { cin >> w[i]; w[i]--; }

        int left = 1, right = N;
        while (left < right)
        {
            int mid = (left + right) / 2;

            int aux = 1, i = 0, l = 0, r = mid - 1;
            while (i < W)
            {
                if (w[i] > r) aux++, l = w[i], r = l + mid - 1;

                while (i < W && w[i] <= r) i++;
                if (i == W) break;

                aux++, l = r + 1, r = l + mid - 1;
            }
            if (r < N) aux++;

            if (aux <= L) right = mid;
            else left = mid + 1;
        }

        cout << left << '\n';
    }
}