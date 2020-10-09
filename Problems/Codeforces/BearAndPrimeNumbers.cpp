#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, Q; ll a, x, y;
vector<ll> A;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int MAXN = 1e7 + 10;

    A.assign(MAXN + 1, 0);
    cin >> N;
    rep(i, N) { cin >> a; A[a]++; }

    vector<ll> O(MAXN + 1, 0);

    vector<bool> I(MAXN + 1, 1);
	repx(i, 2, MAXN + 1) if (I[i]) for (ll j = i; j <= MAXN; j += i)
        O[i] += A[j], I[j] = 0;

    vector<int> S(MAXN + 1, 0);
    rep(i, MAXN) S[i + 1] = S[i] + O[i];

    cin >> Q;
    while (Q--)
    {
        cin >> x >> y;

        x = min(x, (ll)MAXN - 1), y = min(y, (ll)MAXN - 1);

        cout << S[y + 1] - S[x] << '\n';
    }
}