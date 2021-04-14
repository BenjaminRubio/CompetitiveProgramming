#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, B;
vector<int> P;

int main()
{
    while (cin >> N >> B && N != -1)
    {
        P.resize(N);
        rep(i, N) cin >> P[i];

        int l = 1, r = 5000000;
        while (l < r)
        {
            int m = (l + r) / 2;

            int aux = 0;
            rep(i, N) aux += P[i] / m + bool(P[i] % m);
            
            if (aux <= B) r = m;
            else l = m + 1;
        }

        cout << l << '\n';
    }
}