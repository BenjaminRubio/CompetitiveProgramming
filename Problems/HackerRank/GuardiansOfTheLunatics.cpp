#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int L, G;
vector<ll> C, acc;

ll cost(int i, int j)
{
    return (acc[j + 1] - acc[i]) * (j - i + 1);
}

vector<ll> last, now;

void compute(int l, int r, int optl, int optr)
{
    if (l > r) return;

    int mid = (l + r) / 2;
    pair<ll, int> best = {cost(0, mid), -1};

    repx(k, optl, min(mid, optr + 1))
        best = min(best, {last[k] + cost(k + 1, mid), k});

    now[mid] = best.ff;

    compute(l, mid - 1, optl, best.ss);
    compute(mid + 1, r, best.ss, optr);
}

int main()
{
    cin >> L >> G;

    C.resize(L);
    rep(i, L) cin >> C[i];

    acc.assign(L + 1, 0);
    rep(i, L) acc[i + 1] = acc[i] + C[i];

    last.assign(L, 1e17);
    now.resize(L);

    rep(_, G) { compute(0, L - 1, 0, L - 1); swap(last, now); }

    cout << last[L - 1] << '\n';
}