#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int N, K;
vector<ll> X, W, Wacc, XWacc;

ll cost(int i, int j)
{
    return X[j] * (Wacc[j] - (i ? Wacc[i - 1] : 0)) - 
           XWacc[j] + (i ? XWacc[i - 1] : 0);
}

vector<ll> last, now;

void compute(int l, int r, int optl, int optr)
{
    if (l > r) return;

    int mid = (l + r) / 2;
    pair<ll, int> best = {cost(0, mid), -1};

    repx(k, max(1, optl), min(mid, optr) + 1)
        best = min(best, {last[k - 1] + cost(k, mid), k});

    now[mid] = best.ff;

    compute(l, mid - 1, optl, best.ss);
    compute(mid + 1, r, best.ss, optr);
}

int main()
{
    while (cin >> N >> K)
    {
        X.resize(N), W.resize(N);
        rep(i, N) cin >> X[i] >> W[i];

        Wacc.assign(N, 0);
        rep(i, N) Wacc[i] = (i ? Wacc[i - 1] : 0) + W[i];

        XWacc.assign(N, 0);
        rep(i, N) XWacc[i] = (i ? XWacc[i - 1] : 0) + X[i] * W[i];

        last.assign(N, 1e17);
        now.resize(N);

        rep(_, K) { compute(0, N - 1, 0, N - 1); swap(last, now); }

        cout << last[N - 1] << '\n';
    }
}