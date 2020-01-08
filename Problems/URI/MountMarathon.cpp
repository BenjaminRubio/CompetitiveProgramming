#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repinv(i, n) for (int i = (int)n - 1; i >= 0; i--)

int N;
vector<int> C;

int main()
{
    cin >> N;

    C.resize(N);
    rep(i, N) cin >> C[i];

    rep(i, 52) repinv(j, C.size() - 1)
        if (C[j] == i + 1 && C[j + 1] <= C[j])
            C.erase(C.begin() + j + 1);

    cout << C.size() << '\n';
}