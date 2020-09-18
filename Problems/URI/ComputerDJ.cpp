#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int mul(const int &a, const int &b) { return (a > INT_MAX / b) ? INT_MAX : a * b; }

int N, Q, K;
vector<string> S;

int P[101];

int main()
{
    while (cin >> N >> Q && N)
    {
        S.resize(N);
        rep(i, N) cin >> S[i];

        P[0] = 1;
        rep(i, 100) P[i + 1] = mul(P[i], N);

        rep(_, Q)
        {
            cin >> K;
            
            int l = 1;
            while (K > P[l] * l) K -= P[l] * l, l++;

            int R = K % l ? K % l : l, k; K = (K - 1) / l + 1;
            rep(i, R)
            {
                k = 0;
                while (K > P[l - i - 1]) K -= P[l - i - 1], k++;
            }
            cout << S[k] << '\n';
        }
        cout << '\n';
    }
}