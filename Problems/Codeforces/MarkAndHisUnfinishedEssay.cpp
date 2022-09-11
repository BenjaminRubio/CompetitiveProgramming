#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll T, N, C, Q, K;
vector<ll> L, R;
string S;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> C >> Q >> S;

        L.resize(C); R.resize(C);
        for (int i = 0; i < C; i++)
        {
            cin >> L[i] >> R[i];
            L[i]--, R[i]--;
        }

        for (int j = 0; j < Q; j++)
        {
            cin >> K; K--;

            while (K >= N)
            {
                ll p = N - 1;
                for (int i = 0; i < C; i++)
                {
                    ll l = (R[i] - L[i] + 1ll);
                    p += l;
                    if (K <= p)
                    {
                        K = L[i] - 1 + (K - (p - l));
                        break;
                    }
                }
            }

            cout << S[K] << '\n';
        }
    }
}