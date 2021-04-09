#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

int N, a, c;
vector<int> A, C;

int main()
{
    cin >> N;

    A.resize(N), C.resize(N);
    rep(i, N) cin >> A[i] >> C[i];

    vector<pair<int, pair<int, int>>> E;
    rep(i, N)
    {
        E.emplace_back(A[i], mp(0, i));
        E.emplace_back(A[i] + C[i], mp(1, i));
    }

    sort(E.begin(), E.end(), greater<pair<int, pair<int, int>>>());

    ll ans = 0;
    rep(i, N) ans += C[i];

    int on = 0, l = E[0].ff;
    for (auto &e : E)
    {
        if (e.ss.ff == 1)
        {
            if (on == 0) ans += l - e.ff;
            on++;
        }
        if (e.ss.ff == 0) on--;
        l = e.ff;
    }

    cout << ans << '\n';
}